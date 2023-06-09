#ifndef NSWG_HPP
#define NSWG_HPP

#include "./graph.hpp"
// #include "./Figure.hpp"
#include <set>
#include <functional>

namespace geli {

    template<typename TObject, typename HashFunc>
    class Nswg {
    protected:
        Graph<TObject, HashFunc> graph;
        std::size_t sum_of_degrees = 0;

        class ClosestToCompare {
            const TObject& base;
        public:
            ClosestToCompare(const TObject& base) : base(base) {};
            bool operator()(const TObject& p1, const TObject& p2) const;
        };

        void multi_search(const TObject& target_node, 
                          std::set<TObject, ClosestToCompare>& res, 
                          std::size_t count) const;
    
    public:
        virtual void load_nodes(const std::vector<TObject>& objects) = 0;
        double get_mean_deg() const;
        double get_cc() const;

        const std::vector<TObject>& get_nodes() const;

        const TObject& greedy_search(const TObject& target_node, const TObject& start_node) const;
        std::pair<TObject, double> get_best_element(const TObject& target_node, std::size_t count) const;

        const std::vector<TObject>& get_neighbours(const TObject& p) const;
        const TObject& get_random_node() const;
        void clear();
        std::size_t get_size() const;
    };
}

#include "../source/Nswg.cpp"

#endif