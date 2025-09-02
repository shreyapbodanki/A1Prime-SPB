//prime.cpp
#include "prime.hpp"

static inline void bump(long long* p) { if (p) (*p)++; }

bool isPrimeHalf(int n, long long* modOps) {
    if (n < 2) return false;
    if (n == 2) return true;
    if ((n & 1) == 0) return false;
    for (int d = 3; d <= n / 2; d += 2) {
        bump(modOps);
        if (n % d == 0) return false;
    }
    return true;
}

bool isPrimeSqrt(int n, long long* modOps) {
    if (n < 2) return false;
    if (n == 2) return true;
    if ((n & 1) == 0) return false;
    for (int d = 3; 1LL * d * d <= n; d += 2) {
        bump(modOps);
        if (n % d == 0) return false;
    }
    return true;
}

long long countModOps(PrimeFn isPrime, int lo, int hi) {
    if (lo > hi) { int t = lo; lo = hi; hi = t; }
    if (hi < 2) return 0;
    if (lo < 2) lo = 2;

    long long total = 0;
    for (int x = lo; x <= hi; ++x) {
        long long local = 0;
        (void)isPrime(x, &local);
        total += local;
    }
    return total;
}

