//
// Created by pc on 22-10-21.
//

#ifndef H_PRM_IMPL_COPYASVECTOR_H
#define H_PRM_IMPL_COPYASVECTOR_H

#include <vector>

namespace prm::impl {

    template <class It>
    class CopyAsVector {

        template <class, class, class>
        friend class MallowsImpl;

      private:
        CopyAsVector(It first, It last) : m_first(first), m_last(last), m_copy({first, last}) {
        }

        It                                   m_first;
        It                                   m_last;
        std::vector<typename It::value_type> m_copy;
    };
} // namespace prm::impl

#endif // H_PRM_IMPL_COPYASVECTOR_H
