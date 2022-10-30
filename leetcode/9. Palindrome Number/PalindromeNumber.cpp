//
//  PalindromeNumber.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/10/29.
//

#include "PalindromeNumber.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class PalindromeNumberSolution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        string s = to_string(x);
        int n = s.size();
        int l = (n % 2 != 0) ? n / 2 : n / 2 - 1;
        int r = n / 2;
        while (l >= 0 && r < n && s[l] == s[r]) {
            l--;
            r++;
        }
        return (l == -1 && r == n);
    }
};

void testPalindromeNumber() {
    
}
