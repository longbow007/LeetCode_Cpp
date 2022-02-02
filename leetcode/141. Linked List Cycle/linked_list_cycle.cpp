//
//  linked_list_cycle.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/2.
//

#include "linked_list_cycle.hpp"


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr) return false;
    ListNode *slow = head, *fast = head->next;
    while (slow != fast) {
        if (fast == nullptr || fast->next == nullptr) return false;
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
    
    /* 哈希表法
     unordered_set<ListNode *>set;
     ListNode *p = head;
     while (p != nullptr) {
     if (set.count(p) > 0) return true;
     set.insert(p);
     p = p->next;
     }
     return false;
     */
}
