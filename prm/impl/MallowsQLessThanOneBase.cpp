//
// Created by pc on 29-10-21.
//

#include "MallowsQLessThanOneBase.h"

#include "Math.h"

#include <cmath>

namespace prm::impl {

    MallowsQLessThanOneBase::MallowsQLessThanOneBase(double q, size_t number_of_elements) : MallowsBase(q, number_of_elements) {
    }

    size_t MallowsQLessThanOneBase::get_k(const double uniform_zero_one) const {
        return math::clamp(math::ceil_of_non_negative(log_base_q(1.0 - uniform_zero_one * (1.0 - std::pow(m_q, m_unmatched)))), 1ul, m_unmatched) - 1;
    }

} // namespace prm::impl