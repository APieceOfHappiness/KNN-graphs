#include <iostream>
#include <vector>
#include <map>
#include "../headers/Figure.hpp"
#include "../headers/PonomarenkoGraph.hpp"
#include "../headers/KleinbergGraph.hpp"
#include "../headers/RandomGraph.hpp"
#include "../headers/point.hpp"

double rrange(int min, int max) {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_real_distribution<double> distr(min, max);
    return distr(generator);
}

int main() {
    
    
    std::vector<geli::Point> points;

    for (size_t i = 0; i < 10; ++i) {
        for (size_t j = 0; j < 10; ++j) {
            points.push_back(geli::Point(i, j));
        }
    }  

    geli::KleinbergGraph<geli::Point, geli::Point::HashPoint> kgraph(2, 5);

    kgraph.load_nodes(points);

    geli::graphic_object::Figure fig("Kleinberg");
    fig.add_graph(kgraph, 10, 3, "red", "blue", "smth");
    fig.update_title("MEGA GRAPH");
    fig.update_xaxes("X axis", "linear");
    fig.update_yaxes("Y axis", "linear");
    fig.show();    

    // ------------------------------------------------------------------
    
    // std::vector<geli::Point> points;

    // for (size_t points_cnt = 0; points_cnt < 100; ++points_cnt) {
    //     points.push_back(geli::Point(rrange(0, 1000), rrange(0, 1000)));
    // }  

    // geli::PonomarenkoGraph<geli::Point, geli::Point::HashPoint> pgraph(10, 10);
    // geli::KleinbergGraph<geli::Point, geli::Point::HashPoint> kgraph(20, 20);
    // geli::RandomGraph<geli::Point, geli::Point::HashPoint> rgraph(20);

    // pgraph.load_nodes(points);
    // // kgraph.load_nodes(points);
    // rgraph.load_nodes(points);

    // geli::graphic_object::Figure fig("smth");

    // fig.add_graph(pgraph, 10, 3, "red", "blue", "smth");
    // fig.update_title("MEGA GRAPH");
    // fig.update_xaxes("X axis", "linear");
    // fig.update_yaxes("Y axis", "linear");
    // fig.show();

    // std::vector<double> pccs;
    // std::vector<double> kccs;
    // std::vector<double> rccs;
    // std::vector<double> xs;
    // for(size_t i = 5; i < 100; i += 5) {
    //     geli::PonomarenkoGraph<geli::Point, geli::Point::HashPoint> pgraph(3, i / 2);
    //     // geli::KleinbergGraph<geli::Point, geli::Point::HashPoint> kgraph(i);
    //     geli::RandomGraph<geli::Point, geli::Point::HashPoint> rgraph(i);
    //     pgraph.load_nodes(points);
    //     // kgraph.load_nodes(points);
    //     rgraph.load_nodes(points);

    //     double pccs_temp = 0;
    //     double kccs_temp = 0;
    //     double rccs_temp = 0;
    //     for (size_t atts = 0; atts < 1000; ++atts) {
    //         pccs_temp += pgraph.get_best_element(points[i % 100], 1).second;           
    //         // kccs_temp += kgraph.get_best_element(points[i % 100], 1).second;
    //         rccs_temp += rgraph.get_best_element(points[i % 100], 1).second;            
    //     }
    //     pccs.push_back(pccs_temp);
    //     kccs.push_back(kccs_temp);
    //     rccs.push_back(rccs_temp);
    //     xs.push_back(i);
    //     std::cout << pgraph.get_mean_deg() << std::endl;
    //     // std::cout << kgraph.get_mean_deg() << std::endl;
    //     std::cout << rgraph.get_mean_deg() << std::endl << std::endl;
    //     pgraph.clear();
    //     // kgraph.clear();
    //     rgraph.clear();
    // }

    // geli::graphic_object::Figure fig("CC_G");
    // fig.add_line(xs, pccs, 5, "blue", "pgraph loss");
    // // fig.add_line(xs, kccs, 5, "red", "kgraph loss");
    // // fig.add_line(xs, rccs, 5, "green", "rgraph loss");
    // fig.update_title("Sum loss of graphs");
    // fig.update_xaxes("parametr", "linear");
    // fig.update_yaxes("loss", "linear");
    // fig.show();

    // ----------------------------------------- cc test

    // std::vector<geli::Point> points;

    // for (size_t points_cnt = 0; points_cnt < 1000; ++points_cnt) {
    //     points.push_back(geli::Point(rrange(0, 1000), rrange(0, 1000)));
    // }  

    // std::vector<double> pccs;
    // std::vector<double> kccs;
    // std::vector<double> rccs;
    // std::vector<double> xs1;
    // std::vector<double> xs2;
    // std::vector<double> xs3;
    // for(size_t i = 5; i < 100; i += 5) {
    //     geli::PonomarenkoGraph<geli::Point, geli::Point::HashPoint> pgraph(1, i / 2);
    //     geli::KleinbergGraph<geli::Point, geli::Point::HashPoint> kgraph(i);
    //     geli::RandomGraph<geli::Point, geli::Point::HashPoint> rgraph(i);
    //     pgraph.load_nodes(points);
    //     kgraph.load_nodes(points);
    //     rgraph.load_nodes(points);
    //     pccs.push_back(pgraph.get_cc());
    //     kccs.push_back(kgraph.get_cc());
    //     rccs.push_back(rgraph.get_cc());
    //     xs1.push_back(pgraph.get_mean_deg());
    //     xs2.push_back(kgraph.get_mean_deg());
    //     xs3.push_back(rgraph.get_mean_deg());
    //     std::cout << i << std::endl;
    //     pgraph.clear();
    //     kgraph.clear();
    //     rgraph.clear();
    // }

    // geli::graphic_object::Figure fig("CC_G");
    // fig.add_line(xs1, pccs, 5, "blue", "pgraph ccs");
    // fig.add_line(xs2, kccs, 5, "red", "kgraph ccs");
    // fig.add_line(xs3, rccs, 5, "green", "rgraph ccs");
    // fig.update_title("cc of graphs");
    // fig.update_xaxes("deg", "linear");
    // fig.update_yaxes("cc", "linear");
    // fig.show();
    // -------------------------------------------------

    // std::vector<geli::Point> points;

    // for (size_t points_cnt = 0; points_cnt < 5000; ++points_cnt) {
    //     points.push_back(geli::Point(rrange(0, 1000), rrange(0, 1000)));
    // }  

    // geli::PonomarenkoGraph<geli::Point, geli::Point::HashPoint> pgraph(1, 50);
    // geli::KleinbergGraph<geli::Point, geli::Point::HashPoint> kgraph(120);
    // geli::RandomGraph<geli::Point, geli::Point::HashPoint> rgraph(50);

    // pgraph.load_nodes(points);
    // kgraph.load_nodes(points);
    // rgraph.load_nodes(points);

    // std::cout << "start" << std::endl;
    // std::cout << pgraph.get_cc() << std::endl;
    // std::cout << kgraph.get_cc() << std::endl;
    // std::cout << rgraph.get_cc() << std::endl;
    // std::cout << "fin" << std::endl;
    //------------------------------------------------------------

    // std::vector<geli::Point> points;

    // for (size_t points_cnt = 0; points_cnt < 10000; ++points_cnt) {
    //     points.push_back(geli::Point(rrange(0, 1000), rrange(0, 1000)));
    // }   

    // std::vector<double> losses;
    // std::vector<double> time;
    // // std::vector<int> neighbours_cnt = {5, 7, 10, 15, 20, 25, 30, 40, 50};
    // std::vector<int> neighbours_cnt = {5, 10, 50};


    // for (auto ncnt: neighbours_cnt) {
    //     for (size_t q_count = 1; q_count <= 10; ++q_count) {
    //         geli::PonomarenkoGraph<geli::Point, geli::Point::HashPoint> pgraph(q_count, ncnt);
    //         pgraph.load_nodes(points);
    //         double loss = 0;
    //         for (size_t attempt = 0; attempt < 100000; ++attempt) {
    //             loss += pgraph.get_best_element(points[attempt % 10000], 1).second;
    //         }
    //         std::cout << loss / 100000 << std::endl;
    //         losses.push_back(loss);
    //         time.push_back(q_count);
    //         pgraph.clear();
    //     }
    //     losses.push_back(geli::graphic_object::Nan);
    //     time.push_back(geli::graphic_object::Nan);
    // }

    // geli::graphic_object::Figure fig("different_losses");
    // fig.add_line(time, losses, 3, "blue", "hmm");
    // fig.show();

    // -------------------------------------------------------------------------

    // geli::PonomarenkoGraph<geli::Point, geli::Point::HashPoint> pgraph(2, 50);
    // geli::KleinbergGraph<geli::Point, geli::Point::HashPoint> kgraph(120);
    // geli::RandomGraph<geli::Point, geli::Point::HashPoint> rgraph(50);

    // pgraph.load_nodes(points);
    // kgraph.load_nodes(points);
    // rgraph.load_nodes(points);

    // std::cout << pgraph.get_mean_deg() << std::endl;
    // std::cout << kgraph.get_mean_deg() << std::endl;
    // std::cout << rgraph.get_mean_deg() << std::endl;

    // double loss1 = 0;    
    // double loss2 = 0;
    // double loss3 = 0;    

    // for (size_t i = 0; i < 10000; ++i) {
    //     loss1 += pgraph.get_best_element(points[i % 100], 1).second;
    //     loss2 += kgraph.get_best_element(points[i % 100], 1).second;
    //     loss3 += rgraph.get_best_element(points[i % 100], 1).second;
    // }

    // std::cout << loss1 << std::endl;
    // std::cout << loss2 << std::endl;
    // std::cout << loss3 << std::endl;

    return 0;
}