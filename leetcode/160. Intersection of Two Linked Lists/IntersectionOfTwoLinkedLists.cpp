//
//  IntersectionOfTwoLinkedLists.cpp
//  LeetcodeCpp
//
//  Created by XiaojianDuan on 2024/3/7.
//

#include "IntersectionOfTwoLinkedLists.hpp"
#include "ListNode.hpp"

class IntersectionOfTwoLinkedListsSolution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p = headA, *q = headB;
        bool pHasChanged = false, qHasChanged = false;
        while (p  != q) {
            p = p->next;
            if (p == nullptr && !pHasChanged) {
                p = headB;
                pHasChanged = true;
            }
            q = q->next;
            if (q == nullptr && !qHasChanged) {
                q = headA;
                qHasChanged = true;
            }
        }
        return p;
    }
};
