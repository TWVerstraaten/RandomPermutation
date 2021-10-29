//
// Created by pc on 29-10-21.
//

#include "MallowsBase.h"

#include <cmath>

namespace prm::impl {

    MallowsBase::MallowsBase(const double q, size_t unmatched) : m_q(q), m_log_q(std::log(m_q)), m_unmatched(unmatched) {
    }

} // namespace prm::impl