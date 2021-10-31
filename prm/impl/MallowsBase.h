//
// Created by pc on 29-10-21.
//

#ifndef H_PRM_IMPL_MALLOWSBASE_H
#define H_PRM_IMPL_MALLOWSBASE_H

#include <cmath>
#include <cstddef>

namespace prm::impl {

    /*! Base class containing some non template data members used in generating a Mallows permutation */
    class MallowsBase {

      protected:
        /*!
         * Constructor
         *
         * @param q The parameter used to generate the random Mallows permutation
         * @param number_of_elements Number of elements to permute
         */
        MallowsBase(double q, size_t number_of_elements);

        /*!
         * Returns log_q(x)
         *
         * @param x The argument
         * @return log_q(x)
         */
        [[nodiscard]]  double log_base_q(double x) const;

        /*! The parameter used to generate the random Mallows permutation */
        const double m_q;
        /*! log_q */
        const double m_log_q;
        /*! Number of elements unmatched during the stepwise generation of Mallows permutation. Initially equals total number of elements in the range */
        size_t m_unmatched;
    };

} // namespace prm::impl

#endif // H_PRM_IMPL_MALLOWSBASE_H
