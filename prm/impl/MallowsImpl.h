//
// Created by pc on 28-10-21.
//

#ifndef H_PRM_IMPL_MALLOWSIMPL_H
#define H_PRM_IMPL_MALLOWSIMPL_H

#include "CopyAsVector.h"

#include <cassert>

namespace prm::impl {

    template <class It, class Gen, class Base>
    class MallowsImpl : private Base {

      public:
        static void permute(const double q, It first, It last, Gen&& generator) {
            MallowsImpl<It, Gen, Base> g(q, first, last, std::move(generator));
            g.do_permute();
        }

      private:
        MallowsImpl(double q, It first, It last, Gen&& generator) : Base(q, std::distance(first, last)), m_random_generator(std::move(generator)), m_copy_as_vector({first, last}) {
            assert(this->m_q != 1.0);
        }

        void do_permute() {
            for (; m_copy_as_vector.m_first != m_copy_as_vector.m_last; ++m_copy_as_vector.m_first, --this->m_unmatched) {
                const size_t k            = this->get_k(m_random_generator());
                *m_copy_as_vector.m_first = m_copy_as_vector.m_copy[k];
                m_copy_as_vector.m_copy.erase(m_copy_as_vector.m_copy.begin() + k);
            }
        }

        Gen              m_random_generator;
        CopyAsVector<It> m_copy_as_vector;
    };

} // namespace prm::impl

#endif // H_PRM_IMPL_MALLOWSIMPL_H
