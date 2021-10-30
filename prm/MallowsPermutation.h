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
     * Randomly permutes the elements in [first,last) according to the Mallows distribution. A permutation p (theoretically) occurs with probability proportional to q^inv(p), where inv(p) counts the
     * number of inversions in p. \n \n
     * <b>NOTA BENE:</b> No comparisons of the elements in the range is made, instead, the initial (identity) ordering is inherited from simply the ordering in which the elements occur.
     *
     * \tparam It Iterator type of input
     * \tparam Gen Uniform 0-1 random number generator type
     * \param q Parameter for Mallows permutation
     * \param first Iterator at start of range
     * \param last iterator at end of range
     * \param random_generator Object such that random_generator() can be called producing a uniform random number in the range [0,1]
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

    template <class Gen = impl::UniformZeroOneGenerator>
    [[nodiscard]] std::vector<size_t> mallows_random_permutation(double q, size_t n, Gen&& random_generator = Gen{}) {
        auto result = impl::con::linear_vector(n);
        mallows_random_permutation(q, result.begin(), result.end(), std::forward<Gen>(random_generator));
        return result;
    }

} // namespace prm

#endif // H_PRM_IMPL_MALLOWSPERMUTATION_H
