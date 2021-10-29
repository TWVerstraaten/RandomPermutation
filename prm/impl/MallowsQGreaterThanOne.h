//
// Created by pc on 28-10-21.
//

#ifndef H_PRM_MALLOWSQGREATERTHANONE_H
#define H_PRM_MALLOWSQGREATERTHANONE_H

#include "MallowsBase.h"

namespace prm::impl {

    template <class It, class Gen>
    class MallowsQGreaterThanOne : private MallowsBase<It, Gen> {

      public:
        static void permute(const double q, It first, It last, Gen&& generator) {
            MallowsQGreaterThanOne<It, Gen> g(q, first, last, std::move(generator));
            g.do_permute();
        }

      private:
        MallowsQGreaterThanOne(const double q, It first, It last, Gen&& generator)
            : MallowsBase<It, Gen>(q, first, last, std::forward<Gen>(generator)),
              m_safe_power_limit(std::min(floor_of_non_negative(this->log_base_q(std::numeric_limits<double>::max()) - 1), this->m_unmatched)) {
            assert(this->m_q > 1.0);
        }

        void do_permute() {
            assert(this->m_q > 1);
            for (; this->m_first != this->m_last; ++this->m_first, --this->m_unmatched) {
                const size_t k = get_k();
                *this->m_first = this->m_copy[k];
                this->m_copy.erase(this->m_copy.begin() + k);
            }
        }

      private:
        [[nodiscard]] size_t get_k() {
            size_t k;
            if (this->m_unmatched <= m_safe_power_limit) {
                k = ceil_of_non_negative(this->log_base_q(1.0 - this->m_random_generator() * (1.0 - std::pow(this->m_q, this->m_unmatched))));
            } else {
                k = approximate_k();
            }
            return clamp(k, 1ul, this->m_unmatched) - 1;
        }

        [[nodiscard]] size_t approximate_k() {
            // log_q (1-r(1-q^u)) ~= log_q (1+rq^u) ~= log_q r + u
            const double log_r = std::ceil(this->log_base_q(this->m_random_generator()));
            if (-log_r > this->m_unmatched) {
                return 1;
            } else {
                return static_cast<size_t>(log_r + this->m_unmatched);
            }
        }

        const size_t m_safe_power_limit;
    };

} // namespace prm::impl

#endif // H_PRM_MALLOWSQGREATERTHANONE_H
