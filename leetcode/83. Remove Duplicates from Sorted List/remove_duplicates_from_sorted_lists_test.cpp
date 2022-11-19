//
//  remove_duplicates_from_sorted_lists_test.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/2.
//

#include "remove_duplicates_from_sorted_lists_test.hpp"

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

void remove_duplicates_from_sorted_lists_test(void) {
    int a[] = {1,1,2};
    ListNode *list = createLinkedList(a, 3);
    list = deleteDuplicates(list);
}
