//
//  remove_linked_list_elements.hpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/2.
//

#ifndef remove_linked_list_elements_hpp
#define remove_linked_list_elements_hpp

#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *createLinkedList2(int a[], int n);
ListNode* removeElements(ListNode* head, int val);

#endif /* remove_linked_list_elements_hpp */
