#include "utils.h"

#include <iostream>

void printLinkedList(const Node* root) {
    if (root) {
        std::cout << root->value << " ";
        printLinkedList(root->next.get());
    }
}
