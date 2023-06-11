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

    for (size_t points_cnt = 0; points_cnt < 3000; ++points_cnt) {
        points.push_back(geli::Point(rrange(0, 200), rrange(0, 200)));
    }  

    std::vector<double> pccs0;
    std::vector<double> pccs1;
    std::vector<double> pccs2;
    std::vector<double> pccs3;
    std::vector<double> pccs4;
    std::vector<double> pccs5;
    std::vector<double> xs;
    for(size_t i = 0; i < 15; i++) {
        geli::PonomarenkoGraph<geli::Point, geli::Point::HashPoint> kgraph0(0, i);
        geli::PonomarenkoGraph<geli::Point, geli::Point::HashPoint> kgraph1(1, i);
        geli::PonomarenkoGraph<geli::Point, geli::Point::HashPoint> kgraph2(2, i);
        geli::PonomarenkoGraph<geli::Point, geli::Point::HashPoint> kgraph3(3, i);
        geli::PonomarenkoGraph<geli::Point, geli::Point::HashPoint> kgraph4(5, i);
        geli::PonomarenkoGraph<geli::Point, geli::Point::HashPoint> kgraph5(7, i);
        kgraph0.load_nodes(points);
        kgraph1.load_nodes(points);
        kgraph2.load_nodes(points);
        kgraph3.load_nodes(points);
        kgraph4.load_nodes(points);
        kgraph5.load_nodes(points);

        double pccs_temp0 = 0;
        double pccs_temp1 = 0;
        double pccs_temp2 = 0;
        double pccs_temp3 = 0;
        double pccs_temp4 = 0;
        double pccs_temp5 = 0;
        for (size_t atts = 0; atts < 1000; ++atts) {
            pccs_temp0 += kgraph0.get_best_element(points[atts % 100], 1).path_len;  
            pccs_temp1 += kgraph1.get_best_element(points[atts % 100], 1).path_len;           
            pccs_temp2 += kgraph2.get_best_element(points[atts % 100], 1).path_len;
            pccs_temp3 += kgraph3.get_best_element(points[atts % 100], 1).path_len;   
            pccs_temp4 += kgraph4.get_best_element(points[atts % 100], 1).path_len;
            pccs_temp5 += kgraph5.get_best_element(points[atts % 100], 1).path_len;
        }
        pccs0.push_back(pccs_temp0 / 1000);
        pccs1.push_back(pccs_temp1 / 1000 / 1);
        pccs2.push_back(pccs_temp2 / 1000 / 2);
        pccs3.push_back(pccs_temp3 / 1000 / 3);
        pccs4.push_back(pccs_temp4 / 1000 / 5);
        pccs5.push_back(pccs_temp5 / 1000 / 7);
        // pccs0.push_back(pccs_temp0 / 1000);
        // pccs1.push_back(pccs_temp1 / 1000);
        // pccs2.push_back(pccs_temp2 / 1000);
        // pccs3.push_back(pccs_temp3 / 1000);
        // pccs4.push_back(pccs_temp4 / 1000);
        // pccs5.push_back(pccs_temp5 / 1000);
        std::cout << i << std::endl;
        // pccs.push_back(pgraph.get_cc());
        // kccs.push_back(kgraph.get_cc());
        // rccs.push_back(rgraph.get_cc());
        xs.push_back(i);
        // std::cout << pccs.back() << std::endl;
        // std::cout << kccs.back() << std::endl;
        // std::cout << rccs.back() << std::endl << std::endl;
        kgraph0.clear();
        kgraph1.clear();
        kgraph2.clear();
        kgraph3.clear();
        kgraph4.clear();
        kgraph5.clear();
    }

    geli::graphic_object::Figure fig("Mean_loss");
    fig.add_line(xs, pccs0, 5, "purple", "kgraph loss (0, *)");
    fig.add_line(xs, pccs1, 5, "blue", "kgraph loss (1, *)");
    fig.add_line(xs, pccs2, 5, "red", "kgraph loss (2, *)");
    fig.add_line(xs, pccs3, 5, "green", "kgraph loss (3, *)");
    fig.add_line(xs, pccs4, 5, "black", "kgraph loss (5, *)");
    fig.add_line(xs, pccs5, 5, "grey", "kgraph loss (7, *)");
    fig.update_title("avg loss Kleinberg");
    fig.update_xaxes("long paths", "linear");
    fig.update_yaxes("mean loss", "linear");
    fig.show();

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
//-------------------__!!!!!!!!!!!!
    // std::vector<double> pccs;
    // std::vector<double> kccs;
    // std::vector<double> rccs;
    // std::vector<double> xs;
    // for(size_t i = 0; i < 15; i++) {
    //     geli::PonomarenkoGraph<geli::Point, geli::Point::HashPoint> pgraph(3, i);
    //     geli::KleinbergGraph<geli::Point, geli::Point::HashPoint> kgraph(11, i);
    //     geli::RandomGraph<geli::Point, geli::Point::HashPoint> rgraph(i);
    //     pgraph.load_nodes(points);
    //     kgraph.load_nodes(points);
    //     rgraph.load_nodes(points);

    //     double pccs_temp = 0;
    //     double kccs_temp = 0;
    //     double rccs_temp = 0;
    //     for (size_t atts = 0; atts < 1000; ++atts) {
    //         pccs_temp += pgraph.get_best_element(points[i % 100], 1).path_len;           
    //         kccs_temp += kgraph.get_best_element(points[i % 100], 1).path_len;
    //         rccs_temp += rgraph.get_best_element(points[i % 100], 1).path_len;            
    //     }
    //     pccs.push_back(pccs_temp / 1000);
    //     kccs.push_back(kccs_temp / 1000);
    //     rccs.push_back(rccs_temp / 1000);
    //     // pccs.push_back(pgraph.get_cc());
    //     // kccs.push_back(kgraph.get_cc());
    //     // rccs.push_back(rgraph.get_cc());
    //     xs.push_back(i);
    //     std::cout << pccs.back() << std::endl;
    //     std::cout << kccs.back() << std::endl;
    //     std::cout << rccs.back() << std::endl << std::endl;
    //     pgraph.clear();
    //     kgraph.clear();
    //     rgraph.clear();
    // }

    // geli::graphic_object::Figure fig("Mean_path_len");
    // fig.add_line(xs, pccs, 5, "blue", "pgraph path");
    // fig.add_line(xs, kccs, 5, "red", "kgraph path");
    // fig.add_line(xs, rccs, 5, "green", "rgraph path");
    // fig.update_title("Mean path length");
    // fig.update_xaxes("parametr", "linear");
    // fig.update_yaxes("mean path_len", "linear");
    // fig.show();

    //----------------------------------------------!!!!!!!!!!!!
    // std::vector<geli::Point> points;

    // for (size_t points_cnt = 0; points_cnt < 1000; ++points_cnt) {
    //     points.push_back(geli::Point(rrange(0, 200), rrange(0, 200)));
    // }  

    // std::vector<geli::Point> points;

    // points.push_back(geli::Point(0, 0));
    // points.push_back(geli::Point(1, 1));

    // std::vector<double> res1;
    // std::vector<double> res2;
    // std::vector<double> res3;
    // std::vector<double> x;
    // for (size_t n = 3; n < 100; ++n) {      
    //     geli::PonomarenkoGraph<geli::Point, geli::Point::HashPoint> pgraph(1, 16);
    //     geli::KleinbergGraph<geli::Point, geli::Point::HashPoint> kgraph(7, 3);
    //     geli::RandomGraph<geli::Point, geli::Point::HashPoint> rgraph(5);
    //     rgraph.load_nodes(points);
    //     kgraph.load_nodes(points);
    //     pgraph.load_nodes(points);
        
    //     x.push_back(n);
    //     // res1.push_back(pgraph.get_cc());
    //     // res2.push_back(kgraph.get_cc());
    //     // res3.push_back(rgraph.get_cc());

    //     geli::SearchInfo info = pgraph.get_best_element();
    //     std::cout <<

    //     points.push_back(geli::Point(n, n));
    //     rgraph.clear();
    //     pgraph.clear();
    //     kgraph.clear();
    //     std::cout << n;
    // }

    // geli::graphic_object::Figure fig("CC_RandomGraph");
    // fig.add_line(x, res1, 5, "green", "cc_NN");
    // fig.add_line(x, res2, 5, "blue", "cc_Kleinberg");
    // fig.add_line(x, res3, 5, "red", "cc_Random");
    // fig.update_xaxes("n", "linear");
    // fig.update_yaxes("cc", "linear");
    // fig.show();    

    // std::vector<geli::ManhPoint> points;

    // for (size_t i = 1; i < 10;  ++i) {
    //     for (size_t j = 1; j < 10; ++j) {
    //         points.push_back(geli::ManhPoint(i * 1, j * 1));
    //     }
    // }  


    
    // for (size_t sh = 1; sh < 10; ++sh) {
    //     for (size_t lng = 1; lng < 10; ++lng) {
    //         geli::KleinbergGraph<geli::ManhPoint, geli::ManhPoint::HashPoint> kgraph(sh, lng);
    //         kgraph.load_nodes(points);
    //         std::cout << sh << ", " <<  lng << "|" << kgraph.get_cc() << std::endl;
    //         kgraph.clear();
    //     }
    // }

    // geli::graphic_object::Figure fig("Kleinberg");
    // fig.add_graph(kgraph, 10, 3, "red", "blue", "smth");
    // fig.update_title("MEGA GRAPH");
    // fig.update_xaxes("X axis", "linear");
    // fig.update_yaxes("Y axis", "linear");
    // fig.show();    

    // ------------------------------------------------------------------
    

    // std::vector<geli::Point> points;

    // for (size_t points_cnt = 0; points_cnt < 3000; ++points_cnt) {
    //     points.push_back(geli::Point(rrange(0, 200), rrange(0, 200)));
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
    // for(size_t i = 0; i < 15; i++) {
        // geli::PonomarenkoGraph<geli::Point, geli::Point::HashPoint> pgraph(3, 14 + i);
        // geli::KleinbergGraph<geli::Point, geli::Point::HashPoint> kgraph(11, i);
        // geli::RandomGraph<geli::Point, geli::Point::HashPoint> rgraph(27 + i * 2);
    //     pgraph.load_nodes(points);
    //     kgraph.load_nodes(points);
    //     rgraph.load_nodes(points);

    //     double pccs_temp = 0;
    //     double kccs_temp = 0;
    //     double rccs_temp = 0;
    //     for (size_t atts = 0; atts < 1000; ++atts) {
    //         pccs_temp += pgraph.get_best_element(points[i % 100], 1).second;           
    //         kccs_temp += kgraph.get_best_element(points[i % 100], 1).second;
    //         rccs_temp += rgraph.get_best_element(points[i % 100], 1).second;            
    //     }
    //     pccs.push_back(pccs_temp / 1000);
    //     kccs.push_back(kccs_temp / 1000);
    //     rccs.push_back(rccs_temp / 1000);
    //     xs.push_back(i);
    //     std::cout << pgraph.get_mean_deg() << std::endl;
    //     std::cout << kgraph.get_mean_deg() << std::endl;
    //     std::cout << rgraph.get_mean_deg() << std::endl << std::endl;
    //     pgraph.clear();
    //     kgraph.clear();
    //     rgraph.clear();
    // }

    // geli::graphic_object::Figure fig("CC_G");
    // fig.add_line(xs, pccs, 5, "blue", "pgraph loss");
    // fig.add_line(xs, kccs, 5, "red", "kgraph loss");
    // fig.add_line(xs, rccs, 5, "green", "rgraph loss");
    // fig.update_title("Sum loss of graphs");
    // fig.update_xaxes("parametr", "linear");
    // fig.update_yaxes("loss", "linear");
    // fig.show();

    // ----------------------------------------- cc test

    // std::vector<geli::Point> points;

    // for (size_t points_cnt = 0; points_cnt < 3000; ++points_cnt) {
    //     points.push_back(geli::Point(rrange(0, 200), rrange(0, 200)));
    // }  

    // std::vector<double> pccs;
    // std::vector<double> kccs;
    // std::vector<double> rccs;
    // std::vector<double> xs1;
    // std::vector<double> xs2;
    // std::vector<double> xs3;
    // for(size_t i = 0; i < 10; i += 1) {
    //     geli::PonomarenkoGraph<geli::Point, geli::Point::HashPoint> pgraph(3, 14 + i);
    //     geli::KleinbergGraph<geli::Point, geli::Point::HashPoint> kgraph(11, i);
    //     geli::RandomGraph<geli::Point, geli::Point::HashPoint> rgraph(27 + i * 2);
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