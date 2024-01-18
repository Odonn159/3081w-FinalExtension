#ifndef BATTERY_DECORATOR_H_
#define BATTERY_DECORATOR_H_

#include "BeelineStrategy.h"
#include "Drone.h"
#include "IEntity.h"

class RechargeStation;
/**
 * @brief This class inherits from IEntity, and serves as a decorator (wrapper)
 * for the drone. This wrapper adds information regarding the drone's current
 * charge level, and logic to determine charge loss and movement.
 */
class BatteryDecorator : public IEntity {
 public:
  /**
   * @brief Construct a new Battery Decorator object
   *
   * @param drone Drone to be decorated
   * @param charge How much charge the drone starts with (Max: 5000)
   * @return BatteryDecorator object
   */
  BatteryDecorator(Drone* drone, double charge);

  /**
   * @brief Destroy the Recharge Decorator object
   */
  ~BatteryDecorator();
  /**
   * @brief Finds the nearest recharge station to a given Battery-Powered Drone
   * @return RechargeStation* object
   */
  RechargeStation* getNearestRechargeStation();
  /**
   * @brief Updates the Drone based on Drone's update, as well as modify Battery
   * charge accordingly.
   * @param dt How much time has passed since the last call to update
   * @return void
   */
  void update(double dt);
  /**
   * @brief Recharges the Drone Battery when in the appropriate location
   * @param dt How much charge the drone starts with (Max: 5000)
   * @return void
   */
  void chargeBattery(double dt);

  /**
   * @brief Defers to Drone's implementation.
   *
   *  @param[in] model The simulation model to link.
   */
  void linkModel(SimulationModel* model);

  /**
   * @brief Defers to Drone's implementation.
   *
   * @return The ID of the entity.
   */
  int getId() const;

  /**
   * @brief Defers to Drone's implementation.
   *
   * @return The position of the entity.
   */
  Vector3 getPosition() const;

  /**
   * @brief Defers to Drone's implementation.
   *
   * @return The direction of the entity.
   */
  Vector3 getDirection() const;

  /**
   * @brief Defers to Drone's implementation.
   *
   * @return const JsonObject&
   */
  const JsonObject& getDetails() const;

  /**
   * @brief Defers to Drone's implementation.
   *
   * @return The color of the entity
   */
  std::string getColor() const;

  /**
   * @brief Defers to Drone's implementation.
   *
   * @return The name of the entity
   */
  std::string getName() const;

  /**
   * @brief Defers to Drone's implementation.
   *
   * @return The speed of the entity.
   */
  double getSpeed() const;

  /**
   * @brief Defers to Drone's implementation.
   *
   * @param pos_ The desired position of the entity.
   */
  void setPosition(Vector3 pos_);

  /**
   *@brief Defers to Drone's implementation.

   *@param dir_ The new direction of the entity.
   */
  void setDirection(Vector3 dir_);

  /**
   * @brief Defers to Drone's implementation.
   *
   * @param col_ The new color of the entity
   */
  void setColor(std::string col_);

  /**
   * @brief Defers to Drone's implementation.
   *
   * @param angle The angle to rotate the entity by.
   */
  void rotate(double angle);

 private:
  const double MAXCHARGE = 5000;

  bool leftPackage = false;
  double charge;
  Drone* drone;
  IStrategy* toStation = nullptr;
  IStrategy* toPackage = nullptr;
  Vector3 packagePosition;
};

#endif  // BATTERY_DECORATOR_H_
