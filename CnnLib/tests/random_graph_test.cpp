#include <iostream>
#include <unordered_map>
#include <vector>
#include <functional>
#include "../headers/point.hpp"
#include "../headers/RandomGraph.hpp"
#include "../headers/Figure.hpp"

double get_random_range(int min, int max) {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_real_distribution<double> distr(min, max);
    return distr(generator);
}

int main() {
    geli::RandomGraph<geli::Point, geli::Point::HashPoint> graph(0.03, 5);

    std::vector<geli::Point> points;
    for (std::size_t i = 0; i < 100; ++i) {
        try {
            points.push_back(geli::Point(get_random_range(1, 100), get_random_range(1, 100)));
        } catch (std::invalid_argument & er) {
            std::cout << er.what() << std::endl;
        };
    }

    graph.load_nodes(points);

    geli::graphic_object::Figure fig("RandomGraph");
    fig.add_graph(graph, 10, 3, "red", "blue", "RandomGraph");
    fig.update_title("MEGA GRAPH");
    fig.update_xaxes("X axis", "linear");
    fig.update_yaxes("Y axis", "linear");
    fig.show();


    return 0;
}