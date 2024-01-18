#include "RechargeStation.h"

#include "BatteryDecorator.h"

RechargeStation::RechargeStation(JsonObject& obj) : IEntity(obj) {}

void RechargeStation::chargeBattery(BatteryDecorator* battery, double dt) {
  if (battery->getPosition().dist(getPosition()) < 5) {
    battery->chargeBattery(dt);
  }

  return;
}
