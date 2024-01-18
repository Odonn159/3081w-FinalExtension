#include "BatteryDecorator.h"

#include "Package.h"
#include "RechargeStation.h"
#include "SimulationModel.h"

BatteryDecorator::BatteryDecorator(Drone* drone, double charge)
    : drone(drone), charge(charge) {}

BatteryDecorator::~BatteryDecorator() {
  delete drone;

  if (toStation) {
    delete toStation;
  }

  if (toPackage) {
    delete toPackage;
  }
}

RechargeStation* BatteryDecorator::getNearestRechargeStation() {
  if (model->rechargeStations.size() == 0) {
    return nullptr;
  }

  RechargeStation* minStation = model->rechargeStations[0];

  double min =
      model->rechargeStations[0]->getPosition().dist(drone->getPosition());

  for (RechargeStation* station : model->rechargeStations) {
    double distance = station->getPosition().dist(drone->getPosition());

    if (distance < min) {
      min = distance;
      minStation = station;
    }
  }

  return minStation;
}

void BatteryDecorator::update(double dt) {
  // Every second that passes in the simulation is 1 tick of the battery, so we
  // set a decharge to be 1 unit of distance if moving
  charge -= drone->getSpeed() * dt;

  if (charge < 0) {
    return;
  }

  // This gets the minimum station
  RechargeStation* station = getNearestRechargeStation();
  double distanceFromStation =
      station->getPosition().dist(drone->getPosition());

  if (!station) {
    drone->update(dt);
    return;
  }

  station->chargeBattery(this, dt);

  // If we need to go to a station for recharging, there are 3 steps, traveling,
  // charging, and setting the return path.
  if (toStation) {
    // This is charging
    if (toStation->isCompleted() && charge < MAXCHARGE) {
      station->chargeBattery(this, dt);
    }

    // This is when the battery is full
    if (toStation->isCompleted() && charge >= MAXCHARGE) {
      delete toStation;
      toStation = nullptr;
      if (leftPackage) {
        toPackage = new BeelineStrategy(drone->getPosition(), packagePosition);
      }
    }
  }

  // If we are not charging or finished charging, we move to the station.
  if (toStation) {
    toStation->move(drone, dt);
    return;
  }

  if (distanceFromStation > charge - 100) {
    if (drone->getPackage()) {
      packagePosition = drone->getPosition();
      leftPackage = true;
    } else {
      leftPackage = false;
    }

    toStation =
        new BeelineStrategy(drone->getPosition(), station->getPosition());
  }

  if (toPackage && toPackage->isCompleted()) {
    delete toPackage;
    toPackage = nullptr;
  }

  if (toPackage) {
    toPackage->move(drone, dt);
    return;
  }

  // If the battery has no other tasks, we defer to the drone.
  drone->update(dt);
  return;
}

void BatteryDecorator::chargeBattery(double dt) {
  charge += 100 * dt;
  if (charge >= MAXCHARGE) {
    charge = MAXCHARGE;
  }
}

void BatteryDecorator::linkModel(SimulationModel* model) {
  this->model = model;
  drone->linkModel(model);
  return;
}

int BatteryDecorator::getId() const { return drone->getId(); }

Vector3 BatteryDecorator::getPosition() const { return drone->getPosition(); }

Vector3 BatteryDecorator::getDirection() const { return drone->getDirection(); }

const JsonObject& BatteryDecorator::getDetails() const {
  return drone->getDetails();
}

std::string BatteryDecorator::getColor() const { return drone->getColor(); }

std::string BatteryDecorator::getName() const { return drone->getName(); }

double BatteryDecorator::getSpeed() const { return drone->getSpeed(); }

void BatteryDecorator::setPosition(Vector3 pos_) { drone->setPosition(pos_); }

void BatteryDecorator::setDirection(Vector3 dir_) { drone->setDirection(dir_); }

void BatteryDecorator::setColor(std::string col_) { drone->setColor(col_); }

void BatteryDecorator::rotate(double angle) { drone->rotate(angle); }
