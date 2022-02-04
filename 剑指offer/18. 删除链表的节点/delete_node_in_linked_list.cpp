//
//  delete_node_in_linked_list.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/4.
//

#include "delete_node_in_linked_list.hpp"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class DeleteNodeSolution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        // 新建头结点，用 next 指向原 head，可以简化操作
        ListNode *temp = new ListNode(0);
        temp->next = head;
        ListNode *p = temp;
        while (p->next != nullptr) {
            if (p->next->val == val) {
                ListNode *q = p->next->next;
                p->next = q;
            } else {
                p = p->next;
            }
        }
        ListNode *result = temp->next;
        delete temp;
        return result;
    }
};
