#include <iostream>
#include <vector>
#include <map>
#include "../headers/Figure.hpp"
#include "../headers/PonomarenkoGraph.hpp"
#include "../headers/point.hpp"

int main() {
    std::map<double, int> m;
    m[0] = 1;
    m[1] = 2;
    m[3] = 4;

    std::vector<double> x;
    std::vector<double> y;

    for (double i = 0; i < 10; ++i) {
        x.push_back(i);
        x.push_back(i + 1);
        x.push_back(geli::graphic_object::Nan);

        y.push_back(2 * i);
        y.push_back(2 * i + 1);
        y.push_back(geli::graphic_object::Nan);
    } 

    for (double i = 0; i < 10; ++i) {
        x.push_back(i);
        x.push_back(i + 1);
        x.push_back(geli::graphic_object::Nan);

        y.push_back(2 * i);
        y.push_back(2 * i + 1);
        y.push_back(geli::graphic_object::Nan);
    } 

    geli::graphic_object::Figure fig("plot1");
    fig.add_markers_and_lines(x, y, 5, 2, "red", "blue", "smth1");
    fig.update_title("MEGA GRAPH");
    fig.update_xaxes("X axis", "linear");
    fig.update_yaxes("Y axis", "log");
    fig.show();

    return 0;
}