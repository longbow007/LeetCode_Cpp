//
//  ContainerWithMostWater.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/10/29.
//

#include "ContainerWithMostWater.hpp"
#include <vector>

using namespace std;

class ContainerWithMostWaterSolution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int result = 0;
        while (i < j) {
            int area = (j - i) * min(height[i], height[j]);
            result = max(area, result);
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return result;
    }
};
