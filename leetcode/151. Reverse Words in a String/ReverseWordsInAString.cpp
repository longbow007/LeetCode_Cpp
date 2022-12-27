//
//  ReverseWordsInAString.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/12/27.
//

#include "ReverseWordsInAString.hpp"
#include <string>

using namespace std;

class ReverseWordsInAStringSolution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int n = s.size();
        int idx = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != ' ') {
                if (idx != 0) {
                    s[idx++] = ' ';
                }
                int j = i;
                while (s[j] != ' ' && j < n) {
                    s[idx++] = s[j++];
                }
                reverse(s.begin() + idx - (j - i), s.begin() + idx);
                i = j;
            }
        }
        s.erase(s.begin() + idx, s.end());
        return s;
    }
};
