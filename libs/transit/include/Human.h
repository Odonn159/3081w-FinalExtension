#ifndef HUMAN_H_
#define HUMAN_H_

#include "IEntity.h"
#include "IStrategy.h"
/**
 * @brief Not to be confused with robots, humans are tiny models that run around
 * on the map. They do not interact with drones robots or packages. They can be
 * added to the simulation on the schedule page.
 */
class Human : public IEntity {
 public:
  /**
   * @brief Humans are created with a name
   * @param obj JSON object containing the humans's information
   */
  Human(JsonObject& obj);

  /**
   * @brief Destroys the Human object
   */
  ~Human();

  /**
   * @brief Updates the humans's position
   * @param dt Delta time
   */
  void update(double dt);

 private:
  IStrategy* movement = nullptr;
};

#endif
