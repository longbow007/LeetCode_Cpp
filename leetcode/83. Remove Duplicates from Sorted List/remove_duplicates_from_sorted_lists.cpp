//
//  remove_duplicates_from_sorted_lists.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/2.
//

#include "remove_duplicates_from_sorted_lists.hpp"

ListNode *createLinkedList(int a[], int n) {
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

ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr) return head;
    ListNode *cur = head;
    while (cur->next != nullptr) {
        if (cur->val == cur->next->val) {
            cur->next = cur->next->next;
        } else {
            cur = cur->next;
        }
    }
    return head;
}
