//
//  reverse_linked_list_II.cpp
//  AlgorithmCpp
//
//  Created by DuanXiaojian on 2025/3/22.
//

#include "reverse_linked_list_II.hpp"
#include "ListNode.hpp"

class ReverseLinkedListIISolution {
public:

    ListNode* reverseN(ListNode* head, int n) {
        if (n == 1) {
            successor = head->next;
            return head;
        }
        ListNode *last = reverseN(head->next, n - 1);
        head->next->next = head;
        head->next = successor;
        return last;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == 1) {
            return reverseN(head, right);
        }
        head->next = reverseBetween(head->next, left - 1, right - 1);
        return head;
    }

private:
    ListNode *successor = nullptr;
};
