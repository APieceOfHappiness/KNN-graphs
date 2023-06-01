#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <iostream>
#include <cmath>

namespace geli {
    class Point {
    public:
        double x;
        double y;

        Point() = default;
        Point(const Point& p) = default;
        Point(double x, double y);

        friend std::ostream& operator<<(std::ostream& out, const Point& p);

        bool operator==(const Point& p) const;

        static double dist(const Point& p1, const Point& p2);

        ~Point() = default;
    };

    struct HashPoint {
        std::size_t operator()(const Point& p) const;
    };

    
}

#endif