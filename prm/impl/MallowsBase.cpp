//
// Created by pc on 29-10-21.
//

#include "MallowsBase.h"

#include <cmath>

namespace prm::impl {

    MallowsBase::MallowsBase(const double q, size_t number_of_elements) : m_q(q), m_log_q(std::log(m_q)), m_unmatched(number_of_elements) {
    }

    double MallowsBase::log_base_q(const double x) const {
        return std::log(x) / m_log_q;
    }

} // namespace prm::impl