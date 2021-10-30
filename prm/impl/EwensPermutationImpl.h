//
// Created by pc on 30-10-21.
//

#ifndef H_PRM_IMPL_EWENSPERMUTATIONIMPL_H
#define H_PRM_IMPL_EWENSPERMUTATIONIMPL_H

#include "../UniformPermutation.h"
#include "UniformZeroOneGenerator.h"

#include <cassert>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <map>

using namespace std::chrono;

namespace prm::impl {

    template <class Gen>
    [[nodiscard]] std::map<size_t, size_t> ewens_partition_impl(const double theta, const size_t n, Gen&& random_generator) {
        std::map<size_t, size_t> bin_counts = {{1, 1}};
        size_t                   count      = 1;
        while (count < n) {
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
            ++count;
        }
        return bin_counts;
    }

    template <class Gen>
    [[nodiscard]] std::vector<size_t> ewens_permutation_impl(const double theta, const size_t n, Gen&& random_generator = Gen{}) {
        const auto cycle_structure     = ewens_partition_impl(theta, n, std::forward<Gen>(random_generator));
        const auto uniform_permutation = ::prm::uniform_random_permutation(n, std::forward<Gen>(random_generator));

        std::vector<size_t> result;
        result.resize(n);
        size_t index = 0;
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

} // namespace prm::impl

#endif // H_PRM_IMPL_EWENSPERMUTATIONIMPL_H
