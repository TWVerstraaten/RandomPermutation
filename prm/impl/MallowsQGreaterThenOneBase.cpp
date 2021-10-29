//
// Created by pc on 29-10-21.
//

#include "MallowsQGreaterThenOneBase.h"

#include "Math.h"

namespace prm::impl {

    MallowsQGreaterThenOneBase::MallowsQGreaterThenOneBase(double q, size_t unmatched)
        : MallowsBase(q, unmatched), m_safe_power_limit(std::min(floor_of_non_negative(this->log_base_q(std::numeric_limits<double>::max()) - 1), this->m_unmatched)) {
    }

    size_t MallowsQGreaterThenOneBase::get_k(const double uniform_zero_one) const {
        size_t k;
        if (this->m_unmatched <= m_safe_power_limit) {
            k = ceil_of_non_negative(this->log_base_q(1.0 - uniform_zero_one * (1.0 - std::pow(this->m_q, this->m_unmatched))));
        } else {
            k = approximate_k(uniform_zero_one);
        }
        return clamp(k, 1ul, this->m_unmatched) - 1;
    }

    size_t MallowsQGreaterThenOneBase::approximate_k(const double uniform_zero_one) const {
        // log_q (1-r(1-q^u)) ~= log_q (1+rq^u) ~= log_q r + u
        const double log_r = std::ceil(log_base_q(uniform_zero_one));
        if (-log_r > static_cast<double>(m_unmatched)) {
            return 1;
        } else {
            return static_cast<size_t>(log_r) + m_unmatched;
        }
    }
} // namespace prm::impl
