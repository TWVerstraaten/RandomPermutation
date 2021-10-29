//
// Created by pc on 28-10-21.
//

#ifndef H_PRM_MALLOWSQLESSTHANONE_H
#define H_PRM_MALLOWSQLESSTHANONE_H

#include "MallowsBase.h"

namespace prm::impl {

    template <class It, class Gen>
    class MallowsQLessThanOne : private MallowsBase<It, Gen> {
      public:
        static void permute(const double q, It first, It last, Gen&& generator) {
            MallowsQLessThanOne<It, Gen> g(q, first, last, std::move(generator));
            g.do_permute();
        }

      private:
        MallowsQLessThanOne(const double q, It first, It last, Gen&& generator) : MallowsBase<It, Gen>(q, first, last, std::move(generator)) {
            assert(this->m_q < 1.0);
        }

        void do_permute() {
            assert(this->m_q < 1);
            for (; this->m_first != this->m_last; ++this->m_first, --this->m_unmatched) {
                const size_t k = clamp(ceil_of_non_negative(this->log_base_q(1.0 - this->m_random_generator() * (1.0 - std::pow(this->m_q, this->m_unmatched)))), 1ul, this->m_unmatched) - 1;
                *this->m_first = this->m_copy[k];
                this->m_copy.erase(this->m_copy.begin() + k);
            }
        }
    };

} // namespace prm::impl

#endif // H_PRM_MALLOWSQLESSTHANONE_H
