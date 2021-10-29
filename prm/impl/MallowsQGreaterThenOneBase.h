//
// Created by pc on 29-10-21.
//

#ifndef H_PRM_IMPL_MALLOWSQGREATERTHENONEBASE_H
#define H_PRM_IMPL_MALLOWSQGREATERTHENONEBASE_H

#include "MallowsBase.h"

namespace prm::impl {

    class MallowsQGreaterThenOneBase : public MallowsBase {

      protected:
        MallowsQGreaterThenOneBase(double q, size_t unmatched);

        [[nodiscard]] size_t get_k(double uniform_zero_one) const;

      private:
        [[nodiscard]] size_t approximate_k(double uniform_zero_one) const;

        const size_t m_safe_power_limit;
    };

} // namespace prm::impl

#endif // H_PRM_IMPL_MALLOWSQGREATERTHENONEBASE_H
