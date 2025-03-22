//
//  reverse_list.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/4.
//

#include "reverse_list.hpp"
#include "ListNode.hpp"

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *p = head, *q = head->next;
        p->next = nullptr;
        while (q != nullptr) {
            ListNode *r = q->next;
            q->next = p;
            p = q;
            q = r;
        }
        return p;
    }
};
