#include "../headers/point.hpp"

int main() {
    geli::Point p1(1, 1);
    geli::Point p2(2, 2);

    std::cout << geli::Point::EuclideanDist(p1, p2);

    return 0;
}