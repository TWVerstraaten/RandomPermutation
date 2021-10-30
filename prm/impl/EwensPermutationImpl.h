//
// Created by pc on 30-10-21.
//

#ifndef H_PRM_IMPL_EWENSPERMUTATIONIMPL_H
#define H_PRM_IMPL_EWENSPERMUTATIONIMPL_H

#include "../UniformPermutation.h"
#include "CopyIntoContainer.h"

#include <cassert>
#include <map>

namespace prm::impl {

    /*!
     * Random sample a Ewens partition as the cycle structure for a Ewens random permutation
     *
     * @tparam Gen Generator of random numbers in the range [0,1]
     * @param theta The parameter for the Ewens partition
     * @param n The number of elements to partition
     * @param random_generator Object such that random_generator() can be called producing a uniform random number in the range [0,1]
     * @return A cycle structure stored in an std::map<size_t, size_t>
     */
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
                        con::add_or_insert_one_into_map(bin_counts, bin_size + 1);
                        break;
                    }
                }
            }
        }
        return bin_counts;
    }

    /*!
     * Combine a cycle structure and a uniform random permutation into a random Ewens permutation
     *
     * @param cycle_structure The cycle structure
     * @param uniform_permutation The uniform random permutation
     * @return A permutation stored in a std::vector<size_t>
     */
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

    /*!
     * Returns a random permutation of {0,..,n-1}, distributed according to the Ewens distribution
     *
     * @tparam Gen Generator of random numbers in the range [0,1]
     * @param theta The parameter for the Ewens partition
     * @param n The number of elements to partition
     * @param random_generator Object such that random_generator() can be called producing a uniform random number in the range [0,1]
     * @return
     */
    template <class Gen>
    [[nodiscard]] std::vector<size_t> ewens_permutation_impl(const double theta, const size_t n, Gen&& random_generator = Gen{}) {
        return build_from_cycle_structure_and_random_permutation(sample_ewens_cycle_structure(theta, n, std::forward<Gen>(random_generator)),
                                                                 uniform_random_permutation(n, std::forward<Gen>(random_generator)));
    }

    /*!
     * Randomly permutes the elements in [first,last), distributed according to the Ewens distribution\n \n
     *
     * Random access iterator version
     *
     * @tparam It Random access iterator
     * @tparam Gen Uniform 0-1 random number generator type
     * @param theta The parameter for the Ewens partition
     * @param first Iterator at start of range
     * @param last iterator at end of range
     * @param random_generator Object such that random_generator() can be called producing a uniform random number in the range [0,1]
     * @return
     */
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

    /*!
     * Randomly permutes the elements in [first,last), distributed according to the Ewens distribution. \n \n
     *
     * Non random access iterator version. Here we first copy the range [first,last) into a vector.
     *
     * @tparam It Non random access iterator
     * @tparam Gen Uniform 0-1 random number generator type
     * @param theta The parameter for the Ewens partition
     * @param first Iterator at start of range
     * @param last iterator at end of range
     * @param random_generator Object such that random_generator() can be called producing a uniform random number in the range [0,1]
     * @return
     */
    template <class It, class Gen>
    std::enable_if_t<!std::is_same_v<typename std::iterator_traits<It>::iterator_category, std::random_access_iterator_tag>, void>
    ewens_permutation_impl(const double theta, It first, It last, Gen&& random_generator) {
        std::vector<typename std::iterator_traits<It>::value_type> copy{first, last};
        ewens_permutation_impl(theta, copy.begin(), copy.end(), std::forward<Gen>(random_generator));
        std::copy(copy.begin(), copy.end(), first);
    }

} // namespace prm::impl

#endif // H_PRM_IMPL_EWENSPERMUTATIONIMPL_H
