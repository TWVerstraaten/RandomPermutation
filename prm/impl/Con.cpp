//
// Created by pc on 30-10-21.
//

#include "Con.h"

namespace prm::impl::con {

    std::vector<size_t> linear_vector(size_t size) {
        std::vector<size_t> result;
        result.reserve(size);
        for (size_t i = 0; i != size; ++i) {
            result.push_back(i);
        }
        return result;
    }

    void add_or_insert_one_into_map(std::map<size_t, size_t>& map, const size_t key) {
        if (map.find(key) != map.end()) {
            ++map[key];
        } else {
            map.insert(std::make_pair(key, 1));
        }
    }

    void subtract_one_and_remove_if_now_zero(std::map<size_t, size_t>& map, std::map<size_t, size_t>::iterator it) {
        if (it->second > 1) {
            --it->second;
        } else {
            map.erase(it);
        }
    }
} // namespace prm::impl::con
