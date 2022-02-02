//
//  valid_anagram.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/2.
//

#include "valid_anagram.hpp"
#include <string>
#include <vector>

using namespace std;

bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    vector<int> cnt(26, 0);
    for (char c : s) {
        int a = c - 'a';
        ++cnt[a];
    }
    for (char c : t) {
        int a = c - 'a';
        if (--cnt[a] < 0) {
            return false;
        }
    }
    for (int x : cnt) {
        if (x != 0) return false;
    }
    return true;
}
