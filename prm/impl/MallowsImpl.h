//
// Created by pc on 28-10-21.
//

#ifndef H_PRM_IMPL_MALLOWSIMPL_H
#define H_PRM_IMPL_MALLOWSIMPL_H

#include "CopyIntoContainer.h"
#include "MallowsQGreaterThenOneBase.h"
#include "MallowsQLessThanOneBase.h"

#include <cassert>

namespace prm::impl {

    template <class It, class Gen, class Base, class CopyCon>
    class MallowsImpl : private Base {

      public:
        static void permute(const double q, It first, It last, Gen&& generator) {
            MallowsImpl<It, Gen, Base, CopyCon> g(q, first, last, std::move(generator));
            g.do_permute();
        }

      private:
        MallowsImpl(double q, It first, It last, Gen&& generator) : Base(q, std::distance(first, last)), m_random_generator(std::move(generator)), m_copy_as_vector({first, last}) {
            assert(this->m_q != 1.0);
        }


        void do_permute() {
            for (; m_copy_as_vector.m_first != m_copy_as_vector.m_last; ++m_copy_as_vector.m_first, --this->m_unmatched) {
                const size_t k            = this->get_k(m_random_generator());
                auto         it           = std::next(m_copy_as_vector.m_copy.begin(), k);
                *m_copy_as_vector.m_first = *it;
                m_copy_as_vector.m_copy.erase(it);
            }
        }

        Gen                            m_random_generator;
        CopyIntoContainer<It, CopyCon> m_copy_as_vector;
    };

    template <class It, class Gen>
    using MallowsImplQGreaterThanOne = impl::MallowsImpl<It, Gen, impl::MallowsQGreaterThenOneBase, std::vector<typename It::value_type>>;

    template <class It, class Gen>
    using MallowsImplQLessThanOne = impl::MallowsImpl<It, Gen, impl::MallowsQLessThanOneBase, std::deque<typename It::value_type>>;

} // namespace prm::impl

#endif // H_PRM_IMPL_MALLOWSIMPL_H
