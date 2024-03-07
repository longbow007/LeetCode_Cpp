//
//  ListNode.hpp
//  LeetcodeCpp
//
//  Created by XiaojianDuan on 2024/3/7.
//

#ifndef ListNode_hpp
#define ListNode_hpp

#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

#endif /* ListNode_hpp */
