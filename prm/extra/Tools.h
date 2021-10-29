//
// Created by pc on 22-10-21.
//

#ifndef H_PRM_EXTRA_TOOLS_H
#define H_PRM_EXTRA_TOOLS_H

#include <cstddef>
#include <iterator>
#include <limits>
#include <vector>

namespace prm::extra {

    size_t element_in_triangle(const std::vector<size_t>& p);

    std::vector<size_t> a_cycle(const std::vector<size_t>& p);

    size_t number_of_one_cycles(const std::vector<size_t>& p);

    size_t number_of_two_cycles(const std::vector<size_t>& p);

    template <typename It>
    size_t number_of_inversions(It first, It last) {
        if (first == last || std::next(first) == last) {
            return 0;
        }
        size_t     count = 0;
        const auto begin = first;
        ++first;
        for (; first != last; ++first) {
            for (auto smaller = begin; smaller != first; ++smaller) {
                if (*smaller > *first) {
                    ++count;
                }
            }
        }
        return count;
    }

} // namespace prm::extra

#endif // H_PRM_EXTRA_TOOLS_H
