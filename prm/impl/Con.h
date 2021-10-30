//
// Created by pc on 30-10-21.
//

#ifndef H_PRM_IMPL_VECTORBUILDER_H
#define H_PRM_IMPL_VECTORBUILDER_H

#include <map>
#include <vector>

namespace prm::impl::con {

    [[nodiscard]] std::vector<size_t> linear_vector(size_t n);

    void add_or_insert_one_to_map(std::map<size_t, size_t>& m, size_t key);

    void subtract_one_and_remove_if_empty(std::map<size_t, size_t>& m, std::map<size_t, size_t>::iterator it);

} // namespace prm::impl::con

#endif // H_PRM_IMPL_VECTORBUILDER_H
