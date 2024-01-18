#include "DroneFactory.h"

#include "BatteryDecorator.h"

IEntity* DroneFactory::CreateEntity(JsonObject& entity) {
  std::string type = entity["type"];
  if (type.compare("drone") == 0) {
    std::cout << "Drone Created" << std::endl;
    return new BatteryDecorator(new Drone(entity), 5000.0);
  }
  return nullptr;
}
