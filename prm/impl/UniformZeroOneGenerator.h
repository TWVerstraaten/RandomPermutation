//
// Created by pc on 21-10-21.
//

#ifndef H_PRM_IMPL_UNIFORMZEROONEGENERATOR_H
#define H_PRM_IMPL_UNIFORMZEROONEGENERATOR_H

#include <random>

namespace prm::impl {

    /// Class that defines a double operator()() generating uniform doubles in the range [0,1]
    class UniformZeroOneGenerator {

      public:
        UniformZeroOneGenerator();

        /// Constructor with explicit seed for testing purposes
        ///
        /// \param seed The seed
        explicit UniformZeroOneGenerator(size_t seed);

        /// \return Random number in the range [0,1]
        double operator()();

      private:
        /// Mersenne Twister used to generate random numbers
        std::mt19937 m_mersenne_twister;
        /// The [0,1] distribution
        std::uniform_real_distribution<> m_distribution;
    };

} // namespace prm::impl

#endif // H_PRM_IMPL_UNIFORMZEROONEGENERATOR_H
