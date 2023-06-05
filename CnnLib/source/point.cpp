#ifndef POINT_CPP
#define POINT_CPP

#include "../headers/point.hpp"



namespace geli {
    template<typename Obj>
    void add_to_seed(std::size_t &seed_val, const Obj& obj) {
        std::hash<double> hash_function;
        seed_val ^= hash_function(obj) + 0x9e3779b9 + (seed_val << 6) + (seed_val >> 2);
    }

    Point::Point(double x, double y) {
        this->x = x;
        this->y = y;
    }

    bool Point::operator==(const Point& p) const {
        return (p.x == this->x) && (p.y == this->y); 
    }

    std::size_t Point::HashPoint::operator()(const Point& p) const {
        std::size_t seed_val = 0;
        add_to_seed(seed_val, p.x);
        add_to_seed(seed_val, p.y);
        return seed_val;
    }

    std::ostream& operator<<(std::ostream& out, const Point& p) {
        out << "(" << p.x << ", " << p.y << ")";
        return out;
    }

    double Point::dist(const Point& p1, const Point& p2) {
        return std::sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
    }

    Point3D::Point3D(double x, double y, double z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    std::ostream& operator<<(std::ostream& out, const Point3D p) {
        out << "(" << p.x << ", " << p.y << ", " << p.z << ")";
        return out;
    }

    bool Point3D::operator==(const Point3D p) const {
        return (this->x == p.x) && (this->y == p.y) && (this->z == p.z);
    }

    double Point3D::dist(const Point3D p1, const Point3D p2) {
        return std::sqrt((p1.x - p2.x) * (p1.x - p2.x) + 
                         (p1.y - p2.y) * (p1.y - p2.y) + 
                         (p1.z - p2.z) * (p1.z - p2.z));
    }

    std::size_t Point3D::HashPoint::operator()(const Point3D& p) const {
        std::size_t seed_val = 0;
        add_to_seed(seed_val, p.x);
        add_to_seed(seed_val, p.y);
        add_to_seed(seed_val, p.z);
        return seed_val;
    }
}

#endif