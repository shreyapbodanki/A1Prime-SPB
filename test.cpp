// test.cpp
#include <cassert>
#include "prime.hpp"

static void compareConsistency(int lo, int hi) {
    for (int n = lo; n <= hi; ++n) {
        bool a = isPrimeHalf(n, nullptr);
        bool b = isPrimeSqrt(n, nullptr);
        assert(a == b);
    }
}

int main() {
    long long c = 0;

    c = 0; assert(isPrimeHalf(2, &c) == true && c == 0);
    c = 0; assert(isPrimeSqrt(2, &c) == true && c == 0);

    c = 0; assert(isPrimeHalf(3, &c) == true);
    c = 0; assert(isPrimeSqrt(3, &c) == true);

    c = 0; assert(isPrimeHalf(0, &c) == false && c == 0);
    c = 0; assert(isPrimeSqrt(0, &c) == false && c == 0);

    c = 0; assert(isPrimeHalf(1, &c) == false && c == 0);
    c = 0; assert(isPrimeSqrt(1, &c) == false && c == 0);

    c = 0; assert(isPrimeHalf(8, &c) == false && c == 0);
    c = 0; assert(isPrimeSqrt(8, &c) == false && c == 0);

    c = 0; assert(isPrimeHalf(9, &c) == false && c >= 1);
    c = 0; assert(isPrimeSqrt(9, &c) == false && c >= 1);

    compareConsistency(2, 200);

    long long halfOps = countModOps(&isPrimeHalf, 2, 1000);
    long long sqrtOps = countModOps(&isPrimeSqrt, 2, 1000);
    assert(sqrtOps <= halfOps);

    c = 0; assert(isPrimeHalf(-7, &c) == false && c == 0);
    c = 0; assert(isPrimeSqrt(-7, &c) == false && c == 0);

    return 0;
}
