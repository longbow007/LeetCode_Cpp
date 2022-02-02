//
//  remove_linked_list_elements_test.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/2.
//

#include "remove_linked_list_elements_test.hpp"
#include "remove_linked_list_elements.hpp"

void remove_linked_list_elements_test(void) {
    int a[] = {7,7,7,7};
    ListNode *head = createLinkedList2(a, 4);
    head = removeElements(head, 7);
}
