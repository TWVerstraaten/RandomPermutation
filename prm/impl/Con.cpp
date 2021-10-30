//
// Created by pc on 30-10-21.
//

#include "Con.h"

namespace prm::impl::con {

    std::vector<size_t> linear_vector(size_t n) {
        std::vector<size_t> result;
        result.reserve(n);
        for (size_t i = 0; i != n; ++i) {
            result.push_back(i);
        }
        return result;
    }

    void add_or_insert_one_into_map(std::map<size_t, size_t>& m, size_t key) {
        if (m.find(key) != m.end()) {
            ++m[key];
        } else {
            m.insert(std::make_pair(key, 1));
        }
    }

    void subtract_one_and_remove_if_empty(std::map<size_t, size_t>& m, std::map<size_t, size_t>::iterator it) {
        if (it->second > 1) {
            --it->second;
        } else {
            m.erase(it);
        }
    }
} // namespace prm::impl::con