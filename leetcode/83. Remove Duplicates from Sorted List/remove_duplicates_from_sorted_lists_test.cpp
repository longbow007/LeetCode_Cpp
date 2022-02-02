//
//  remove_duplicates_from_sorted_lists_test.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/2.
//

#include "remove_duplicates_from_sorted_lists_test.hpp"

void remove_duplicates_from_sorted_lists_test(void) {
    int a[] = {1,1,2};
    ListNode *list = createLinkedList(a, 3);
    list = deleteDuplicates(list);
}
