//
// Created by pc on 30-10-21.
//

#ifndef H_PRM_IMPL_VECTORBUILDER_H
#define H_PRM_IMPL_VECTORBUILDER_H

#include <map>
#include <vector>

namespace prm::impl::con {

    /*!
     * Return a vector with contents {0,1,...,n-1}
     *
     * @param n Size the vector
     * @return std::vector<size_t>{1,2,...,n-1}
     */
    [[nodiscard]] std::vector<size_t> linear_vector(size_t n);

    /*!
     * Increments m[key] if key exists in m, otherwise insert {key,1} into m
     *
     * @param m The map<size_t, size_t>
     * @param key The key
     */
    void add_or_insert_one_into_map(std::map<size_t, size_t>& m, size_t key);

    /*!
     * Subtract one from the element in the map pointer to by an it. Erase the iterator from map if it->second became.
     *
     * @param m The map<size_t, size_t>
     * @param it The iterator
     */
    void subtract_one_and_remove_if_empty(std::map<size_t, size_t>& m, std::map<size_t, size_t>::iterator it);

} // namespace prm::impl::con

#endif // H_PRM_IMPL_VECTORBUILDER_H
