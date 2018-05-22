// Remove Dups: Write code to remove duplicates from an unsorted linked list.
// FOLLOW UP
// How would you solve this problem if a temporary buffer is not allowed?

#include "lists/Node.h"
#include "lists/utils.h"

#include <iostream>
#include <unordered_set>

using namespace std;

// Use a hash table to identify if a value has been already added:
// Time complexity: O(N)
// This implementation uses extra space (unordered_set)
// This implementation is not recursive.
void removeDuplicates(Node* node) {
    if (node == nullptr) {
        return;
    }

    unordered_set<int> set;
    set.insert(node->value);

    while(node->next) {
        auto& next = node->next;
        bool duplicatedValue = !set.insert(next->value).second;

        if (duplicatedValue) {
            // This line do two things: resets next, and assign it to the next->next
            next = move(next->next);
        }

        node = node->next.get();
    }
}

// Instead of using a hash table, we have second pointer to search ahead the first one.
// Time complexity: O(N^2)
// This implementation does not use extra space.
// This implementation is recursive.
void removeDuplicatesNoBuffer(Node* node) {
    if (node == nullptr) {
        return;
    }

    Node* prev = node;
    Node* runner = node->next.get();
    while(runner) {
        if (node->value == runner->value) {
            prev->next = move(runner->next);
        } else {
            prev = runner;
        }
        runner = runner->next.get();
    }

    removeDuplicatesNoBuffer(node->next.get());
}

int main()
{
    Node root(5);
    Node *tail = &root;

    for (int i=0; i<10; i++) {
        tail = tail->appendToTail(i);
    }

    cout << "created linked list: ";
    printLinkedList(&root);
    cout << endl;

    cout << "Remove duplicates ...";
    //removeDuplicates(&root);
    removeDuplicatesNoBuffer(&root);
    cout << endl;

    cout << "list after removal: ";
    printLinkedList(&root);
    cout << endl;

    return EXIT_SUCCESS;
}
