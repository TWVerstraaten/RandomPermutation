#include "prm/Permutation.h"
#include "prm/SpeedTest.h"
#include "prm/Tools.h"

#include <chrono>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>

using namespace std::chrono;

template <class It>
void print_vector(It first, It last) {
    while (first != last) {
        std::cout << *first << "\t";
        ++first;
    }
    std::cout << "\n";
}

template <class A>
class B : A {};

int main() {

    //        1.1                 61             	441            	4205           	42851          	434889         	5193953
    //        2                   48             	2927           	3679           	36950          	398673         	4392813
    //        40                  72             	4358           	4285           	43251          	397211         	3525406

    //    prm::SpeedTest::mallows(0.1);
    //    prm::SpeedTest::mallows(0.5);
    //    prm::SpeedTest::mallows(0.9);
    //    prm::SpeedTest::mallows(1.0);
    prm::SpeedTest::mallows(1.1);
    prm::SpeedTest::mallows(2.0);
    prm::SpeedTest::mallows(40.0);

    //    double d = 0.01;
    //    size_t n = 10000;
    //    for (size_t du = 0; du != 99; ++du) {
    //        size_t count = 0;
    //        for (size_t repeat = 0; repeat != 10; ++repeat) {
    //            std::vector<size_t> vec;
    //            for (size_t i = 0; i != n; ++i) {
    //                vec.push_back(i);
    //            }
    //            prm::mallows_random_permutation(1 + d, vec.begin(), vec.end());
    //            count += prm::number_of_one_cycles(vec);
    //        }
    //        //        std::cout << static_cast<double>(count) / 10.0 << "\t" << static_cast<double>(count) / (10.0 * n) << "\n";
    //        std::cout << n << "\t" << static_cast<double>(count) << "\n";
    //        n *= 2;
    //        //        d += 0.01;
    //    }

    //
    //    size_t counter = 200000;
    //    while (--counter) {
    //        prm::mallows_random_permutation(11.1, vec.begin(), vec.end());
    //        std::cout << counter << "\n";
    //
    //        const size_t before = prm::number_of_inversions(vec.begin(), vec.end());
    //        const auto   copy   = vec;
    //        size_t       repl   = 0;
    //        for (size_t i = 0; i != vec.size(); ++i) {
    //            if (vec[i] == i || vec[vec[i]] == i) {
    //                continue;
    //            } else {
    //                vec[i] = i;
    //                ++repl;
    //            }
    //        }
    //        const size_t after = prm::number_of_inversions(vec.begin(), vec.end());
    //        assert(before >= after + repl / 2);
    //    }

    //    prm::SpeedTest::mallows(.01);
    //    prm::SpeedTest::mallows(.1);
    //    prm::SpeedTest::mallows(.5);
    //    prm::SpeedTest::mallows(1);
    //    prm::SpeedTest::mallows(1.01);
    //    prm::SpeedTest::mallows(2.01);
    //    prm::SpeedTest::mallows(5.01);
    //    prm::SpeedTest::mallows(20.0);
    //    prm::SpeedTest::mallows(200.0);
}
