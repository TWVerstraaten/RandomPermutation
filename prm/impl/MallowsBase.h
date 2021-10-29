//
// Created by pc on 29-10-21.
//

#ifndef H_PRM_IMPL_MALLOWSBASE_H
#define H_PRM_IMPL_MALLOWSBASE_H

#include <cmath>
#include <cstddef>

namespace prm::impl {

    class MallowsBase {

      protected:
        MallowsBase(double q, size_t unmatched);

        [[nodiscard]] inline double log_base_q(double x) const {
            return std::log(x) / m_log_q;
        }

        const double m_q;
        const double m_log_q;
        size_t       m_unmatched;
    };

} // namespace prm::impl

#endif // H_PRM_IMPL_MALLOWSBASE_H
