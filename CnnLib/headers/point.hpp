#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <iostream>
#include <cmath>

namespace geli {

    template<typename Obj>
    void add_to_seed(std::size_t &seed, const Obj& obj);

    class Point {
    public:
        double x;
        double y;
        Point() = default;
        Point(const Point& p) = default;
        Point(Point&& p) = default;
        Point(double x, double y);
        friend std::ostream& operator<<(std::ostream& out, const Point& p);
        bool operator==(const Point& p) const;
        
        static double dist(const Point& p1, const Point& p2);
        
        class HashPoint {
        public:
            std::size_t operator()(const Point& p) const;
        };
        ~Point() = default;
    };



    class Point3D {
    public:
        double x;
        double y;
        double z;
        Point3D() = default;
        Point3D(const Point3D& p) = default;
        Point3D(Point3D&& p) = default;
        Point3D(double x, double y, double z);
        friend std::ostream& operator<<(std::ostream& out, const Point3D p);
        bool operator==(const Point3D p) const;
        static double dist(const Point3D p1, const Point3D p2);
        class HashPoint {
        public:
            std::size_t operator()(const Point3D& p) const;
        };
    };

    
}

#endif