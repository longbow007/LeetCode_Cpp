//
//  ranson_note.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/2.
//

#include "ranson_note.hpp"
#include "stdlib.h"
#include <string>

using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    int cnt[26];
    memset(cnt, 0, sizeof(cnt));
    for (char c : magazine) {
        int a = c - 'a';
        ++cnt[a];
    }
    for (char c : ransomNote) {
        int a = c - 'a';
        if (--cnt[a] < 0) {
            return false;
        }
    }
    return true;
}
