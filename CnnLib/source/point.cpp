#include "../headers/point.hpp"



namespace geli {
    Point::Point(double x, double y) {
        this->x = x;
        this->y = y;
    }

    bool Point::operator==(const Point& p) const {
        return (p.x == this->x) && (p.y == this->y); 
    }

    std::size_t HashPoint::operator()(const Point& p) const {
        std::hash<double> hash_function;
        std::size_t seed_val = hash_function(p.x);
        seed_val ^= hash_function(p.y) + 0x9e3779b9 + (seed_val << 6) + (seed_val >> 2);
        return seed_val;
        
    }

    std::ostream& operator<<(std::ostream& out, const Point& p) {
        out << "(" << p.x << ", " << p.y << ")";
        return out;
    }

    double Point::dist(const Point& p1, const Point& p2) {
        return std::sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
    }
}