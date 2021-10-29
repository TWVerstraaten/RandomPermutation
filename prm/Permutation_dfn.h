//
// Created by pc on 29-10-21.
//

#ifndef H_PRM_PERMUTATION_DFN_H
#define H_PRM_PERMUTATION_DFN_H

#include "impl/MallowsImpl.h"
#include "impl/MallowsQGreaterThenOneBase.h"
#include "impl/MallowsQLessThanOneBase.h"
#include "impl/UniformPermutationImpl.h"
#include "impl/UniformZeroOneGenerator.h"

#include <cassert>

namespace prm {

    template <class It, class Gen>
    void uniform_random_permutation(It first, It last, Gen&& random_generator) {
        impl::uniform_random_permutation_impl(first, last, random_generator);
    }

    template <class It, class Gen>
    void mallows_random_permutation(const double q, It first, It last, Gen&& random_generator) {
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

#endif // H_PRM_PERMUTATION_DFN_H
