//
// Created by pc on 29-10-21.
//

#ifndef H_PRM_IMPL_MALLOWSQLESSTHANONEBASE_H
#define H_PRM_IMPL_MALLOWSQLESSTHANONEBASE_H

#include "MallowsBase.h"

namespace prm::impl {

    /*! Base class for Mallows permutation implementation in the case q < 1 */
    class MallowsQLessThanOneBase : protected MallowsBase {

      protected:
        /*!
         * Constructor
         *
         * @param q The parameter used to generate the random Mallows permutation
         * @param number_of_elements Number of elements to permute
         */
        MallowsQLessThanOneBase(double q, size_t number_of_elements);

        /*!
         * Randomly select the index of the image of the current element to be assigned. If the remaining elements are j_0,j_1,...,j_{l-1}, then j_k will be selected.
         *
         * @param uniform_zero_one A (pseudo) random number in the range [0,1]
         * @return The index k
         */
        [[nodiscard]] size_t get_k(double uniform_zero_one) const;
    };

} // namespace prm::impl

#endif // H_PRM_IMPL_MALLOWSQLESSTHANONEBASE_H
