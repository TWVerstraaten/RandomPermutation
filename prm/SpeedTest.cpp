//
// Created by pc on 22-10-21.
//

#include "SpeedTest.h"

#include "Permutation.h"

#include <chrono>
#include <iomanip>
#include <iostream>

using namespace std::chrono;

namespace prm {

    //        0.9                 67             	387            	3800           	36317          	378683         	4554884
    //        1.1                 53             	459            	4575           	44179          	445295         	5488754

    void SpeedTest::mallows(double q) {
        size_t n = 100;
        std::cout << std::setw(20) << std::left << q;
        for (size_t j = 0; j != 6; ++j) {
            std::vector<size_t> vec;
            for (size_t i = 0; i != n; ++i) {
                vec.push_back(i);
            }
            auto start = high_resolution_clock::now();
            prm::mallows_random_permutation(q, vec.begin(), vec.end());
            auto stop     = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            std::cout << std::setw(15) << std::left << duration.count() << "\t";
            n *= 10;
        }
        std::cout << "\n";
    }

} // namespace prm
