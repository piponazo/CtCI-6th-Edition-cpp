// Delete Middle Node: Implement an algorithm to delete a node in the middle (i.e., any node but the
// first and last node, not necessarily the exact middle) of a singly linked list, given only access
// to that node.
//
// EXAMPLE
// Input:  the noce c from the linked list a -> b -> c -> d -> e -> f
// Result: Nothing is returned, but the new linked list looks like a -> b -> d -> e -> f

#include "lists/Node.h"
#include "lists/utils.h"

#include <iostream>

using namespace std;

void deleteNode(Node* node) {
    if (!node->next) {
        throw runtime_error("node does not have a next pointer");
    }

    node->value = node->next->value;
    node->next = move(node->next->next);
}

int main()
{
    Node root(5);
    Node *tail = &root;
    Node *nodeToDelete = nullptr;

    for (int i=0; i<10; i++) {
        tail = tail->appendToTail(i);
        if (i==5) {
            nodeToDelete = tail;
        }
    }

    cout << "created linked list: ";
    printLinkedList(&root);
    cout << endl;

    deleteNode(nodeToDelete);

    cout << "created linked list: ";
    printLinkedList(&root);
    cout << endl;

    return EXIT_SUCCESS;
}
