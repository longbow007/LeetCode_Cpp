//
//  DuoZhuaYuTest.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/1/31.
//

#include "DuoZhuaYuTest.hpp"
#include <vector>
#include <iostream>
#include "DuoZhuaYu.hpp"

void duozhuayu_test(void) {
    // 多抓鱼
    std::vector<std::vector<int>> vect
    {
        {1,1,1,2},
        {2,1,2,2},
        {3,2,3,3}
    };
    int n = categoryOfMaxWarehouseAreaCpp(vect, 3, 4);
    std::cout << "result: " << n << std::endl;

//    int grid[3][4] = {{1,1,1,2}, {2,1,2,2}, {3,2,3,3}};
//    int *grid;
//    int colomn = 4;
//    categoryOfMaxWarehouseArea(&grid, 3, &colomn);

    int N = 7;
    int size;
    int *result = numberOfShelves(N, &size);
    printf("result: ");
    for (int idx = 0; idx < size; idx++) {
        printf("%d, ", result[idx]);
    }
    printf("\n");
}
