//
// Created by pc on 21-10-21.
//

#include "UniformZeroOneGenerator.h"

namespace prm::impl {
    UniformZeroOneGenerator::UniformZeroOneGenerator() : m_mersenne_twister(std::random_device{}()), m_distribution(0.0, 1.0) {
    }

    UniformZeroOneGenerator::UniformZeroOneGenerator(size_t seed) : m_mersenne_twister(seed), m_distribution(0.0, 1.0) {
    }

    double UniformZeroOneGenerator::operator()() {
        return m_distribution(m_mersenne_twister);
    }
} // namespace prm::impl