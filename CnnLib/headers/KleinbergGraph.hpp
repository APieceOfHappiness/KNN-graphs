#ifndef KLEINBERG_GRAPH_HPP
#define KLEINBERG_GRAPH_HPP

#include <iostream>
#include <random>
#include "./graph.hpp"
#include "./DynamicDistribution.hpp"

namespace geli {

    template<typename TObject, typename HashFunc>
    class KleinbergGraph;

    template<typename TObject, typename HashFunc>
    std::ostream& operator<<(std::ostream& out, const KleinbergGraph<TObject, HashFunc>& kg);

    template<typename TObject, typename HashFunc>
    class KleinbergGraph {
        Graph<TObject, HashFunc> graph;
    
    public:
        KleinbergGraph() = default;
        KleinbergGraph(const KleinbergGraph& kg) = delete;
        KleinbergGraph(KleinbergGraph&& kg) = delete;

        void load_nodes(const std::vector<TObject>& nodes, size_t max_neighbous);

        friend std::ostream& operator<< <>(std::ostream& out, const KleinbergGraph& kg);

        ~KleinbergGraph() = default;
    };
}

#include "../source/KleinbergGraph.cpp"

#endif