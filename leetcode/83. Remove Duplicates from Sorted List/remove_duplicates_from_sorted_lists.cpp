//
//  remove_duplicates_from_sorted_lists.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/2.
//

#include "remove_duplicates_from_sorted_lists.hpp"

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
