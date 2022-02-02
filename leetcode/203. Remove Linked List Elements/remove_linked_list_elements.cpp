//
//  remove_linked_list_elements.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/2.
//

#include "remove_linked_list_elements.hpp"

ListNode *createLinkedList2(int a[], int n) {
    ListNode *head = nullptr;
    if (n <= 0) return head;
    ListNode *pre = nullptr;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            head = new ListNode(a[i], nullptr);
            pre = head;
        } else {
            ListNode *node = new ListNode(a[i], nullptr);
            pre->next = node;
            pre = pre->next;
        }
    }
    return head;
}

ListNode* removeElements(ListNode* head, int val) {
    if (head == nullptr) return head;
    ListNode *result = new ListNode(0, head);
    ListNode *p = result;
    while (p->next != nullptr) {
        if (p->next->val == val) {
            p->next = p->next->next;
        } else {
            p = p->next;
        }
    }
    ListNode *d = result;
    result = result->next;
    delete d;
    return result;
}
