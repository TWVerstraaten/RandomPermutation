#include "prm/EwensPermutation.h"

#include <iostream>

template <class It>
void print_vector(It first, It last) {
    while (first != last) {
        std::cout << *first << "\t";
        ++first;
    }
    std::cout << "\n";
}

int main() {

    auto       start    = high_resolution_clock::now();
    const auto v        = prm::ewens_random_permutation(1.1, 100000, prm::impl::UniformZeroOneGenerator{1234});
    auto       stop     = high_resolution_clock::now();
    auto       duration = duration_cast<microseconds>(stop - start) / 7;
    std::cout << std::setw(15) << std::left << duration.count() << "\t";

    //    print_vector(v.begin(), v.end());

    //    using namespace prm;
    //    using namespace prm::extra;

    //    SpeedTest::mallows(0.02);
    //    SpeedTest::mallows(0.1);
    //    SpeedTest::mallows(0.5);
    //    SpeedTest::mallows(0.9);
    //    SpeedTest::mallows(0.99);
    //    SpeedTest::mallows(1.0);
    //    SpeedTest::mallows(1.1);
    //    SpeedTest::mallows(2.0);
    //    SpeedTest::mallows(40.0);
}
