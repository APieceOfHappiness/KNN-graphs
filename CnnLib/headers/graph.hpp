#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <time.h>


namespace geli { 

    template<typename TObject, typename HashFunc>
    class Graph;

    template<typename TObject, typename HashFunc>
    std::ostream& operator<<(std::ostream& out, const Graph<TObject, HashFunc>& graph);

    template<typename TObject, typename HashFunc>
    class Graph {
        std::unordered_map<TObject, std::vector<TObject>, HashFunc> graph;
        std::vector<TObject> nodes;
        size_t size;

    public:
        Graph() = default;
        Graph(const Graph& g) = delete;
        Graph(Graph&& g) = delete;

        void add_node(const TObject& p);
        void add_edge(const TObject& p1, const TObject& p2);
        void delete_edge(const TObject& p1, const TObject& p2);
        // void delete_node(const TObject& p); // unrecommended to use

        void clear();

        std::size_t get_size() const;

        const std::vector<TObject>& get_nodes() const;
        // const std::unordered_map<TObject, std::vector<TObject>, HashFunc>& get_edges() const;

        bool consists_node(const TObject& p) const;
        bool consists_edge(const TObject& p1, const TObject& p2) const;
    
        const std::vector<TObject>& get_neighbours(const TObject& p) const;

        const TObject& get_random_node() const;

        friend std::ostream& operator<< <>(std::ostream& out, const Graph& graph);

        ~Graph() = default;
    };
}

#include "../source/graph.cpp"

#endif

