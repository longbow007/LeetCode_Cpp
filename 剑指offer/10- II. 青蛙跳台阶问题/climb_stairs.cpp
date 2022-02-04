//
//  climb_stairs.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/4.
//

#include "climb_stairs.hpp"

int numWays(int n) {
    if (n < 2) return 1;
    const int m = 1000000007;
    int p = 1, q = 1, r = 0;
    for (int i = 2; i <= n; i++) {
        r = (p + q) % m;
        p = q;
        q = r;
    }
    return r;
}
