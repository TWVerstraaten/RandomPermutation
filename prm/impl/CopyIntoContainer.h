//
// Created by pc on 22-10-21.
//

#ifndef H_PRM_IMPL_COPYINTOCONTAINER_H
#define H_PRM_IMPL_COPYINTOCONTAINER_H

#include <deque>
#include <vector>

namespace prm::impl {

    template <class It, class Con>
    class CopyIntoContainer {

        template <class, class, class, class>
        friend class MallowsImpl;

      private:
        CopyIntoContainer(It first, It last) : m_first(first), m_last(last), m_copy({first, last}) {
        }

        It  m_first;
        It  m_last;
        Con m_copy;
    };
} // namespace prm::impl

#endif // H_PRM_IMPL_COPYINTOCONTAINER_H
