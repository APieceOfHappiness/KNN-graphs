#ifndef GRAPH_CPP
#define GRAPH_CPP

#include "../headers/graph.hpp"

namespace geli {
    template<typename TObject, typename HashFunc>
    void Graph<TObject, HashFunc>::add_node(const TObject& p) {
        if (this->consists_node(p)) {
            throw std::invalid_argument("node already exists");
        }
        this->size++;
        this->graph[p];
        this->nodes.push_back(p);
    }
    
    template<typename TObject, typename HashFunc>
    void Graph<TObject, HashFunc>::delete_edge(const TObject& p1, const TObject& p2) {
        this->graph[p1].erase(p2);
        this->graph[p2].erase(p1);
    }

    // template<typename TObject, typename HashFunc> 
    // void Graph<TObject, HashFunc>::delete_node(const TObject& p) {
    //     std::cerr << "Warning: delete_node method is too slow" << std::endl;
    //     for (auto neighbour : this->get_neighbours(p)) {
    //         this->delete_edge(p, neighbour);
    //     }
    // } // unrecommended to use

    template<typename TObject, typename HashFunc>
    std::size_t Graph<TObject, HashFunc>::get_size() const {
        return this->size;
    }

    template<typename TObject, typename HashFunc>
    bool Graph<TObject, HashFunc>::consists_node(const TObject& p) const {
        return this->graph.count(p);
    }

    template<typename TObject, typename HashFunc>
    const std::vector<TObject>& Graph<TObject, HashFunc>::get_neighbours(const TObject& p) const {
        if (this->consists_node(p)) {
            return this->graph.at(p);
        } else {
            throw std::invalid_argument("this node does not exists");
        }
    }

    template<typename TObject, typename HashFunc>
    bool Graph<TObject, HashFunc>::consists_edge(const TObject& p1, const TObject& p2) const {
        if (this->consists_node(p1)) {
            for (auto &neighbour : this->get_neighbours(p1)) {
                if (neighbour == p2) {
                    return true;
                }
            }
        }   
        return false;
    }

    template<typename TObject, typename HashFunc>
    void Graph<TObject, HashFunc>::add_edge(const TObject& p1, const TObject& p2) {
        if (!this->consists_node(p1)) {
            this->add_node(p1);
        }
        if (!this->consists_node(p2)) {
            this->add_node(p2);
        }
        this->graph[p1].push_back(p2);
        this->graph[p2].push_back(p1);
    }

    template<typename TObject, typename HashFunc>
    void Graph<TObject, HashFunc>::clear() {
        this->graph.clear();
        this->nodes.clear();
        this->size = 0;
    }

    template<typename TObject, typename HashFunc>
    const TObject& Graph<TObject, HashFunc>::get_random_node() const {
        if (!this->get_size()) {
            throw std::runtime_error("the graph is empty");
        }
        std::random_device device;
        std::mt19937 rng(device());
        std::uniform_int_distribution<int> range(0, this->get_size() - 1); 

        return this->nodes[range(rng)];
    }

    template<typename TObject, typename HashFunc>
    std::ostream& operator<<(std::ostream& out, const Graph<TObject, HashFunc>& graph) {
        out << "graph {" << std::endl;
        for (auto &node : graph.nodes) {
            out << "\t" << node << " -> ";
            for (auto &neighbour : graph.get_neighbours(node)) {
                out << neighbour << " ";
            }
            out << std::endl;
        }
        out << "}";
        return out;
    }
}

#endif