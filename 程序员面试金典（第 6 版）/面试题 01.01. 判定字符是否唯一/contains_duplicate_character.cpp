//
//  contains_duplicate_character.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/1.
//

#include "contains_duplicate_character.hpp"
#include <string>
#include <unordered_set>

using namespace std;
bool isUnique(string astr) {
    unordered_set<char> set;
    for (char c : astr) {
        if (set.find(c) != set.end()) {
            return false;
        }
        set.insert(c);
    }
    return true;
}
