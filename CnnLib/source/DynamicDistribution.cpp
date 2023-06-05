#ifndef DYNAMIC_DISTRIBUTION_CPP
#define DYNAMIC_DISTRIBUTION_CPP

#include "../headers/DynamicDistribution.hpp"

namespace geli {

    DynamicDistribution::DynamicDistribution() : generator(rd()) {};

    void DynamicDistribution::push_back(double val) {
        if (this->partial_sum.size()) {
            this->partial_sum.push_back(this->partial_sum.back() + val);
        } else {
            this->partial_sum.push_back(val);
        }
    }

    void DynamicDistribution::pop_back(double val) {
        this->partial_sum.pop_back();
    }

    size_t DynamicDistribution::get_random_index() {
        if (!this->partial_sum.size()) {
            throw std::runtime_error("vector is empty");
        }
        std::uniform_real_distribution<double> distribution(0, this->partial_sum.back());
        double rand_val = distribution(this->generator);
        size_t res_index = std::lower_bound(this->partial_sum.begin(),
                                            this->partial_sum.end(),
                                            rand_val) - this->partial_sum.begin();
        return res_index;
    }

    void DynamicDistribution::clear() {
        this->partial_sum.clear();
    }
}

#endif

