#include <iostream>
#include <vector>
#include <map>
#include "../headers/Figure.hpp"
#include "../headers/PonomarenkoGraph.hpp"
#include "../headers/point.hpp"

double get_random_range(int min, int max) {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_real_distribution<double> distr(min, max);
    return distr(generator);
}

int main() {
    std::map<double, int> m;
    m[0] = 1;
    m[1] = 2;
    m[3] = 4;

    std::vector<double> x;
    std::vector<double> y;

    // for (double i = 0; i < 10; ++i) {
    //     x.push_back(i);
    //     x.push_back(i + 1);
    //     x.push_back(geli::graphic_object::Nan);

    //     y.push_back(2 * i);
    //     y.push_back(2 * i + 1);
    //     y.push_back(geli::graphic_object::Nan);
    // } 

    // for (double i = 0; i < 10; ++i) {
    //     x.push_back(i);
    //     x.push_back(i + 1);
    //     x.push_back(geli::graphic_object::Nan);

    //     y.push_back(2 * i);
    //     y.push_back(2 * i + 1);
    //     y.push_back(geli::graphic_object::Nan);
    // } 

    geli::PonomarenkoGraph<geli::Point, geli::Point::HashPoint> pgraph;
    for (std::size_t i = 0; i < 100000; ++i) {
        if (i % 10000 == 0) {
            std::cout << i << std::endl;
        }
        try {
            pgraph.add_node(geli::Point(get_random_range(1, 100), get_random_range(1, 100)), 5, 3);
        } catch (std::invalid_argument & er) {
            std::cout << er.what() << std::endl;
        };
    }

    geli::graphic_object::Figure fig("plot1");
    fig.add_markers_and_lines(x, y, 5, 2, "red", "blue", "smth1");
    fig.add_graph(pgraph, 5, 2, "red", "blue", "smth1");
    fig.update_title("MEGA GRAPH");
    fig.update_xaxes("X axis", "linear");
    fig.update_yaxes("Y axis", "linear");
    fig.show();

    return 0;
}