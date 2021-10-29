//
// Created by pc on 21-10-21.
//

#ifndef H_PRM_PERMUTATION_H
#define H_PRM_PERMUTATION_H

namespace prm {
    namespace impl {
        class UniformZeroOneGenerator;
    }

    template <class It, class Gen = impl::UniformZeroOneGenerator>
    void uniform_random_permutation(It first, It last, Gen&& random_generator = Gen{});

    template <class It, class Gen = impl::UniformZeroOneGenerator>
    void mallows_random_permutation(double q, It first, It last, Gen&& random_generator = Gen{});

} // namespace prm

#include "Permutation_dfn.h"

#endif // H_PRM_PERMUTATION_H
