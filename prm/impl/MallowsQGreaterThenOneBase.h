//
// Created by pc on 29-10-21.
//

#ifndef H_PRM_IMPL_MALLOWSQGREATERTHENONEBASE_H
#define H_PRM_IMPL_MALLOWSQGREATERTHENONEBASE_H

#include "MallowsBase.h"

namespace prm::impl {

    /// Base class for Mallows permutation implementation in the case q > 1
    class MallowsQGreaterThenOneBase : public MallowsBase {

      protected:
        /// \param q The parameter used to generate the random Mallows permutation
        /// \param number_of_elements Number of elements to permute
        MallowsQGreaterThenOneBase(double q, size_t unmatched);

        /// Randomly select the index of the image of the current element to be assigned. If the remaining elements are j_1,j_2,...,j_l, then j_k will be selected.
        ///
        /// \param uniform_zero_one A (pseudo) random number in the range [0,1]
        /// \return The index k
        [[nodiscard]] size_t get_k(double uniform_zero_one) const;

      private:
        /// When get_k will over_flow or under_flow, use this approximation instead
        ///
        /// \param uniform_zero_one A (pseudo) random number in the range [0,1]
        /// \return The index k
        [[nodiscard]] size_t approximate_k(double uniform_zero_one) const;

        /// The largest integer s such that q^s fits in a size_t
        const size_t m_safe_power_limit;
    };

} // namespace prm::impl

#endif // H_PRM_IMPL_MALLOWSQGREATERTHENONEBASE_H
