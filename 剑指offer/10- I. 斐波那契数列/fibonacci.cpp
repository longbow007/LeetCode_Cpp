//
//  fibonacci.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/4.
//

#include "fibonacci.hpp"
#include <iostream>
#include <vector>

using namespace std;

// dp 经典解法
int helper(int n, vector<int>& v) {
    if (n <= 0) return 0;
    if (n <= 2) return 1;
    int fn = v[n];
    if (fn > 0) return fn;
    fn = helper(n - 1, v) + helper(n - 2, v);
    fn = fn % 1000000007;
    v[n] = fn;
    return fn;
}

int fib(int n) {
    vector<int> v = vector(n + 1, -1);
    return helper(n, v);
}

// 循环法
//int fib(int n) {
//    if (n < 2) return n;
//    const int m = 1000000007;
//    int p = 0, q = 1, r = 0;
//    for (int i = 2; i <= n; i++) {
//        r = (p + q) % m;
//        p = q;
//        q = r;
//    }
//    return r;
//}
