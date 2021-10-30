//
// Created by pc on 30-10-21.
//

#ifndef H_PRM_IMPL_EWENSPERMUTATIONIMPL_H
#define H_PRM_IMPL_EWENSPERMUTATIONIMPL_H

#include "../UniformPermutation.h"
#include "CopyIntoContainer.h"
#include "UniformZeroOneGenerator.h"

#include <cassert>
#include <map>

namespace prm::impl {

    template <class Gen>
    [[nodiscard]] std::map<size_t, size_t> sample_ewens_cycle_structure(const double theta, const size_t n, Gen&& random_generator) {
        std::map<size_t, size_t> bin_counts = {{1, 1}};
        size_t                   count      = 1;
        for (; count < n; ++count) {
            const double r = (static_cast<double>(count) + theta) * random_generator();
            if (r >= static_cast<double>(count)) {
                ++bin_counts[1];
            } else {
                size_t seen = 0;
                for (auto it = bin_counts.rbegin(); it != bin_counts.rend(); ++it) {
                    const auto [bin_size, bin_count] = *it;
                    seen += bin_size * bin_count;
                    if (r <= static_cast<double>(seen)) {
                        con::subtract_one_and_remove_if_empty(bin_counts, std::next(it).base());
                        con::add_or_insert_one_to_map(bin_counts, bin_size + 1);
                        break;
                    }
                }
            }
        }
        return bin_counts;
    }

    [[nodiscard]] std::vector<size_t> build_from_cycle_structure_and_random_permutation(const std::map<size_t, size_t>& cycle_structure, const std::vector<size_t>& uniform_permutation) {
        std::vector<size_t> result(uniform_permutation.size());
        size_t              index = 0;
        for (const auto [cycle_size, cycle_count] : cycle_structure) {
            if (cycle_size == 1) {
                for (; index != cycle_count; ++index) {
                    const auto one_cycle = uniform_permutation[index];
                    result[one_cycle]    = one_cycle;
                }
            } else {
                for (size_t j = 0; j != cycle_count; ++j) {
                    const auto start_of_cycle = uniform_permutation[index];
                    for (size_t i = 0; i != cycle_size - 1; ++i) {
                        result[uniform_permutation[index]] = uniform_permutation[index + 1];
                        ++index;
                    }
                    result[uniform_permutation[index]] = start_of_cycle;
                    ++index;
                }
            }
        }
        return result;
    }

    template <class Gen>
    [[nodiscard]] std::vector<size_t> ewens_permutation_impl(const double theta, const size_t n, Gen&& random_generator = Gen{}) {
        return build_from_cycle_structure_and_random_permutation(sample_ewens_cycle_structure(theta, n, std::forward<Gen>(random_generator)),
                                                                 uniform_random_permutation(n, std::forward<Gen>(random_generator)));
    }

    template <class It, class Gen>
    std::enable_if_t<std::is_same_v<typename std::iterator_traits<It>::iterator_category, std::random_access_iterator_tag>, void>
    ewens_permutation_impl(const double theta, It first, It last, Gen&& random_generator) {
        const size_t n                     = std::distance(first, last);
        const auto   reference_permutation = ewens_permutation_impl(theta, n, std::forward<Gen>(random_generator));

        std::vector<typename std::iterator_traits<It>::value_type> copy{first, last};

        for (size_t i = 0; i != n; ++i) {
            *(first + i) = copy[reference_permutation[i]];
        }
    }

    template <class It, class Gen>
    std::enable_if_t<!std::is_same_v<typename std::iterator_traits<It>::iterator_category, std::random_access_iterator_tag>, void>
    ewens_permutation_impl(const double theta, It first, It last, Gen&& random_generator) {
        std::vector<typename std::iterator_traits<It>::value_type> copy{first, last};
        ewens_permutation_impl(theta, copy.begin(), copy.end(), std::forward<Gen>(random_generator));
        std::copy(copy.begin(), copy.end(), first);
    }

} // namespace prm::impl

#endif // H_PRM_IMPL_EWENSPERMUTATIONIMPL_H
