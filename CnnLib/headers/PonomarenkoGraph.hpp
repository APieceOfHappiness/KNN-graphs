#ifndef PONOMARENKO_GRAPH_HPP
#define PONOMARENKO_GRAPH_HPP
#include "./graph.hpp"
#include "./Nswg.hpp"
#include <set>
#include <functional>

namespace geli {

    template<typename TObject, typename HashFunc>
    class PonomarenkoGraph;

    template<typename TObject, typename HashFunc>
    std::ostream& operator<<(std::ostream& out, const PonomarenkoGraph<TObject, HashFunc>& pgraph);

    template<typename TObject, typename HashFunc>
    class PonomarenkoGraph : public Nswg<TObject, HashFunc> {
        std::size_t queries_count = 5;
        std::size_t edges_count = 7;
    public:
        PonomarenkoGraph(std::size_t queries_count = 5, std::size_t edges_count = 7);
        // PonomarenkoGraph(const std::vector<TObject>& objects);

        PonomarenkoGraph(const PonomarenkoGraph& pg) = delete;
        PonomarenkoGraph(PonomarenkoGraph&& pg) = delete;

        void add_node(const TObject& obj);
        void load_nodes(const std::vector<TObject>& objects) override;

        friend std::ostream& operator<< <>(std::ostream& out, const PonomarenkoGraph<TObject, HashFunc>& pgraph);

        ~PonomarenkoGraph() = default;
    };
}

#include "../source/PonomarenkoGraph.cpp"

#endif
