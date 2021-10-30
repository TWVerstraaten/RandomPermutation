//
// Created by pc on 30-10-21.
//

#ifndef H_PRM_EWENSPERMUTATION_H
#define H_PRM_EWENSPERMUTATION_H

#include "impl/EwensPermutationImpl.h"

namespace prm {

    template <class Gen = impl::UniformZeroOneGenerator>
    [[nodiscard]] std::vector<size_t> ewens_random_permutation(const double theta, const size_t n, Gen&& random_generator = Gen{}) {
        assert(theta > 0);
        if (theta == 1.0) {
            return uniform_random_permutation(n, std::forward<Gen>(random_generator));
        } else {
            return impl::ewens_permutation_impl<Gen>(theta, n, std::forward<Gen>(random_generator));
        }
    }

    template <class Gen>
    [[nodiscard]] std::map<size_t, size_t> ewens_partition(const double theta, const size_t n, Gen&& random_generator) {
        return impl::ewens_partition_impl<Gen>(theta, n, std::forward<Gen>(random_generator));
    }

} // namespace prm

#endif // H_PRM_EWENSPERMUTATION_H
