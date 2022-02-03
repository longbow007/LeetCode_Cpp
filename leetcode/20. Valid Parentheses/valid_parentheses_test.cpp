//
//  valid_parentheses_test.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/2.
//

#include "valid_parentheses_test.hpp"
#include "valid_parentheses.hpp"
#include <string>

using namespace std;

void valid_parentheses_test(void) {
    string s("(]");
    bool valid = isValid(s);
    printf("%d", valid ? 1 : 0);
}
