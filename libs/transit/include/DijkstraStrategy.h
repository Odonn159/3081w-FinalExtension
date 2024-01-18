#ifndef DIJKSTRA_STRATEGY_H_
#define DIJKSTRA_STRATEGY_H_

#include "PathStrategy.h"
#include "graph.h"

/**
 * @brief this class inherits from the PathStrategy class and is responsible for
 * generating the Dijkstra path that the drone will take.
 */
class DijkstraStrategy : public PathStrategy {
 public:
  /**
   * @brief Construct a new Dijkstra Strategy object
   *
   * @param position Current position
   * @param destination End destination
   * @param graph Graph/Nodes of the map
   */
  DijkstraStrategy(Vector3 position, Vector3 destination,
                   const routing::IGraph* graph);
};
#endif  // DIJKSTRA_STRATEGY_H_
