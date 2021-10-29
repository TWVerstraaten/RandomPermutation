//
// Created by pc on 22-10-21.
//

#include "Tools.h"

namespace prm {

    size_t element_in_triangle(const std::vector<size_t>& p) {
        for (size_t i = 0; i != p.size(); ++i) {
            if (p[i] != i && (p[p[p[i]]] == i)) {
                return i;
            }
        }
        return std::numeric_limits<size_t>::max();
    }

    std::vector<size_t> a_cycle(const std::vector<size_t>& p) {
        size_t start = 0;
        while (p[start] == start) {
            ++start;
            if (start >= p.size()) {
                return {};
            }
        }

        std::vector<size_t> result;
        result.push_back(start);
        auto next = p[start];
        while (next != start) {
            result.push_back(next);
            next = p[next];
        }
        return result;
    }

    size_t number_of_one_cycles(const std::vector<size_t>& p) {
        size_t count = 0;
        for (size_t i = 0; i != p.size(); ++i) {
            if (p[i] == i) {
                ++count;
            }
        }
        return count;
    }

    size_t number_of_two_cycles(const std::vector<size_t>& p) {
        size_t count = 0;
        for (size_t i = 0; i != p.size(); ++i) {
            if (i < p[i] && p[p[i]] == i) {
                ++count;
            }
        }
        return count;
    }

} // namespace prm