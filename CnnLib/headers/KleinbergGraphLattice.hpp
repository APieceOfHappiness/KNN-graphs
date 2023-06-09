#ifndef KLEINBERG_GRAPH_HPP
#define KLEINBERG_GRAPH_HPP

#include <iostream>
#include <random>
#include "./graph.hpp"
#include "./Nswg.hpp"
#include "./DynamicDistribution.hpp"

namespace geli {

    template<typename TObject, typename HashFunc>
    class KleinbergGraph;

    template<typename TObject, typename HashFunc>
    std::ostream& operator<<(std::ostream& out, const KleinbergGraph<TObject, HashFunc>& kg);

    template<typename TObject, typename HashFunc>
    class KleinbergGraph : public Nswg<TObject, HashFunc>{
        size_t mean_neighbours;
    public:
        KleinbergGraph(size_t mean_neighbours = 10);
        KleinbergGraph(const KleinbergGraph& kg) = delete;
        KleinbergGraph(KleinbergGraph&& kg) = delete;

        void load_nodes(const std::vector<TObject>& nodes) override;

        friend std::ostream& operator<< <>(std::ostream& out, const KleinbergGraph& kg);

        ~KleinbergGraph() = default;
    };
}

#include "../source/KleinbergGraph.cpp"

#endif