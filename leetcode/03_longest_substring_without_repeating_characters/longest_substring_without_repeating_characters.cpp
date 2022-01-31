//
//  longest_substring_without_repeating_characters.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/1/31.
//

#include "longest_substring_without_repeating_characters.hpp"
#include <unordered_set>

int lengthOfLongestSubstring(string s) {
    if (s.size() < 2) {
        return (int)s.size();
    }
    unordered_set<char> set;
    int j = 0, result = 0;
    set.insert(s[0]);
    for (int i = 0; i < s.size(); i++) {
        if (i > 0) {
            set.erase(s[i-1]);
        }
        while (j < s.size() - 1 && !set.count(s[j + 1])) {
            set.insert(s[j + 1]);
            j++;
        }
        result = max(result, j - i + 1);
    }
    return result;
}
