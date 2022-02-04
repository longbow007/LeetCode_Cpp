//
//  asteroid_collision.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/20.
//

#include "asteroid_collision.hpp"

using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> v;
    for (int y : asteroids) {
        while (!v.empty() && v.back() > 0 && v.back() < -y) {
            v.pop_back();
        }
        if (!v.empty() && v.back() > 0 && v.back() == -y) {
            v.pop_back();
        }
        else if (v.empty() || v.back() < 0 || y > 0) {
            v.emplace_back(y);
        }
    }
    return v;
}
