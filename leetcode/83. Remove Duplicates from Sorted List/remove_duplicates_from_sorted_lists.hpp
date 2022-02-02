//
//  remove_duplicates_from_sorted_lists.hpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/2.
//

#ifndef remove_duplicates_from_sorted_lists_hpp
#define remove_duplicates_from_sorted_lists_hpp

#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *createLinkedList(int a[], int n);
ListNode* deleteDuplicates(ListNode* head);

#endif /* remove_duplicates_from_sorted_lists_hpp */
