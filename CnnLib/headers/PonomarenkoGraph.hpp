#ifndef PONOMARENKO_GRAPH_HPP
#define PONOMARENKO_GRAPH_HPP
#include "./graph.hpp"
#include <set>
#include <functional>

namespace geli {

    template<typename TObject, typename HashFunc>
    class PonomarenkoGraph;

    template<typename TObject, typename HashFunc>
    std::ostream& operator<<(std::ostream& out, const PonomarenkoGraph<TObject, HashFunc>& pgraph);

    template<typename TObject, typename HashFunc>
    class PonomarenkoGraph {
        Graph<TObject, HashFunc> graph;

        class ClosestToCompare {
            const TObject& base;
        public:
            ClosestToCompare(const TObject& base) : base(base) {};

            bool operator()(const TObject& p1, const TObject& p2) const { // TODO: rewrite in cpp
                double d1 = TObject::dist(p1, base);
                double d2 = TObject::dist(p2, base);
                if (d1 != d2) {
                    return TObject::dist(p1, base) < TObject::dist(p2, base);
                } else {
                    HashFunc hash;
                    return hash(p1) < hash(p2);
                }
            }
        };

        void multi_search(const TObject& target_node, 
                          std::set<TObject, ClosestToCompare>& res, 
                          std::size_t count) const;
    public:
        PonomarenkoGraph() = default;
        // PonomarenkoGraph(const std::vector<TObject>& objects);

        PonomarenkoGraph(const PonomarenkoGraph& pg) = delete;
        PonomarenkoGraph(PonomarenkoGraph&& pg) = delete;

        void add_node(const TObject& obj, std::size_t queries_count, std::size_t edges_limit);
        void load_nodes(const std::vector<TObject>& objects, std::size_t queries_count, std::size_t edges_limit);

        const TObject& greedy_search(const TObject& target_node, const TObject& start_node) const;
        TObject get_best_element(const TObject& target_node, std::size_t count) const;

        friend std::ostream& operator<< <>(std::ostream& out, const PonomarenkoGraph<TObject, HashFunc>& pgraph);

        ~PonomarenkoGraph() = default;
    };
}

#include "../source/PonomarenkoGraph.cpp"

#endif
