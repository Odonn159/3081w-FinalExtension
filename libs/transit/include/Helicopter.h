#ifndef Helicopter_H_
#define Helicopter_H_

#include "IEntity.h"
#include "IStrategy.h"
/**
 * @brief Helicopter's are just created to look nice and demonstrate knowledge
 * of models. They serve no purpose in the simulation. They choose to move from
 * any location to another in a straight line (targets chosen randomly).
 */
class Helicopter : public IEntity {
 public:
  /**
   * @brief Helicopter are created with a name
   * @param obj JSON object containing the drone's information
   */
  Helicopter(JsonObject& obj);

  ~Helicopter();
  /**
   * @brief Update's the helicopter location based on the change in time (Uses
   * the underlying strategy)
   * @param dt
   */
  void update(double dt);

 private:
  IStrategy* movement = nullptr;
};

#endif
