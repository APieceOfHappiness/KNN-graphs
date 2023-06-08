#ifndef NSWG_CPP
#define NSWG_CPP

#include "../headers/Nswg.hpp"

namespace geli {
    
    template<typename TObject, typename HashFunc>
    bool Nswg<TObject, HashFunc>::ClosestToCompare::operator()(const TObject& p1, const TObject& p2) const {
        double d1 = TObject::dist(p1, base);
        double d2 = TObject::dist(p2, base);
        if (d1 != d2) {
            return TObject::dist(p1, base) < TObject::dist(p2, base);
        } else {
            HashFunc hash;
            return hash(p1) < hash(p2);
        }
    }

    template<typename TObject, typename HashFunc>
    const std::vector<TObject>& Nswg<TObject, HashFunc>::get_nodes() const {
        return this->graph.get_nodes();
    }

    // template<typename TObject, typename HashFunc>
    // const std::unordered_map<TObject, std::vector<TObject>, HashFunc>& Nswg<TObject, HashFunc>::get_edges() const {
    //     return this->graph.get_edges();
    // }

    template<typename TObject, typename HashFunc>
    const TObject& Nswg<TObject, HashFunc>::greedy_search(const TObject& target_node, const TObject& start_node) const {
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
    void Nswg<TObject, HashFunc>::multi_search(const TObject& target_node, 
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
    TObject Nswg<TObject, HashFunc>::get_best_element(const TObject& target_node, 
                                                      std::size_t queries_count) const {
        std::set<TObject, ClosestToCompare> res {ClosestToCompare(target_node)};
        this->multi_search(target_node, res, queries_count);
        return *res.begin();
    }

    template<typename TObject, typename HashFunc>
    const std::vector<TObject>& Nswg<TObject, HashFunc>::get_neighbours(const TObject& p) const {
        return this->graph.get_neighbours(p);
    }

    template<typename TObject, typename HashFunc>
    const TObject& Nswg<TObject, HashFunc>::get_random_node() const {
        return this->graph.get_random_node();
    }

    template<typename TObject, typename HashFunc>
    void Nswg<TObject, HashFunc>::clear() {
        this->graph.clear();
    }

    template<typename TObject, typename HashFunc>
    std::size_t Nswg<TObject, HashFunc>::get_size() const {
        return this->graph.get_size();
    }

    template<typename TObject, typename HashFunc>
    double Nswg<TObject, HashFunc>::get_mean_deg() const {
        return static_cast<double>(this->sum_of_degrees) / this->get_size();
    }
}

#endif