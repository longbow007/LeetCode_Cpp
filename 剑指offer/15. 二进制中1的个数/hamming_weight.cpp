//
//  hamming_weight.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/4.
//

#include "hamming_weight.hpp"
#include <stdint.h>

class HammingWeightSolution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        for (int i = 0; i < 32; i++) {
            if (n & (1 << i)) {
                cnt++;
            }
        }
        return cnt;
    }
};
