//
//  MergeKSortedLists.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/11/1.
//

#include "MergeKSortedLists.hpp"
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class MergeKSortedListsSolution {
public:
    // 先合并2个排序链表，再分治
    // ListNode* mergeTwoLists(ListNode *list1, ListNode *list2) {
    //     if (nullptr == list1) return list2;
    //     if (nullptr == list2) return list1;
    //     ListNode *temp = new ListNode(-1, nullptr);
    //     ListNode *p = temp;
    //     while (list1 != nullptr && list2 != nullptr) {
    //         if (list1->val <= list2->val) {
    //             p->next = list1;
    //             list1 = list1->next;
    //         } else {
    //             p->next = list2;
    //             list2 = list2->next;
    //         }
    //         p = p->next;
    //     }
    //     if (nullptr == list1) p->next = list2;
    //     if (nullptr == list2) p->next = list1;
    //     p = temp->next;
    //     delete temp;
    //     return p;
    // }

    // ListNode* merge(vector<ListNode*>& lists, int low, int high) {
    //     if (low > high) return nullptr;
    //     if (low == high) return lists[low];
    //     int mid = 0.5 * (low + high);
    //     return mergeTwoLists(merge(lists, low, mid), merge(lists, mid + 1, high));
    // }

    // ListNode* mergeKLists(vector<ListNode*>& lists) {
    //     int cnt = lists.size();
    //     if (cnt == 0) {
    //         return nullptr;
    //     }
    //     if (cnt == 1) {
    //         return lists[0];
    //     }
    //     if (cnt == 2) {
    //         return mergeTwoLists(lists[0], lists[1]);
    //     }
    //     return merge(lists, 0, cnt - 1);
    // }

    // 优先级队列
    struct CompareElement {
        int val;
        ListNode *ptr;
        bool operator < (const CompareElement &node) const {
            return val > node.val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto pq = priority_queue<CompareElement>();
        for (auto node : lists) {
            if (node != nullptr) {
                pq.push({node->val, node});
            }
        }
        ListNode *temp = new ListNode(-1, nullptr);
        ListNode *p = temp;
        while (!pq.empty()) {
            CompareElement node = pq.top();
            pq.pop();
            p->next = node.ptr;
            p = p->next;
            ListNode *q = node.ptr->next;
            if (q != nullptr) {
                pq.push({q->val, q});
            }
        }
        ListNode *head = temp->next;
        delete temp;
        return head;
    }
};
