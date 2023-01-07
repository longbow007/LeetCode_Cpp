//
//  HJ45.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2023/1/7.
//

#include "HJ45.hpp"
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int beautifulName(string s) {
    auto map = unordered_map<char, int>();
    for (char c : s) {
        map[c]++;
    }
    auto arr = vector<int>();
    for (auto it = map.begin(); it != map.end(); it++) {
        arr.push_back(it->second);
    }
    sort(arr.begin(), arr.end());
    int val = 26;
    int sum = 0;
    for (int i = arr.size() - 1; i >= 0; i--) {
        int n = arr[i];
        sum += n * val;
        val--;
    }
    return sum;
}

void test_beautifulName() {
    int n;
    cin>>n;
    while (n > 0) {
        string str;
        cout<<"Input: ";
        cin>>str;
        cout<<"Output: ";
        cout<<beautifulName(str)<<endl;
        cout<<endl;
        n--;
    }
}
