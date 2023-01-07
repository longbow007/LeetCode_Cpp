//
//  RepeatedDNASequences.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/12/27.
//

#include "RepeatedDNASequences.hpp"
#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

class RepeatedDNASequencesSolution {
public:
    char charForKey(int key) {
        unordered_map<int, char> map = {{0, 'A'}, {1, 'C'}, {2, 'G'}, {3, 'T'}};
        return map[key];
    }
    // key 为 20 bit 的数字
    string stringForKey(int key) {
        string s;
        int mask = 3;
        for (int i = 0; i < 10; i++) {
            int k = (key >> (9 - i) * 2) & mask;
            char c = charForKey(k);
            s.push_back(c);
        }
        return s;
    }
    vector<string> findRepeatedDnaSequences(string s) {
        int len = 10;
        long n = s.length();
        vector<string> res = {};
        if (n < len) {
            return res;
        }
        unordered_map<char, int> map = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
        int mask = 0xfffff;
        int x = map[s[0]];
        for (int i = 1; i < len; i++) {
            int key = map[s[i]];
            x = (x << 2) | key;
        }
        unordered_map<int, int> cntMap = {};
        cntMap[x] = 1;
        for (int j = len; j < s.size(); j++) {
            int key = map[s[j]];
            x = ((x << 2) | key) & mask;
            if (++cntMap[x] == 2) {
                string sub = s.substr(j - len + 1, len);
                res.push_back(sub);
            }
        }
        return res;
    }
};

void test_RepeatedDNASequences() {
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    RepeatedDNASequencesSolution *solution = new RepeatedDNASequencesSolution();
    auto res = solution->findRepeatedDnaSequences(s);
    for (string s : res) {
        cout<<s<<endl;
    }
}

