//
// Created by pc on 28-10-21.
//

#ifndef H_PRM_IMPL_MALLOWSPERMUTATIONIMPL_H
#define H_PRM_IMPL_MALLOWSPERMUTATIONIMPL_H

#include "CopyIntoContainer.h"
#include "MallowsQGreaterThenOneBase.h"
#include "MallowsQLessThanOneBase.h"

#include <cassert>

namespace prm::impl {
    /*!
     * Implementation of Mallows permutation
     *
     * @tparam It Iterator type of input
     * @tparam Gen Generator of random numbers in the range [0,1]
     * @tparam Base Can be either MallowsQGreaterThenOneBase or MallowsQLessThanOneBase
     * @tparam Copy Type of container into which the range will be copied
     */
    template <class It, class Gen, class Base, class Copy>
    class MallowsPermutationImpl : private Base {

      public:
        /*!
         * Static function that does the permutation
         *
         * @param q The parameter used to generate the random Mallows permutation
         * @param first Iterator at start of range
         * @param last iterator at end of range
         * @param random_generator Object such that random_generator() can be called, which produces a uniform random number in the range [0,1]
         */
        static void permute(const double q, It first, It last, Gen&& generator) {
            MallowsPermutationImpl<It, Gen, Base, Copy> g(q, first, last, std::move(generator));
            g.do_permute();
        }

      private:
        /*!
         * Constructor
         *
         * @param q The parameter used to generate the random Mallows permutation
         * @param first Iterator at start of range
         * @param last iterator at end of range
         * @param random_generator Object such that random_generator() can be called, which produces a uniform random number in the range [0,1]
         */
        MallowsPermutationImpl(double q, It first, It last, Gen&& generator) : Base(q, std::distance(first, last)), m_random_generator(std::move(generator)), m_copiedContainer({first, last}) {
            assert(this->m_q != 1.0);
        }

        /*! Perform the permutation. All the relevant data is stored in the data members at this point */
        void do_permute() {
            for (; m_copiedContainer.m_first != m_copiedContainer.m_last; ++m_copiedContainer.m_first, --this->m_unmatched) {
                const size_t k             = this->get_k(m_random_generator());
                auto         it            = std::next(m_copiedContainer.m_copy.begin(), k);
                *m_copiedContainer.m_first = *it;
                m_copiedContainer.m_copy.erase(it);
            }
        }

        /*! Object such that random_generator() can be called, which produces a uniform random number in the range [0,1] */
        Gen m_random_generator;
        /*! Object containing the copied range */
        Copy m_copiedContainer;
    };

    template <class It, class Gen>
    using MallowsImplQGreaterThanOne = impl::MallowsPermutationImpl<It, Gen, impl::MallowsQGreaterThenOneBase, impl::CopyIntoVector<It>>;

    template <class It, class Gen>
    using MallowsImplQLessThanOne = impl::MallowsPermutationImpl<It, Gen, impl::MallowsQLessThanOneBase, impl::CopyIntoDeque<It>>;

} // namespace prm::impl

#endif // H_PRM_IMPL_MALLOWSPERMUTATIONIMPL_H
