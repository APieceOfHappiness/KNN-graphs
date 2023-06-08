
#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <unordered_set>
// #include "../headers/DynamicDistribution.hpp"
#include "../headers/KleinbergGraph.hpp"
#include "../headers/point.hpp"


int main() {


    // std::unordered_set<std::pair<geli::Point, geli::Point>, geli::Point::HashPoint> s;
    // s.insert(std::make_pair(geli::Point(2, 2), geli::Point(1, 1)));
    geli::KleinbergGraph<geli::Point, geli::Point::HashPoint> graph;
    std::vector<geli::Point> points;
    for(size_t i = 0; i < 10; ++i) {
        points.push_back(geli::Point(i, i));   
    }

    graph.load_nodes(points, 5);
    // graph.get_nodes();
    for (const geli::Point &el : graph.get_nodes()) {
        std::cout << el;
    }
    std::cout << std::endl;

    std::cout << graph << std::endl;

    return 0;
}