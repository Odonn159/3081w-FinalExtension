#ifndef Helicopter_FACTORY_H_
#define Helicopter_FACTORY_H_

#include <vector>

#include "Helicopter.h"
#include "IEntityFactory.h"

/**
 *@brief Helicopter Factory to produce Helicopter class.
 **/
class HelicopterFactory : public IEntityFactory {
 public:
  /**
   * @brief Destructor for HelicopterFactory class.
   **/
  virtual ~HelicopterFactory() {}

  /**
   * @brief Creates a helicopter using the given JSON object, if possible.
   * @param entity - JsonObject to be used to create the new entity.
   * @return Entity that was created if it was created successfully, or a
   * null pointer if creation failed.
   **/
  IEntity* CreateEntity(JsonObject& entity);
};

#endif
