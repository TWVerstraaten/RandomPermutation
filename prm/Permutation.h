//
// Created by pc on 21-10-21.
//

#ifndef H_PRM_PERMUTATION_H
#define H_PRM_PERMUTATION_H

namespace prm {
    namespace impl {
        class UniformZeroOneGenerator;
    }

    /// Randomly permutes the elements in [first,last). Each possible permutation is (theoretically) equally likely to occur.
    ///
    /// \tparam first Iterator at start of range
    /// \tparam last iterator at end of range
    /// \tparam random_generator Object such that random_generator() can be called, which produces a uniform random number in the range [0,1]
    template <class It, class Gen = impl::UniformZeroOneGenerator>
    void uniform_random_permutation(It first, It last, Gen&& random_generator = Gen{});

    /// Randomly permutes the elements in [first,last) according to the Mallows distribution. A permutation p (theoretically) occurs with probability proportional to q^inv(p), where inv(p) counts the
    /// number of inversions in p.
    ///
    /// NOTA BENE: No comparisons of the elements in the range is made, instead, the initial (identity) ordering is inherited from simply the ordering in which the elements occur.
    ///
    /// \param q Parameter for Mallows permutation
    /// \tparam first Iterator at start of range
    /// \tparam last Iterator at end of range
    /// \tparam random_generator Object such that random_generator() can be called, which produces a uniform random number in the range [0,1]
    template <class It, class Gen = impl::UniformZeroOneGenerator>
    void mallows_random_permutation(double q, It first, It last, Gen&& random_generator = Gen{});

} // namespace prm

#include "Permutation_dfn.h"

#endif // H_PRM_PERMUTATION_H
