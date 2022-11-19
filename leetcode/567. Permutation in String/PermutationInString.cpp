//
//  PermutationInString.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/11/19.
//

#include "PermutationInString.hpp"
#include <unordered_map>
#include <string>

using namespace std;

class PermutationInStringSolution {
public:
    bool checkInclusion(string s1, string s2) {
        auto need = unordered_map<char, int>();
        for (char c : s1) {
            need[c]++;
        }
        auto window = unordered_map<char, int>();
        int left = 0, valid = 0;
        for (int right = 0; right < s2.size(); right++) {
            char c = s2[right];
            if (need.find(c) != need.end()) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid++;
                }
            }
            if (right - left >= s1.size() - 1) {
                if (need.size() == valid) {
                    return true;
                }
                char d = s2[left];
                left++;

                if (need.find(d) != need.end()) {
                    if (window[d] == need[d]) {
                        valid--;
                    }
                    window[d]--;
                }
            }
        }
        return false;
    }
};
