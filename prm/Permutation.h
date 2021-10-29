//
// Created by pc on 21-10-21.
//

#ifndef H_PRM_PERMUTATION_H
#define H_PRM_PERMUTATION_H

#include "impl/MallowsImpl.h"
#include "impl/MallowsQGreaterThenOneBase.h"
#include "impl/MallowsQLessThanOneBase.h"
#include "impl/UniformPermutation.h"
#include "impl/UniformZeroOneGenerator.h"

#include <cassert>

namespace prm {

    template <class It, class Gen = impl::UniformZeroOneGenerator>
    void uniform_random_permutation(It first, It last, Gen&& random_generator = Gen{}) {
        impl::uniform_random_permutation_impl(first, last, random_generator);
    }

    template <class It, class Gen = impl::UniformZeroOneGenerator>
    void mallows_random_permutation(double q, It first, It last, Gen&& generator = Gen{}) {
        assert(q > 0);
        if (q == 1.0) {
            uniform_random_permutation(first, last, std::forward<Gen>(generator));
        } else if (q > 1.0) {
            impl::MallowsImpl<It, Gen, impl::MallowsQGreaterThenOneBase>::permute(q, first, last, std::forward<Gen>(generator));
        } else {
            impl::MallowsImpl<It, Gen, impl::MallowsQLessThanOneBase>::permute(q, first, last, std::forward<Gen>(generator));
        }
    }

} // namespace prm

#endif // H_PRM_PERMUTATION_H
