// Return Kth to Last: Implement an algorithm to find the kth to last element of a singly linked
// list.

#include "lists/Node.h"
#include "lists/utils.h"
#include "catch.hpp"

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

TEST_CASE( "return Kth to last", "[lists]" ) {
    Node root(5);
    Node *tail = &root;

    for (int i=1; i<=5; i++) {
        tail = tail->appendToTail(i);
    }

    REQUIRE(countNodes(&root) == 6);

    SECTION("return last element") {
        auto kToLast = findKtoLast(&root, 1);
        REQUIRE(kToLast->value == 5);
    }

    SECTION("return 3-to-last element") {
        auto kToLast = findKtoLast(&root, 3);
        REQUIRE(kToLast->value == 3);
    }

    SECTION("throw when k is greater than number of elements") {
        REQUIRE_THROWS(findKtoLast(&root, 8));
    }
}
