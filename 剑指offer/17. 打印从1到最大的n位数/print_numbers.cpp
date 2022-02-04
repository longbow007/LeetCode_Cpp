//
//  print_numbers.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/4.
//

#include "print_numbers.hpp"
#include <vector>
#include <numeric>

using namespace std;

class PrintNumbersSolution {
public:
    vector<int> printNumbers(int n) {
        if (n == 0) return {};
        // 常规解法
        // int maxNum = pow(10, n);
        // vector<int> v(maxNum - 1);
        // for (int i = 0; i < maxNum - 1; i++) {
        //     v[i] = i + 1;
        // }
        // return v;

        // 利用内置函数 iota()
        vector<int> v(pow(10,n) - 1);
        iota(begin(v), end(v), 1);
        return v;
    }
};
