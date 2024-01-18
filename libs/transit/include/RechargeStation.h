#ifndef RECHARGE_STATION_H
#define RECHARGE_STATION_H

#include <vector>

#include "IEntity.h"
#include "math/vector3.h"
#include "util/json.h"

class BatteryDecorator;

/**
 * @brief Represents a recharging station in a physical system.
 * Used to recharge Battery Drone decorators.
 */
class RechargeStation : public IEntity {
 public:
  /**
   * @brief Constructor
   * @param obj JSON object containing the robot's information
   */
  RechargeStation(JsonObject& obj);

  /**
   * @brief Updates the RechargeStation
   * @param dt difference in time since last update
   * @return void
   */
  void update(double dt) {}

  /**
   * @brief Charges the drone if there is one within 1 unit.
   * @param battery The drone decorator that needs to be recharged
   * @param dt change in time
   * @return void
   */
  void chargeBattery(BatteryDecorator* battery, double dt);
};

#endif  // RECHARGE_STATION_H
