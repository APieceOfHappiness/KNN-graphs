
#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
// #include "../headers/DynamicDistribution.hpp"
#include "../headers/KleinbergGraph.hpp"
#include "../headers/point.hpp"


int main() {

    geli::KleinbergGraph<geli::Point, geli::Point::HashPoint> graph;
    std::vector<geli::Point> points;
    for(size_t i = 0; i < 100000; ++i) {
        points.push_back(geli::Point(i, i));   
    }

    graph.load_nodes(points, 5);

    std::cout << graph << std::endl;

    return 0;
}