//
//  spin_array.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/4.
//

#include "spin_array.hpp"
#include <vector>

using namespace std;

int minArray(vector<int>& numbers) {
    for (int i = 0; i < numbers.size() - 1; i++) {
        if (numbers[i] > numbers[i+1]) {
            return numbers[i+1];
        }
    }
    return numbers[0];
}
