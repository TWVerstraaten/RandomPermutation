//
// Created by pc on 22-10-21.
//

#ifndef H_PRM_MATH_H
#define H_PRM_MATH_H

#include <cassert>
#include <cmath>
#include <cstddef>
#include <limits>

namespace prm {

    template <typename T>
    inline T clamp(T value, T min, T max) {
        assert(min <= max);
        return value < min ? min : value > max ? max : value;
    }

    inline size_t floor_of_non_negative(double d) {
        assert(d < static_cast<double>(std::numeric_limits<size_t>::max()));
        assert(d >= 0.0);
        return static_cast<size_t>(std::floor(d));
    }

    inline size_t ceil_of_non_negative(double d) {
        assert(d < static_cast<double>(std::numeric_limits<size_t>::max()));
        assert(d >= 0.0);
        return static_cast<size_t>(std::ceil(d));
    }

} // namespace prm

#endif // H_PRM_MATH_H
