//
//  longest_substring_without_repeating_characters.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/1/31.
//

#include "longest_substring_without_repeating_characters.hpp"
#include <unordered_set>

//int lengthOfLongestSubstring(string s) {
//    if (s.size() < 2) {
//        return (int)s.size();
//    }
//    unordered_set<char> set;
//    int j = 0, result = 0;
//    set.insert(s[0]);
//    for (int i = 0; i < s.size(); i++) {
//        if (i > 0) {
//            set.erase(s[i-1]);
//        }
//        while (j < s.size() - 1 && !set.count(s[j + 1])) {
//            set.insert(s[j + 1]);
//            j++;
//        }
//        result = max(result, j - i + 1);
//    }
//    return result;
//}

int lengthOfLongestSubstring(string s) {
    if (s.size() < 2) {
        return s.size();
    }
    unordered_set<char> used;
    int left = 0, result = 1;
    used.insert(s[0]);
    for (int right = 1; right < s.size(); right++) {
        char c = s[right];
        if (used.find(c) == used.end()) {
            used.insert(c);
            result = max(result, right - left + 1);
            continue;
        }
        while (s[left] != s[right]) {
            used.erase(s[left]);
            left++;
        }
        left++;
    }
    return result;
}
