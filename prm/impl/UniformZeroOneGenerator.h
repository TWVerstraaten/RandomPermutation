//
// Created by pc on 21-10-21.
//

#ifndef H_PRM_UNIFORMZEROONEGENERATOR_H
#define H_PRM_UNIFORMZEROONEGENERATOR_H

#include <random>

namespace prm::impl {

    class UniformZeroOneGenerator {

      public:
        UniformZeroOneGenerator();

        explicit UniformZeroOneGenerator(size_t seed);

        double operator()();

      private:
        std::mt19937                     m_mersenne_twister;
        std::uniform_real_distribution<> m_distribution;
    };

} // namespace prm::impl

#endif // H_PRM_UNIFORMZEROONEGENERATOR_H
