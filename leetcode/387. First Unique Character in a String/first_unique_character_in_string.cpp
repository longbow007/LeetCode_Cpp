//
//  first_unique_character_in_string.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/2.
//

#include "first_unique_character_in_string.hpp"
#include <unordered_map>
#include <string>

using namespace std;

int firstUniqChar(string s) {
    unordered_map<char, int> map;
    for (char c : s) {
        ++map[c];
    }
    for (int i = 0; i < s.size(); i++) {
        if (map[s[i]] == 1) {
            return i;
        }
    }
    return -1;
}
