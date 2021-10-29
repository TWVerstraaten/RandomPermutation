//
// Created by pc on 22-10-21.
//

#ifndef H_PRM_IMPL_MATH_H
#define H_PRM_IMPL_MATH_H

#include <cassert>
#include <cmath>
#include <cstddef>
#include <limits>

namespace prm {

    /// Clamp value to the range [min, max]
    /// \param value Value to clamp
    /// \param min Minimum
    /// \param max Maximum
    /// \return The clamped value
    template <typename T>
    inline T clamp(T value, T min, T max) {
        assert(min <= max);
        return value < min ? min : value > max ? max : value;
    }

    /// \param d Non-negative double
    /// \return The value d rounded down
    inline size_t floor_of_non_negative(const double d) {
        assert(d < static_cast<double>(std::numeric_limits<size_t>::max()));
        assert(d >= 0.0);
        return static_cast<size_t>(std::floor(d));
    }

    /// \param d Non-negative double
    /// \return The value d rounded up
    inline size_t ceil_of_non_negative(const double d) {
        assert(d < static_cast<double>(std::numeric_limits<size_t>::max()));
        assert(d >= 0.0);
        return static_cast<size_t>(std::ceil(d));
    }

} // namespace prm

#endif // H_PRM_IMPL_MATH_H
