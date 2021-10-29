//
// Created by pc on 22-10-21.
//

#include "SpeedTest.h"

#include "../Permutation.h"

#include <chrono>
#include <iomanip>
#include <iostream>
#include <list>

using namespace std::chrono;

namespace prm::extra {

    void SpeedTest::mallows(double q) {
        size_t n = 100;
        std::cout << std::setw(20) << std::left << q;
        for (size_t j = 0; j != 6; ++j) {
            std::list<size_t> vec;
            for (size_t i = 0; i != n; ++i) {
                vec.push_back(i);
            }
            auto start = high_resolution_clock::now();
            for (size_t dummy = 0; dummy != 7; ++dummy) {
                prm::mallows_random_permutation(q, vec.begin(), vec.end());
            }
            auto stop     = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start) / 7;
            std::cout << std::setw(15) << std::left << duration.count() << "\t";
            n *= 10;
        }
        std::cout << "\n";
    }

} // namespace prm::extra
