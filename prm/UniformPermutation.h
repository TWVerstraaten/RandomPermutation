//
// Created by pc on 21-10-21.
//

#ifndef H_PRM_UNIFORMPERMUTATION_H
#define H_PRM_UNIFORMPERMUTATION_H

#include "impl/Con.h"
#include "impl/UniformPermutationImpl.h"
#include "impl/UniformZeroOneGenerator.h"

namespace prm {

    /*!
     * Returns a random permutation of {0,..,size-1}, each order equally likely
     *
     * @tparam Gen Uniform 0-1 random number generator type
     * @param size Number of elements
     * @param random_generator Object such that random_generator() can be called producing a uniform random number in the range [0,1]
     * @return A std::vector<size_t>
     */
    template <class Gen = impl::UniformZeroOneGenerator>
    [[nodiscard]] std::vector<size_t> uniform_random_permutation(size_t size, Gen&& random_generator = Gen{}) {
        auto result = impl::con::linear_vector(size);
        impl::uniform_random_permutation_impl(result.begin(), result.end(), random_generator);
        return result;
    }

    /*!
     * Randomly permutes the elements in [first,last). Each possible permutation is (theoretically) equally likely to occur.
     *
     * @tparam It Iterator type of input
     * @tparam Gen Uniform 0-1 random number generator type
     * @param first Iterator at start of range
     * @param last iterator at end of range
     * @param random_generator Object such that random_generator() can be called producing a uniform random number in the range [0,1]
     */
    template <class It, class Gen = impl::UniformZeroOneGenerator>
    void uniform_random_permutation(It first, It last, Gen&& random_generator = Gen{}) {
        impl::uniform_random_permutation_impl(first, last, random_generator);
    }

} // namespace prm

#endif // H_PRM_UNIFORMPERMUTATION_H
