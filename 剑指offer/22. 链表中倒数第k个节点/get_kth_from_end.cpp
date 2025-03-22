//
//  get_kth_from_end.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/4.
//

#include "get_kth_from_end.hpp"
#include <vector>
#include "ListNode.hpp"

using namespace std;

class GetKthFromEndSolution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        vector<ListNode *> v;
        ListNode *p = head;
        while (p != nullptr) {
            v.emplace_back(p);
            p = p->next;
        }
        int i = v.size() - k;
        return v[i];
    }
};
