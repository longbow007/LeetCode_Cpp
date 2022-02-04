//
//  number_of_1_bits.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/4.
//

#include "number_of_1_bits.hpp"
#include <stdint.h>

int hammingWeight(uint32_t n) {
    int cnt = 0;
    for (int i = 0; i < 32; i++) {
        if (n & (1 << i)) {
            cnt++;
        }
    }
    return cnt;
}
