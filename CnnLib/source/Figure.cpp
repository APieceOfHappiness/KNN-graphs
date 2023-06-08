#ifndef FIGURE_CPP
#define FIGURE_CPP

#include "../headers/Figure.hpp"

namespace geli {
    namespace graphic_object {
        Figure::Figure(const std::string& name) : script(name + ".py"), name(name) {
            if (!this->script.is_open()) {
                throw std::runtime_error("cannot open the file");
            }

            this->script << "import plotly.graph_objects as go" << std::endl;
            this->script << "fig = go.Figure()" << std::endl;
        }

        void Figure::write_vector_as_list(const std::string& name, const std::vector<double> &data) {
            this->script << name << "=[";
            if (data.size()) {
                if (data[0] == data[0]) {
                    this->script << data[0];
                }
                else {
                    this->script << "None";
                }
            }
            for (std::size_t i = 1; i < data.size(); ++i) {
                if (data[i] == data[i]) {
                    this->script << "," << data[i];
                }
                else {
                    this->script << ",None";
                }
            }
            this->script << "]" << std::endl;
        }

        void Figure::update_title(const std::string& title) {
            this->script << "fig.update_layout(title='" + title + "')" << std::endl;
        }

        void Figure::add_graph(const Nswg<Point, Point::HashPoint>& g,
                               std::size_t marker_size,
                               std::size_t line_width,
                               const std::string& marker_color,
                               const std::string& line_color,
                               const std::string& name) {

            std::unordered_set<Point, Point::HashPoint> drawn_points;

            // std::vector<double> node_x;
            // std::vector<double> node_y;

            std::vector<double> edge_x;
            std::vector<double> edge_y;

            for (auto &point : g.get_nodes()) {
                // node_x.push_back(point.x);
                // node_y.push_back(point.y);

                for (auto &neighbour : g.get_neighbours(point)) {
                    if (drawn_points.find(neighbour) == drawn_points.end()) {
                        edge_x.push_back(point.x);
                        edge_x.push_back(neighbour.x);
                        edge_x.push_back(graphic_object::Nan);

                        edge_y.push_back(point.y);
                        edge_y.push_back(neighbour.y);
                        edge_y.push_back(graphic_object::Nan);
                    }
                }

                drawn_points.insert(point);
            }

            this->add_markers_and_lines(edge_x, edge_y, marker_size, line_width, marker_color, line_color, name);
        }

        void Figure::add_markers_and_lines(const std::vector<double>& x,
                                           const std::vector<double>& y,
                                           std::size_t marker_size,
                                           std::size_t line_width,
                                           const std::string& marker_color,
                                           const std::string& line_color,
                                           const std::string& name) {
            if(x.size() != y.size()) {
                throw std::invalid_argument("size mismatch");
            }
            this->write_vector_as_list("X", x);
            this->write_vector_as_list("Y", y);

            this->script << "fig.add_trace(go.Scatter(x=X, y=Y, mode='markers+lines',"
                                                      "marker={'size':" << marker_size << ", 'color': '" + marker_color + "'},"
                                                      "line={'width':" << line_width << ", 'color': '" + line_color + "'},"
                                                      "name='" + name + "'))" << std::endl;                                    
        }

        void Figure::add_markers(const std::vector<double>& x,
                                 const std::vector<double>& y,
                                 std::size_t marker_size,
                                 const std::string& marker_color,
                                 const std::string& name) {
            if(x.size() != y.size()) {
                throw std::invalid_argument("size mismatch");
            }
            this->write_vector_as_list("X", x);
            this->write_vector_as_list("Y", y);

            this->script << "fig.add_trace(go.Scatter(x=X, y=Y, mode='markers', marker={'size':" << marker_size << ", 'color': '" + marker_color + "'}, name='" + name + "'))" << std::endl;
        }

        void Figure::add_line(const std::vector<double>& x,
                              const std::vector<double>& y,
                              std::size_t line_width,
                              const std::string& line_color,
                              const std::string& name) {
            if(x.size() != y.size()) {
                throw std::invalid_argument("size mismatch");
            }
            this->write_vector_as_list("X", x);
            this->write_vector_as_list("Y", y);

            this->script << "fig.add_trace(go.Scatter(x=X, y=Y, mode='lines', line={'width':" << line_width << ", 'color': '" + line_color + "'}, name='" + name + "'))" << std::endl;
        }
        
        void Figure::show() {
            this->script << "fig.show()" << std::endl;

            int res = std::system(("python3 " + this->name + ".py").c_str());

            if (res != 0) {
                throw std::runtime_error("smth wrong with std::system");
            }
        }

        void Figure::update_xaxes(const std::string& x_title, 
                          const std::string& axis_type) {
            this->script << "fig.update_xaxes(title_text='" + x_title + "', type='" + axis_type + "')" << std::endl;
        }

        void Figure::update_yaxes(const std::string& y_title, 
                          const std::string& axis_type) {
            this->script << "fig.update_yaxes(title_text='" + y_title + "', type='" + axis_type + "')" << std::endl;
        }

        Figure::~Figure() {
            this->script.close();

            int res = std::system(("rm " + this->name + ".py").c_str());
        }
    }
}

#endif