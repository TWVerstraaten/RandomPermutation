//
// Created by pc on 30-10-21.
//

#ifndef H_PRM_EWENSPERMUTATION_H
#define H_PRM_EWENSPERMUTATION_H

#include "impl/EwensPermutationImpl.h"
#include "impl/UniformZeroOneGenerator.h"

namespace prm {

    /*!
     * Returns a random permutation of {0,..,n-1}, distributed according to the Ewens distribution
     *
     * @tparam Gen Uniform 0-1 random number generator type
     * @param theta Parameter for Ewens permutation
     * @param n Number of elements
     * @param random_generator Object such that random_generator() can be called producing a uniform random number in the range [0,1]
     * @return A std::vector<size_t>
     */
    template <class Gen = impl::UniformZeroOneGenerator>
    [[nodiscard]] std::vector<size_t> ewens_random_permutation(const double theta, const size_t n, Gen&& random_generator = Gen{}) {
        assert(theta > 0);
        if (theta == 1.0) {
            return uniform_random_permutation(n, std::forward<Gen>(random_generator));
        } else {
            return impl::ewens_permutation_impl<Gen>(theta, n, std::forward<Gen>(random_generator));
        }
    }

    /*!
     * Randomly permutes the elements in [first,last) according to the Ewens distribution.\n \n
     *
     * <b>NOTA BENE:</b> No comparison of the elements in the range is made, instead, the initial (identity) ordering is inherited from simply the order in which the elements occur.
     *
     * @tparam It Iterator type of input
     * @tparam Gen Uniform 0-1 random number generator type
     * @param theta Parameter for Ewens permutation
     * @param first Iterator at start of range
     * @param last iterator at end of range
     * @param random_generator Object such that random_generator() can be called producing a uniform random number in the range [0,1]
     */
    template <class It, class Gen = impl::UniformZeroOneGenerator>
    void ewens_random_permutation(double theta, It first, It last, Gen&& random_generator = Gen{}) {
        assert(theta > 0);
        if (theta == 1.0) {
            uniform_random_permutation(first, last, std::forward<Gen>(random_generator));
        } else {
            impl::ewens_permutation_impl(theta, first, last, std::forward<Gen>(random_generator));
        }
    }

} // namespace prm

#endif // H_PRM_EWENSPERMUTATION_H
