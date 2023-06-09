#ifndef RANDOM_GRAPH_CPP
#define RANDOM_GRAPH_CPP

#include "../headers/RandomGraph.hpp"

namespace geli {

    template<typename TObject, typename HashFunc>
    RandomGraph<TObject, HashFunc>::RandomGraph(double mean_neighbours) {
        this->mean_neighbours = mean_neighbours;
    }

    template<typename TObject, typename HashFunc>
    void RandomGraph<TObject, HashFunc>::load_nodes(const std::vector<TObject>& objects) {
        for (auto &el : objects) {
            this->graph.add_node(el);
        }

        double p = this->mean_neighbours / this->get_size();

        std::random_device rd;
        std::mt19937 generator(rd());
        std::uniform_real_distribution<double> distribution(0, 1);
        std::size_t nodes_cnt = objects.size();
        for (std::size_t i = 0; i < nodes_cnt - 1; ++i) {
            for (std::size_t j = i + 1; j < nodes_cnt; ++j) {
                if (distribution(generator) < p) {
                    this->graph.add_edge(objects[i], objects[j]);
                    this->sum_of_degrees += 2;
                }
            }
        }
    }
}

#endif