#include <iostream>
#include <unordered_map>
#include <vector>
#include "./headers/graph.hpp"

int main() {
    geli::Graph<geli::Point, geli::HashPoint> graph;
    for (size_t i = 0; i < 10; ++i) {
        graph.add_node(geli::Point(i, i));
    }

    for (size_t i = 0; i < 10 - 1; ++i) {
        graph.add_edge(geli::Point(i, i), geli::Point(i + 1, i + 1));
    }
    graph.add_edge(geli::Point(9, 9), geli::Point(0, 0));

    std::cout << "(0, 0)?:" << graph.consists_node(geli::Point(0, 0)) << std::endl;
    std::cout << "(10, -10)?:" << graph.consists_node(geli::Point(10, -10)) << std::endl;

    std::cout << "(0, 0)-(1, 1)?:" << graph.consists_node(geli::Point(0, 0)) << std::endl;
    std::cout << "(0, 0)-(1, 2)?:" << graph.consists_node(geli::Point(10, -10)) << std::endl;

    std::cout << "neighbours of (0, 0):" << std::endl;
    for (auto neighbour : graph.get_neighbours(geli::Point(0, 0))) {;
        std::cout << neighbour << std::endl; 
    }
    std::cout << "size: " << graph.get_size() << std::endl; 
    
    try {
        graph.get_neighbours(geli::Point(-1, 1));
    } catch (std::invalid_argument& er) {
        std::cout << er.what() << std::endl;
    }

    std::cout << graph.get_random_node() << std::endl;
    std::cout << "d((0, 0), (1, 1)): " << geli::Point::dist(geli::Point(0, 0), geli::Point(1, 1)) << std::endl;
    
    std::cout << graph << std::endl;
    graph.clear();

    return 0;
}