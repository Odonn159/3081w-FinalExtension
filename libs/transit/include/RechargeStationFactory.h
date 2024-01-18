#include "IEntityFactory.h"
#include "RechargeStation.h"

/**
 * @brief This class inherits from IEntityFactory, and serves as a factory for
 * the recharge stations. This factory is added to the composite factory, and is
 * used to create various recharge stations within the simulation.
 */
class RechargeStationFactory : public IEntityFactory {
 public:
  /**
   * @brief Destructor for Recharge stationFactory
   */
  virtual ~RechargeStationFactory() {}
  /**
   * @brief Construct a new RechargeStation object
   * @param entity Contains the JsonObject information in order to create a
   * recharge factory.
   * @return RechargeStation Entity.
   */
  IEntity* CreateEntity(JsonObject& entity);
};
