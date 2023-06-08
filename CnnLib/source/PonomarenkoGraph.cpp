#ifndef PONOMARENKO_GRAPH
#define PONOMARENKO_GRAPH

#include "../headers/PonomarenkoGraph.hpp"

namespace geli {
    template<typename TObject, typename HashFunc>
    void PonomarenkoGraph<TObject, HashFunc>::add_node(const TObject& obj,
                                                       std::size_t queries_count,
                                                       std::size_t edges_limit) {
        std::set<TObject, typename Nswg<TObject, HashFunc>::ClosestToCompare> local_mins {typename Nswg<TObject, HashFunc>::ClosestToCompare(obj)};
        std::set<TObject, typename Nswg<TObject, HashFunc>::ClosestToCompare> res_mins {typename Nswg<TObject, HashFunc>::ClosestToCompare(obj)};
        this->graph.add_node(obj);
        this->multi_search(obj, local_mins, queries_count); // TODO: dynamic cnt
        for (auto &local_min : local_mins) {
            if (local_min == obj) {
                continue;
            }
            res_mins.insert(local_min);
            for (auto &neighbour : this->graph.get_neighbours(local_min)) {
                if (neighbour == local_min) {
                    continue;
                }
                res_mins.insert(neighbour);
            }
        }

        for (auto min : res_mins) {
            if (!edges_limit--) {
                return;
            }
            this->graph.add_edge(min, obj);
            this->sum_of_degrees += 2;
        }
    }

    template<typename TObject, typename HashFunc>
    std::ostream& operator<<(std::ostream& out, const PonomarenkoGraph<TObject, HashFunc>& pgraph) {
        out << "(Ponomarenko) " << pgraph.graph;
        return out;   
    }

    template<typename TObject, typename HashFunc>
    void PonomarenkoGraph<TObject, HashFunc>::load_nodes(const std::vector<TObject>& objects,
                                                         std::size_t queries_count,
                                                         std::size_t edges_limit) {
        for(size_t i = 0; i < objects.size(); ++i) {
            this->add_node(objects[i], queries_count, edges_limit);
        }
    }
}

#endif