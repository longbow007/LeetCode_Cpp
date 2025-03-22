//
//  RemoveNthNodeFromEndOfList.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/10/30.
//

#include "RemoveNthNodeFromEndOfList.hpp"
#include "ListNode.hpp"

class RemoveNthNodeFromEndOfListSolution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head, *q = p;
        for (int i = 0; i < n; i++) {
            p = p->next;
        }
        if (p == nullptr) {
            return head->next;
        }
        while (p->next != nullptr) {
            p = p->next;
            q = q->next;
        }
        q->next = q->next->next;
        return head;
    }
};
