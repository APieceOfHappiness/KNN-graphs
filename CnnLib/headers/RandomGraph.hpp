#ifndef RANDOM_GRAPH_HPP
#define RANDOM_GRAPH_HPP

#include <iostream>
#include <vector>
#include "./Nswg.hpp"


namespace geli {

    template<typename TObject, typename HashFunc>
    class RandomGraph : public Nswg<TObject, HashFunc> {
        double p;
        double mean_deg;
    public:
        RandomGraph(double p = 0.5, double mean_deg = 5);
        RandomGraph(const RandomGraph& rg) = delete;
        RandomGraph(RandomGraph&& rg) = delete;

        void load_nodes(const std::vector<TObject>& objects);

        ~RandomGraph() = default;
    };
}

#include "../source/RandomGraph.cpp"

#endif