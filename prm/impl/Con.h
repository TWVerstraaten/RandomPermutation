//
// Created by pc on 30-10-21.
//

#ifndef H_PRM_IMPL_VECTORBUILDER_H
#define H_PRM_IMPL_VECTORBUILDER_H

#include <map>
#include <vector>

namespace prm::impl::con {

    /*!
     * Return a vector with contents {0,1,...,size-1}
     *
     * @param size Size of the vector
     * @return std::vector<size_t>{1,2,...,size-1}
     */
    [[nodiscard]] std::vector<size_t> linear_vector(size_t size);

    /*!
     * Increments map[key] if key exists in map, otherwise insert {key,1} into map
     *
     * @param map The map<size_t, size_t>
     * @param key The key
     */
    void add_or_insert_one_into_map(std::map<size_t, size_t>& map, size_t key);

    /*!
     * Subtract one from the element in the map pointer to by an it. Erase the iterator from map if it->second became.
     *
     * @param map The map<size_t, size_t>
     * @param it The iterator
     */
    void subtract_one_and_remove_if_now_zero(std::map<size_t, size_t>& map, std::map<size_t, size_t>::iterator it);

} // namespace prm::impl::con

#endif // H_PRM_IMPL_VECTORBUILDER_H
