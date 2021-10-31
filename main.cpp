#include "prm/MallowsPermutation.h"
#include "prm/extra/SpeedTest.h"

#include <forward_list>
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
    SpeedTest::ewens(0.02);
    SpeedTest::ewens(0.1);
    SpeedTest::ewens(0.5);
    SpeedTest::ewens(0.9);
    SpeedTest::ewens(0.99);
    SpeedTest::ewens(1.0);
    SpeedTest::ewens(1.1);
    SpeedTest::ewens(2.0);
    SpeedTest::ewens(40.0);
}
