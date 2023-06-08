#ifndef KLEINBERG_GRAPH_CPP
#define KLEINBERG_GRAPH_CPP

#include "../headers/KleinbergGraph.hpp"

namespace geli {
    template<typename TObject, typename HashFunc>
    void KleinbergGraph<TObject, HashFunc>::load_nodes(const std::vector<TObject>& nodes, size_t mean_neighbous_cnt) {
        for(auto &node1 : nodes) {
            this->graph.add_node(node1);
        }
        
        DynamicDistribution distribution;
        for(auto &node1 : nodes) {
            distribution.clear();
            for (auto &node2 : nodes) {
                if (node1 == node2) {
                    distribution.push_back(0);
                    continue;
                }
                double dist = TObject::dist(node1, node2);
                distribution.push_back(1 / (dist * dist));
            }

            for (size_t i = 0; i < mean_neighbous_cnt / 2 + 1; ++i) {
                size_t random_idx = distribution.get_random_index();
                if (!this->graph.consists_edge(node1, nodes[random_idx])) {
                    this->graph.add_edge(node1, nodes[random_idx]);
                    this->sum_of_degrees += 2;
                }
            }
        }


    }

    template<typename TObject, typename HashFunc>
    std::ostream& operator<<(std::ostream& out, const KleinbergGraph<TObject, HashFunc>& kg) {
        out << kg.graph;
        return out;
    }
}

#endif