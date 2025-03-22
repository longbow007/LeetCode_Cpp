//
//  reverse_linked_list.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/2.
//

#include "reverse_linked_list.hpp"
#include "ListNode.hpp"

ListNode* reverseList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    // 递归法
//    ListNode *p = reverseList(head->next);
//    head->next->next = head;
//    head->next = nullptr;
//    return p;

    // 指针法
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
