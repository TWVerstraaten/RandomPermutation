//
// Created by pc on 22-10-21.
//

#ifndef H_PRM_IMPL_COPYINTOCONTAINER_H
#define H_PRM_IMPL_COPYINTOCONTAINER_H

#include <deque>
#include <vector>

namespace prm::impl {
    /*!
     * Class that stores a copy of an iterator range into a given container
     *
     * \tparam It Input iterator type
     * \tparam Con Container type to store copy in
     */
    template <class It, class Con>
    class CopyIntoContainer {

        template <class, class, class, class>
        friend class MallowsPermutationImpl;
        template <class, class>
        friend class EwensImpl;
        template <class I, class Gen>
        friend void ewens_permutation_impl(double theta, I first, I last, Gen&& random_generator);

      private:
        /*!
         * Constructor
         *
         * \param first Iterator at start of range
         * \param last iterator at end of range
         */
        CopyIntoContainer(It first, It last) : m_first(first), m_last(last), m_copy({first, last}) {
        }

        /*! Iterator at start of range */
        It m_first;
        /*! iterator at end of range */
        It m_last;
        /*! Container containing the copy */
        Con m_copy;
    };

    template <class It>
    using CopyIntoVector = CopyIntoContainer<It, std::vector<typename std::iterator_traits<It>::value_type>>;

    template <class It>
    using CopyIntoDeque = CopyIntoContainer<It, std::deque<typename std::iterator_traits<It>::value_type>>;

} // namespace prm::impl

#endif // H_PRM_IMPL_COPYINTOCONTAINER_H
