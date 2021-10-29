//
// Created by pc on 29-10-21.
//

#include "MallowsQLessThanOneBase.h"

#include "Math.h"

#include <cmath>

namespace prm::impl {

    MallowsQLessThanOneBase::MallowsQLessThanOneBase(double q, size_t unmatched) : MallowsBase(q, unmatched) {
    }

    size_t MallowsQLessThanOneBase::get_k(const double uniform_zero_one) const {
        return clamp(ceil_of_non_negative(log_base_q(1.0 - uniform_zero_one * (1.0 - std::pow(m_q, m_unmatched)))), 1ul, m_unmatched) - 1;
    }

} // namespace prm::impl