#include <iostream>
#include <unordered_map>
#include <vector>
#include <functional>
// #include "../headers/graph.hpp"
#include "../headers/point.hpp"
#include "../headers/PonomarenkoGraph.hpp"

int main() {
    geli::Point start(0, 0);
    geli::Point target(5.5, 5.5);
    geli::PonomarenkoGraph<geli::Point, geli::Point::HashPoint, geli::Point::EuclideanDist> pgraph;
    for (std::size_t i = 0; i < 10; ++i) {
        pgraph.add_node(geli::Point(i, i), 5, 3);
    }
    std::cout << pgraph << std::endl;
    std::cout << pgraph.get_best_element(target, 10) << std::endl;

    //------------------------------------------------------------------

    // geli::Point3D start(0, 0, 0);
    // geli::Point3D target(5.5, 5.5, 5.5);
    // std::cout << start << std::endl;
    // geli::PonomarenkoGraph<geli::Point3D, geli::Point3D::HashPoint> pgraph;
    // for (std::size_t i = 0; i < 10; ++i) {
    //     pgraph.add_node(geli::Point3D(i, i, i), 5, 3);
    // }
    // std::cout << pgraph << std::endl;
    // std::cout << pgraph.get_best_element(target, 10) << std::endl;

    return 0;
}