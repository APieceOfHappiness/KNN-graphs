#include<iostream>
#include"../headers/KleinbergGraph.hpp"
#include"../headers/PonomarenkoGraph.hpp"
#include"../headers/Point.hpp"
#include"../headers/Figure.hpp"
#include "../headers/RandomGraph.hpp"
#include<vector>
#include<random>

double rrange(int min, int max) {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_real_distribution<double> distr(min, max);
    return distr(generator);
}

int main() {

    std::vector<geli::Point> points;
    for (std::size_t i = 0; i < 3000; ++i) {
        points.push_back(geli::Point(rrange(0, 200), rrange(0, 200)));
    }

    std::vector<double> losses1;
    std::vector<double> losses2;
    std::vector<double> losses3;
    std::vector<double> losses5;
    std::vector<double> losses8;
    std::vector<double> x;

    double loss1 = 0;
    double loss2 = 0;
    double loss3 = 0;
    double loss5 = 0;
    double loss8 = 0;
    for (std::size_t i = 0; i < 20; ++i) {
        geli::PonomarenkoGraph<geli::Point, geli::Point::HashPoint> nngraph1(1, i);
        geli::PonomarenkoGraph<geli::Point, geli::Point::HashPoint> nngraph2(2, i);
        geli::PonomarenkoGraph<geli::Point, geli::Point::HashPoint> nngraph3(3, i);
        geli::PonomarenkoGraph<geli::Point, geli::Point::HashPoint> nngraph5(5, i);
        geli::PonomarenkoGraph<geli::Point, geli::Point::HashPoint> nngraph8(8, i);
        std::cout << i << std::endl;
        nngraph1.load_nodes(points);
        nngraph2.load_nodes(points);
        nngraph3.load_nodes(points);
        nngraph5.load_nodes(points);
        nngraph8.load_nodes(points);

        for (std::size_t i = 0; i < 1000; ++i) {
            loss1 += nngraph1.get_best_element(geli::Point(rrange(0, 200), rrange(0, 200)), 10).path_len;                
            loss2 += nngraph2.get_best_element(geli::Point(rrange(0, 200), rrange(0, 200)), 10).path_len;                
            loss3 += nngraph3.get_best_element(geli::Point(rrange(0, 200), rrange(0, 200)), 10).path_len;                
            loss5 += nngraph5.get_best_element(geli::Point(rrange(0, 200), rrange(0, 200)), 10).path_len;                
            loss8 += nngraph8.get_best_element(geli::Point(rrange(0, 200), rrange(0, 200)), 10).path_len;                    
        }
        loss1 /= 1000;
        loss2 /= 1000;
        loss3 /= 1000;
        loss5 /= 1000;
        loss8 /= 1000;

        losses1.push_back(loss1);
        losses2.push_back(loss2);
        losses3.push_back(loss3);
        losses5.push_back(loss5);
        losses8.push_back(loss8);
        x.push_back(i);

        nngraph1.clear();
        nngraph2.clear();
        nngraph3.clear();
        nngraph5.clear();
        nngraph8.clear();        
    }

    
    geli::graphic_object::Figure fig("loss_test_NNGraph");
    fig.update_title("mean path len test (NNGraph)");
    fig.add_line(x, losses1, 3, "red", "nngraph(1, *)");
    fig.add_line(x, losses2, 3, "green", "nngraph(2, *)");
    fig.add_line(x, losses3, 3, "blue", "nngraph(3, *)");
    fig.add_line(x, losses5, 3, "yellow", "nngraph(5, *)");
    fig.add_line(x, losses8, 3, "black", "nngraph(8, *)");
    fig.update_xaxes("parameter: mean neighbours", "linear");
    fig.update_yaxes("mean path len", "linear");
    fig.show();   

    // std::vector<geli::Point> points;

    // for (size_t points_cnt = 0; points_cnt < 30; ++points_cnt) {
    //     points.push_back(geli::Point(rrange(0, 200), rrange(0, 200)));
    // }  

    // geli::RandomGraph<geli::Point, geli::Point::HashPoint> rg(points.size() / 7);
    // rg.load_nodes(points);

    // geli::graphic_object::Figure fig("Random_graph");
    // fig.add_graph(rg, 10, 3, "red", "blue", "random_graph");
    // fig.update_title("Random graph");
    // fig.update_xaxes("X", "linear");
    // fig.update_yaxes("Y", "linear");
    // fig.show();    

    // std::vector<geli::Point> points;

    // for (size_t points_cnt = 0; points_cnt < 3000; ++points_cnt) {
    //     points.push_back(geli::Point(rrange(0, 200), rrange(0, 200)));
    // }  

    // std::vector<double> pccs;
    // std::vector<double> kccs;
    // std::vector<double> rccs;
    // std::vector<double> xs;
    // for(size_t i = 2; i < 15; i++) {
    //     geli::PonomarenkoGraph<geli::Point, geli::Point::HashPoint> pgraph(2, 14 + i);
    //     geli::KleinbergGraph<geli::Point, geli::Point::HashPoint> kgraph(11, i);
    //     geli::RandomGraph<geli::Point, geli::Point::HashPoint> rgraph(27 + i * 2);
    
    //     pgraph.load_nodes(points);
    //     kgraph.load_nodes(points);
    //     rgraph.load_nodes(points);

    //     double pccs_temp = 0;
    //     double kccs_temp = 0;
    //     double rccs_temp = 0;
    //     for (size_t atts = 0; atts < 10000; ++atts) {
    //         pccs_temp += pgraph.get_best_element(points[i % 100], 1).loss;           
    //         kccs_temp += kgraph.get_best_element(points[i % 100], 1).loss;
    //         rccs_temp += rgraph.get_best_element(points[i % 100], 1).loss;            
    //     }
    //     pccs.push_back(pccs_temp / 10000);
    //     kccs.push_back(kccs_temp / 10000);
    //     rccs.push_back(rccs_temp / 10000);
    //     // pccs.push_back(pgraph.get_cc());
    //     // kccs.push_back(kgraph.get_cc());
    //     // rccs.push_back(rgraph.get_cc());
    //     xs.push_back(pgraph.get_mean_deg());
    //     std::cout << pccs.back() << "\t" << pgraph.get_mean_deg() <<  std::endl;
    //     std::cout << kccs.back() << "\t" << kgraph.get_mean_deg() <<  std::endl;
    //     std::cout << rccs.back() << "\t" << rgraph.get_mean_deg() <<  std::endl << std::endl;
    //     pgraph.clear();
    //     kgraph.clear();
    //     rgraph.clear();
    // }

    // geli::graphic_object::vsmooth(xs, 4);
    // geli::graphic_object::vsmooth(kccs, 4);
    // geli::graphic_object::vsmooth(pccs, 4);
    // geli::graphic_object::vsmooth(rccs, 4);

    // geli::graphic_object::Figure fig("Mean_path_len");
    // fig.add_line(xs, pccs, 5, "blue", "nngraph loss");
    // fig.add_line(xs, kccs, 5, "red", "kgraph loss");
    // fig.add_line(xs, rccs, 5, "green", "rgraph loss");
    // fig.update_title("Mean loss");
    // fig.update_xaxes("parametr", "linear");
    // fig.update_yaxes("mean loss", "linear");
    // fig.show();


    // std::vector<double> cc;
    // std::vector<double> x;

    // for (std::size_t i = 3; i < 60; ++i) {
    //     std::cout << i << std::endl;
    //     geli::RandomGraph<geli::Point, geli::Point::HashPoint> rg(5);
        
    //     std::vector<geli::Point> points;

    //     for (std::size_t j = 0; j < i; ++j) {
    //         points.push_back(geli::Point(rrange(0, 200), rrange(0, 200)));
    //     }

    //     rg.load_nodes(points);

    //     x.push_back(i);
    //     cc.push_back(rg.get_cc());
    //     std::cout << rg.get_cc() << rg.get_size();
    //     points.clear();
    //     rg.clear();
    // }

    // geli::graphic_object::vsmooth(x, 5);
    // geli::graphic_object::vsmooth(cc, 5);
    // geli::graphic_object::Figure fig("Table");
    // fig.add_line(x, cc, 3, "green", "cc(G)");
    // fig.update_title("CC(G)");
    // fig.update_xaxes("points count", "linear");
    // fig.update_yaxes("cc", "linear");
    // fig.show();

    // std::vector<geli::Point> points;

    // for (size_t points_cnt = 0; points_cnt < 3000; ++points_cnt) {
    //     points.push_back(geli::Point(rrange(0, 200), rrange(0, 200)));
    // }  

    // std::vector<double> pccs0;
    // std::vector<double> pccs1;
    // std::vector<double> pccs2;
    // std::vector<double> pccs3;
    // std::vector<double> pccs4;
    // std::vector<double> pccs5;
    // std::vector<double> xs;
    // for(size_t i = 0; i < 15; i++) {
    //     std::cout << "start making graphs" << std::endl;
    //     geli::PonomarenkoGraph<geli::Point, geli::Point::HashPoint> kgraph0(0, i);
    //     geli::PonomarenkoGraph<geli::Point, geli::Point::HashPoint> kgraph1(1, i);
    //     geli::PonomarenkoGraph<geli::Point, geli::Point::HashPoint> kgraph2(2, i);
    //     geli::PonomarenkoGraph<geli::Point, geli::Point::HashPoint> kgraph3(3, i);
    //     geli::PonomarenkoGraph<geli::Point, geli::Point::HashPoint> kgraph4(5, i);
    //     geli::PonomarenkoGraph<geli::Point, geli::Point::HashPoint> kgraph5(7, i);
    //     std::cout << "finish making graphs" << std::endl;
    //     std::cout << "start loading nodes" << std::endl;
    //     kgraph0.load_nodes(points);
    //     kgraph1.load_nodes(points);
    //     kgraph2.load_nodes(points);
    //     kgraph3.load_nodes(points);
    //     kgraph4.load_nodes(points);
    //     kgraph5.load_nodes(points);
    //     std::cout << "finish loading nodes" << std::endl;

    //     double pccs_temp0 = 0;
    //     double pccs_temp1 = 0;
    //     double pccs_temp2 = 0;
    //     double pccs_temp3 = 0;
    //     double pccs_temp4 = 0;
    //     double pccs_temp5 = 0;

    //     std::cout << "start checking" << std::endl;
    //     for (size_t atts = 0; atts < 1000; ++atts) {
    //         pccs_temp0 += kgraph0.get_best_element(points[atts % 100], 1).path_len;  
    //         pccs_temp1 += kgraph1.get_best_element(points[atts % 100], 1).path_len;           
    //         pccs_temp2 += kgraph2.get_best_element(points[atts % 100], 1).path_len;
    //         pccs_temp3 += kgraph3.get_best_element(points[atts % 100], 1).path_len;   
    //         pccs_temp4 += kgraph4.get_best_element(points[atts % 100], 1).path_len;
    //         pccs_temp5 += kgraph5.get_best_element(points[atts % 100], 1).path_len;
    //     }
    //     std::cout << "finish checking" << std::endl;

    //     pccs0.push_back(pccs_temp0 / 1000);
    //     pccs1.push_back(pccs_temp1 / 1000 / 1);
    //     pccs2.push_back(pccs_temp2 / 1000 / 2);
    //     pccs3.push_back(pccs_temp3 / 1000 / 3);
    //     pccs4.push_back(pccs_temp4 / 1000 / 5);
    //     pccs5.push_back(pccs_temp5 / 1000 / 7);
    //     // pccs0.push_back(pccs_temp0 / 1000);
    //     // pccs1.push_back(pccs_temp1 / 1000);
    //     // pccs2.push_back(pccs_temp2 / 1000);
    //     // pccs3.push_back(pccs_temp3 / 1000);
    //     // pccs4.push_back(pccs_temp4 / 1000);
    //     // pccs5.push_back(pccs_temp5 / 1000);
    //     std::cout << i << std::endl;
    //     // pccs.push_back(pgraph.get_cc());
    //     // kccs.push_back(kgraph.get_cc());
    //     // rccs.push_back(rgraph.get_cc());
    //     xs.push_back(i);
    //     // std::cout << pccs.back() << std::endl;
    //     // std::cout << kccs.back() << std::endl;
    //     // std::cout << rccs.back() << std::endl << std::endl;
    //     kgraph0.clear();
    //     kgraph1.clear();
    //     kgraph2.clear();
    //     kgraph3.clear();
    //     kgraph4.clear();
    //     kgraph5.clear();
    // }

    
    // geli::graphic_object::vsmooth(pccs0, 4);
    // geli::graphic_object::vsmooth(pccs1, 4);
    // geli::graphic_object::vsmooth(pccs2, 4);
    // geli::graphic_object::vsmooth(pccs3, 4);
    // geli::graphic_object::vsmooth(pccs4, 4);
    // geli::graphic_object::vsmooth(pccs5, 4);    
    // geli::graphic_object::vsmooth(xs, 4);   

    // geli::graphic_object::Figure fig("Mean_loss");
    // fig.add_line(xs, pccs0, 5, "purple", "kgraph loss (0, *)");
    // fig.add_line(xs, pccs1, 5, "blue", "kgraph loss (1, *)");
    // fig.add_line(xs, pccs2, 5, "red", "kgraph loss (2, *)");
    // fig.add_line(xs, pccs3, 5, "green", "kgraph loss (3, *)");
    // fig.add_line(xs, pccs4, 5, "black", "kgraph loss (5, *)");
    // fig.add_line(xs, pccs5, 5, "grey", "kgraph loss (7, *)");
    // fig.update_title("avg loss Kleinberg");
    // fig.update_xaxes("long paths", "linear");
    // fig.update_yaxes("mean loss", "linear");
    // fig.show();

    // geli::PonomarenkoGraph<geli::Point, geli::Point::HashPoint> pg;
    // geli::KleinbergGraph<geli::Point, geli::Point::HashPoint> kg(7, 3);
    
    // std::random_device rd;
    // std::mt19937 generator(rd());
    // std::uniform_real_distribution<double> distr(0, 100);
    // std::vector<geli::Point> points;
    // for(std::size_t i = 0; i < 1000; ++i) {
    //     points.push_back(geli::Point(distr(generator), distr(generator)));
    // }

    // kg.load_nodes(points);
    // std::cout << "done" << std::endl;

    // for(std::size_t i = 0; i < 10000; ++i) {
    //     kg.get_best_element(geli::Point(distr(generator), distr(generator)), 1);
    // }

    // std::cout << "cc(G): " << kg.get_cc() << std::endl;
    // std::cout << "deg(G): " << kg.get_mean_deg() << std::endl;


    // geli::graphic_object::Figure fig("smth");
    // std::vector<double> x = {1, 2, 3, 4, 5};
    // std::vector<double> y = {1, 4, 9, 16, 25};
    // std::vector<double> y1 = {2, 5, 10, 17, 26};
    // fig.add_line(x, y, 3, "red", "pg");
    // fig.show();

    return 0;
}