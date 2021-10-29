//
// Created by pc on 22-10-21.
//

#ifndef H_PRM_IMPL_UNIFORMPERMUTATION_H
#define H_PRM_IMPL_UNIFORMPERMUTATION_H

#include "Math.h"

#include <algorithm>
#include <vector>

namespace prm::impl {

    template <class It>
    struct IsRandomAccessIterator {
        static const bool m_value = std::is_same_v<typename std::iterator_traits<It>::iterator_category, std::random_access_iterator_tag>;
    };

    template <class It, class Gen>
    std::enable_if_t<IsRandomAccessIterator<It>::m_value, void> uniform_random_permutation_impl(It first, It last, Gen&& random_generator) {
        // Permute in place
        auto unmatched = std::distance(first, last);
        for (; unmatched > 1; ++first, --unmatched) {
            const auto k = floor_of_non_negative(unmatched * random_generator());
            std::swap(*first, *(first + k)); // This is too expensive for list or forward_list
        }
    }

    template <class It, class Gen>
    std::enable_if_t<!IsRandomAccessIterator<It>::m_value, void> uniform_random_permutation_impl(It first, It last, Gen&& random_generator) {
        // Copy first into deque, which can be permuted quickly
        std::vector<typename It::value_type> copy{first, last};
        uniform_random_permutation_impl(copy.begin(), copy.end(), std::forward<Gen>(random_generator));
        std::copy(copy.begin(), copy.end(), first);
    }

} // namespace prm::impl

#endif // H_PRM_IMPL_UNIFORMPERMUTATION_H
