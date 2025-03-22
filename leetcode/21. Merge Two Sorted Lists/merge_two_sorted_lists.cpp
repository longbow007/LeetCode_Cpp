//
//  merge_two_sorted_lists.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/2.
//

#include "merge_two_sorted_lists.hpp"
#include "ListNode.hpp"

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (list1 == nullptr) return list2;
    if (list2 == nullptr) return list1;
    ListNode *result = new ListNode(-1);
    ListNode *p = result;
    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val < list2->val) {
            p->next = list1;
            list1 = list1->next;
        } else {
            p->next = list2;
            list2 = list2->next;
        }
        p = p->next;
    }
    p->next = (list1 == nullptr) ? list2 : list1;
    p = result;
    result = result->next;
    delete p;
    return result;
}
