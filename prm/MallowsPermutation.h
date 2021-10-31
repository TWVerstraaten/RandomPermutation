//
// Created by pc on 30-10-21.
//

#ifndef H_PRM_IMPL_MALLOWSPERMUTATION_H
#define H_PRM_IMPL_MALLOWSPERMUTATION_H

#include "UniformPermutation.h"
#include "impl/MallowsPermutationImpl.h"
#include "impl/UniformZeroOneGenerator.h"

#include <cassert>

namespace prm {

    /*!
     * Returns a random permutation of {0,..,size-1}, distributed according to the Mallows distribution
     *
     * @tparam Gen Uniform 0-1 random number generator type
     * @param q Parameter for Mallows permutation
     * @param size Number of elements
     * @param random_generator Object such that random_generator() can be called producing a uniform random number in the range [0,1]
     * @return A std::vector<size_t>
     */
    template <class Gen = impl::UniformZeroOneGenerator>
    [[nodiscard]] std::vector<size_t> mallows_random_permutation(double q, size_t size, Gen&& random_generator = Gen{}) {
        auto result = impl::con::linear_vector(size);
        mallows_random_permutation(q, result.begin(), result.end(), std::forward<Gen>(random_generator));
        return result;
    }

    /*!
     * Randomly permutes the elements in [first,last) according to the Mallows distribution.\n \n
     *
     * <b>NOTA BENE:</b> No comparison of the elements in the range is made, instead, the initial (identity) ordering is inherited from simply the order in which the elements occur.
     *
     * @tparam It Iterator type of input
     * @tparam Gen Uniform 0-1 random number generator type
     * @param q Parameter for Mallows permutation
     * @param first Iterator at start of range
     * @param last iterator at end of range
     * @param random_generator Object such that random_generator() can be called producing a uniform random number in the range [0,1]
     */
    template <class It, class Gen = impl::UniformZeroOneGenerator>
    void mallows_random_permutation(double q, It first, It last, Gen&& random_generator = Gen{}) {
        assert(q > 0);
        if (q == 1.0) {
            uniform_random_permutation(first, last, std::forward<Gen>(random_generator));
        } else if (q > 1.0) {
            impl::MallowsImplQGreaterThanOne<It, Gen>::permute(q, first, last, std::forward<Gen>(random_generator));
        } else {
            impl::MallowsImplQLessThanOne<It, Gen>::permute(q, first, last, std::forward<Gen>(random_generator));
        }
    }

} // namespace prm

#endif // H_PRM_IMPL_MALLOWSPERMUTATION_H
