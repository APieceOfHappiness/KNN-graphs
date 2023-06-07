#ifndef PONOMARENKO_GRAPH
#define PONOMARENKO_GRAPH

#include "../headers/PonomarenkoGraph.hpp"

namespace geli {
    template<typename TObject, typename HashFunc>
    void PonomarenkoGraph<TObject, HashFunc>::add_node(const TObject& obj,
                                                       std::size_t queries_count,
                                                       std::size_t edges_limit) {
        std::set<TObject, ClosestToCompare> local_mins {ClosestToCompare(obj)};
        std::set<TObject, ClosestToCompare> res_mins {ClosestToCompare(obj)};
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
        }
    }

    template<typename TObject, typename HashFunc>
    std::ostream& operator<<(std::ostream& out, const PonomarenkoGraph<TObject, HashFunc>& pgraph) {
        out << "(Ponomarenko) " << pgraph.graph;
        return out;   
    }

    template<typename TObject, typename HashFunc>
    const TObject& PonomarenkoGraph<TObject, HashFunc>::greedy_search(const TObject& target_node, const TObject& start_node) const {
        if (!this->graph.consists_node(start_node)) {
            throw std::invalid_argument("nodes are not in the graph");
        }
        
        const TObject *cur_node = &start_node;
        const TObject *next_node = nullptr;
        double dmin = TObject::dist(*cur_node, target_node);
        for (auto &neighbour : this->graph.get_neighbours(*cur_node)) {
            if (TObject::dist(neighbour, target_node) < dmin) {
                dmin = TObject::dist(neighbour, target_node);
                next_node = &neighbour;
            }
        }
        if (next_node) {
            return this->greedy_search(target_node, *next_node);
        } else {
            return *cur_node;
        }
    }

    template<typename TObject, typename HashFunc>
    void PonomarenkoGraph<TObject, HashFunc>::multi_search(const TObject& target_node, 
                                                           std::set<TObject, ClosestToCompare>& res, 
                                                           std::size_t queries_count) const {
        if (!res.size()) {
            res.clear();
        }
        if (!this->graph.get_size()) {
            return;
        }
        for (std::size_t i = 0; i < queries_count; ++i) {
            const TObject& enter_node = this->graph.get_random_node();
            const TObject& local_min = this->greedy_search(target_node, enter_node);
            res.insert(local_min);
        }
    }

    template<typename TObject, typename HashFunc>
    TObject PonomarenkoGraph<TObject, HashFunc>::get_best_element(const TObject& target_node, 
                                                                  std::size_t queries_count) const {
        std::set<TObject, ClosestToCompare> res {ClosestToCompare(target_node)};
        this->multi_search(target_node, res, queries_count);
        return *res.begin();
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