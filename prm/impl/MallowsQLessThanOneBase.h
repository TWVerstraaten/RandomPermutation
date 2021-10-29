//
// Created by pc on 29-10-21.
//

#ifndef H_PRM_IMPL_MALLOWSQLESSTHANONEBASE_H
#define H_PRM_IMPL_MALLOWSQLESSTHANONEBASE_H

#include "MallowsBase.h"

namespace prm::impl {

    class MallowsQLessThanOneBase : protected MallowsBase {

      protected:
        MallowsQLessThanOneBase(double q, size_t unmatched);

      protected:
        [[nodiscard]] size_t get_k(double uniform_zero_one) const;
    };

} // namespace prm::impl

#endif // H_PRM_IMPL_MALLOWSQLESSTHANONEBASE_H
