#ifndef GEOMETRY_COMPRESSOR_HPP
#define GEOMETRY_COMPRESSOR_HPP

#include "extractor/scripting_environment.hpp"
#include "util/node_based_graph.hpp"
#include "util/typedefs.hpp"

#include <unordered_set>
#include <vector>

namespace osrm::extractor
{

class CompressedEdgeContainer;
struct TurnRestriction;
struct UnresolvedManeuverOverride;

class GraphCompressor
{
  public:
    using EdgeData = util::NodeBasedDynamicGraph::EdgeData;

    void Compress(ScriptingEnvironment &scripting_environment,
                  std::vector<TurnRestriction> &turn_restrictions,
                  std::vector<UnresolvedManeuverOverride> &maneuver_overrides,
                  util::NodeBasedDynamicGraph &graph,
                  const std::vector<NodeBasedEdgeAnnotation> &node_data_container,
                  CompressedEdgeContainer &geometry_compressor);

  private:
    void PrintStatistics(unsigned original_number_of_nodes,
                         unsigned original_number_of_edges,
                         const util::NodeBasedDynamicGraph &graph) const;
};
} // namespace osrm::extractor

#endif
