//
//  asteroid_collision_test.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/20.
//

#include "asteroid_collision_test.hpp"
#include <iostream>

using namespace std;

void asteroid_collision_test(void) {
    vector<int> asteroids = {5,10,-5};
    vector<int> res = asteroidCollision(asteroids);
    cout<<endl;
}
