//
//  FindAllAnagramsInAString.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/11/19.
//

#include "FindAllAnagramsInAString.hpp"
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class FindAllAnagramsInAStringSolution {
public:
    vector<int> findAnagrams(string s, string p) {
        auto need = unordered_map<char, int>();
        for (auto c : p) {
            need[c]++;
        }
        auto window = unordered_map<char, int>();
        int left = 0, valid = 0;
        auto res = vector<int>();
        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            if (need.find(c) != need.end()) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid++;
                }
            }
            if (right - left >= p.size() - 1) {
                if (valid == need.size()) {
                    res.push_back(left);
                }
                char d = s[left];
                left++;
                if (need.find(d) != need.end()) {
                    if (need[d] == window[d]) {
                        valid--;
                    }
                    window[d]--;
                }
            }
        }
        return res;
    }
};
