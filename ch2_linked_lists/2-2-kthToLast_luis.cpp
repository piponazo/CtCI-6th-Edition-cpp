// Return Kth to Last: Implement an algorithm to find the kth to last element of a singly linked
// list.

#include "lists/Node.h"
#include "lists/utils.h"

#include <iostream>
#include <unordered_set>

using namespace std;

const Node* findKtoLast(const Node* root, int k) {
    const Node *node = root; 
    const Node *runner = root;

    // Advance runner alone k positions
    // We define k, such that passing k=1 returns the last element
    for (int i=1; i<k; i++) {
        if (!runner->next) {
            throw runtime_error("k is greater than list size");
        }
        runner = runner->next.get();
    }

    // Now the two pointers advance together
    while(runner->next) {
        node = node->next.get();
        runner = runner->next.get();
    }

    return node;
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

    auto kToLast = findKtoLast(&root, 1);
    cout << "kToLast (1): " << kToLast->value << endl;

    kToLast = findKtoLast(&root, 3);
    cout << "kToLast (3): " << kToLast->value << endl;

    try {
        auto kToLast = findKtoLast(&root, 15);
    } catch (const exception& e) {
        cerr << "exception caught with kToLast(15): " << e.what() << endl;
    }

    return EXIT_SUCCESS;
}
