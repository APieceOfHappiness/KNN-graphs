#ifndef FIGURE_HPP
#define FIGURE_HPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_set>

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include <cstdlib>
#include <limits>

#include "../headers/PonomarenkoGraph.hpp"
#include "../headers/Point.hpp"

namespace geli {
    namespace graphic_object {
        const double Nan = std::numeric_limits<double>::quiet_NaN();

        void vsmooth(std::vector<double>& v, size_t count);

        class Figure {
            std::ofstream script;
            std::string name;

            void write_vector_as_list(const std::string& name, const std::vector<double> &data);
        public:
            Figure() = delete; // TODO: why not
            Figure(const std::string& name);
            Figure(const Figure& f) = delete;
            Figure(Figure&& f) = delete;

            void add_graph(const Nswg<Point, Point::HashPoint>& g,
                           std::size_t marker_size,
                           std::size_t line_width,
                           const std::string& marker_color,
                           const std::string& line_color,
                           const std::string& name);

            void update_title(const std::string& title);

            void add_markers_and_lines(const std::vector<double>& x,
                                       const std::vector<double>& y,
                                       std::size_t marker_size,
                                       std::size_t line_width,
                                       const std::string& marker_color,
                                       const std::string& line_color,
                                       const std::string& name);

            void add_markers(const std::vector<double>& x,
                             const std::vector<double>& y,
                             std::size_t marker_size,
                             const std::string& marker_color,
                             const std::string& name);

            void add_line(const std::vector<double>& x,
                          const std::vector<double>& y,
                          std::size_t line_width,
                          const std::string& line_color,
                          const std::string& name);

            void update_xaxes(const std::string& x_title, 
                              const std::string& axis_type);

            void update_yaxes(const std::string& y_title, 
                              const std::string& axis_type);

            void show();

            ~Figure();
        };
    }
}

#endif