//
//  reverse_print_linked_list.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/4.
//

#include "reverse_print_linked_list.hpp"
#include <vector>
#include <stack>
#include "ListNode.hpp"

using namespace std;

vector<int> reversePrint(ListNode* head) {
    // 数组
    // vector<int> result;
    // ListNode *p = head;
    // while (p != nullptr) {
    //     result.emplace(result.begin(), p->val);
    //     p = p->next;
    // }
    // return result;
    
    // stack
    stack<ListNode *> stk;
    ListNode *p = head;
    while (p != nullptr) {
        stk.push(p);
        p = p->next;
    }
    vector<int> result;
    while (!stk.empty()) {
        result.emplace_back(stk.top()->val);
        stk.pop();
    }
    return result;
}
