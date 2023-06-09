#ifndef KLEINBERG_GRAPH_CPP
#define KLEINBERG_GRAPH_CPP

#include "../headers/KleinbergGraph.hpp"

namespace geli {

    template<typename TObject, typename HashFunc>
    KleinbergGraph<TObject, HashFunc>::KleinbergGraph(std::size_t short_paths, std::size_t long_paths) {
        this->short_paths = short_paths;
        this->long_paths = long_paths;
    }

    template<typename TObject, typename HashFunc>
    void KleinbergGraph<TObject, HashFunc>::load_nodes(const std::vector<TObject>& nodes) {
        for(auto &node1 : nodes) {
            this->graph.add_node(node1);
        }
        
        HashFunc hash;
        DynamicDistribution distribution;
        for(auto &node1 : nodes) {
            distribution.clear();
            for (auto &node2 : nodes) {
                double dist = TObject::dist(node1, node2);
                if (node1 == node2) {
                    distribution.push_back(0);
                    continue;
                }
                
                if (dist <= this->short_paths) {
                    if (!this->graph.consists_edge(node1, node2)) {
                        this->graph.add_edge(node1, node2);
                        this->sum_of_degrees += 2;
                    }
                } else {
                    distribution.push_back(1 / (dist * dist));
                }
            }

            const size_t attempts_to_find_unique = 10;
            for(size_t path_idx = 0; path_idx < this->long_paths; ++path_idx) {
                for (size_t i = 0; i < attempts_to_find_unique; ++i) {
                    size_t random_idx = distribution.get_random_index();
                    if (!this->graph.consists_edge(node1, nodes[random_idx])) {
                        this->graph.add_edge(node1, nodes[random_idx]);
                        this->sum_of_degrees += 2;
                        break;
                    }
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