//
//  fibonacci.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/4.
//

#include "fibonacci.hpp"

int fib(int n) {
    if (n < 2) return n;
    const int m = 1000000007;
    int p = 0, q = 1, r = 0;
    for (int i = 2; i <= n; i++) {
        r = (p + q) % m;
        p = q;
        q = r;
    }
    return r;
}
