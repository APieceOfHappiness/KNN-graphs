#ifndef RANDOM_GRAPH_HPP
#define RANDOM_GRAPH_HPP

#include <iostream>
#include <vector>
#include "./Nswg.hpp"


namespace geli {

    template<typename TObject, typename HashFunc>
    class RandomGraph : public Nswg<TObject, HashFunc> {
        double mean_neighbours;
    public:
        RandomGraph(double mean_neighbours);
        RandomGraph(const RandomGraph& rg) = delete;
        RandomGraph(RandomGraph&& rg) = delete;

        void load_nodes(const std::vector<TObject>& objects) override;

        ~RandomGraph() = default;
    };
}

#include "../source/RandomGraph.cpp"

#endif