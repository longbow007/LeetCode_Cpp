//
//  add_two_numbers.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/1/31.
//

#include "add_two_numbers.hpp"
#include "ListNode.hpp"
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int a,b = 0;
        ListNode *p1 = l1, *p2 = l2, *result = nullptr, *tail = nullptr;
        int incr = 0; // 进位值
        while (p1 != nullptr || p2 != nullptr) {
            a = (p1 != nullptr) ? p1->val : 0;
            b = (p2 != nullptr) ? p2->val : 0;
            int c = a + b + incr;
            if (c >= 10) {
                incr = c / 10;
            } else {
                incr = 0;
            }
            c = c % 10;
            ListNode *node = new ListNode(c, nullptr);
            if (result == nullptr) {
                result = node;
                tail = node;
            } else {
                tail->next = node;
                tail = tail->next;
            }
            if (p1 != nullptr) {
                p1 = p1->next;
            }
            if (p2 != nullptr) {
                p2 = p2->next;
            }
        }
        if (incr > 0) {
            ListNode *node = new ListNode(incr, nullptr);
            tail->next = node;
            tail = tail->next;
        }
        return result;
    }
};
