#include <iostream>
#include <vector>
#include <map>
#include "../headers/Figure.hpp"
#include "../headers/PonomarenkoGraph.hpp"
#include "../headers/KleinbergGraph.hpp"
#include "../headers/RandomGraph.hpp"
#include "../headers/point.hpp"

double rrange(int min, int max) {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_real_distribution<double> distr(min, max);
    return distr(generator);
}

int main() {
    geli::PonomarenkoGraph<geli::Point, geli::Point::HashPoint> pgraph;
    geli::KleinbergGraph<geli::Point, geli::Point::HashPoint> kgraph;
    geli::RandomGraph<geli::Point, geli::Point::HashPoint> rgraph;

    std::vector<geli::Point> points;

    for (size_t i = 0; i < 1000; ++i) {
        points.push_back(geli::Point(rrange(0, 100), rrange(0, 100)));
    }   

    pgraph.load_nodes(points, 10, 4);
    kgraph.load_nodes(points, 4);
    rgraph.load_nodes(points);

    std::cout << pgraph.get_mean_deg() << std::endl;
    std::cout << kgraph.get_mean_deg() << std::endl;
    std::cout << rgraph.get_mean_deg() << std::endl;

    return 0;
}