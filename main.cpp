#include "prm/Permutation.h"
#include "prm/extra/SpeedTest.h"
#include "prm/extra/Tools.h"

#include <deque>
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
    using namespace prm;
    using namespace prm::extra;

    SpeedTest::mallows(0.02);
    SpeedTest::mallows(0.1);
    SpeedTest::mallows(0.5);
    SpeedTest::mallows(0.9);
    SpeedTest::mallows(0.99);
    SpeedTest::mallows(1.0);
    SpeedTest::mallows(1.1);
    SpeedTest::mallows(2.0);
    SpeedTest::mallows(40.0);
}
