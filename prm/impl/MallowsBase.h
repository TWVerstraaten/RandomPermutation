//
// Created by pc on 22-10-21.
//

#ifndef H_PRM_MALLOWSBASE_H
#define H_PRM_MALLOWSBASE_H

#include "Math.h"
#include "UniformPermutation.h"

#include <cassert>
#include <deque>
#include <set>

namespace prm::impl {

    template <class It, class Gen>
    class MallowsBase {

        template <class, class>
        friend class MallowsQGreaterThanOne;
        template <class, class>
        friend class MallowsQLessThanOne;

        MallowsBase(const double q, It first, It last, Gen&& generator)
            : m_q(q), m_first(first), m_last(last), m_random_generator(std::move(generator)), m_unmatched(std::distance(m_first, m_last)), m_log_q(std::log(q)), m_copy({first, last}) {
            assert(q > 0.0);
            assert(q != 1.0);
        }

        [[nodiscard]] double log_base_q(double x) const {
            return std::log(x) / m_log_q;
        }

        const double                        m_q;
        It                                  m_first;
        It                                  m_last;
        Gen                                 m_random_generator;
        size_t                              m_unmatched;
        const double                        m_log_q;
        std::deque<typename It::value_type> m_copy;
    };
} // namespace prm::impl

#endif // H_PRM_MALLOWSBASE_H
