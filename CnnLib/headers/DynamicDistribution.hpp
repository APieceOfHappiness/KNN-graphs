#ifndef DYNAMIC_DISTRIBUTION_HPP
#define DYNAMIC_DISTRIBUTION_HPP

#include <iostream>
#include <vector>
#include <random>


namespace geli {
    class DynamicDistribution {
        std::vector<double> partial_sum;

        std::random_device rd;
        std::mt19937 generator;
    public:
        DynamicDistribution();
        DynamicDistribution(const DynamicDistribution& rv) = delete;
        DynamicDistribution(DynamicDistribution&& rv) = delete;

        void push_back(double val);

        void pop_back(double val);

        void clear();

        size_t get_random_index();

        ~DynamicDistribution() = default;
    };
}

#endif

