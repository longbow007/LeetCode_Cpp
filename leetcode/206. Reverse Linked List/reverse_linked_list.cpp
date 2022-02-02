//
//  reverse_linked_list.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/2.
//

#include "reverse_linked_list.hpp"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
