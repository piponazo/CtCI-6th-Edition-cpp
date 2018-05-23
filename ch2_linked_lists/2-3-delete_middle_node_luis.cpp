// Delete Middle Node: Implement an algorithm to delete a node in the middle (i.e., any node but the
// first and last node, not necessarily the exact middle) of a singly linked list, given only access
// to that node.
//
// EXAMPLE
// Input:  the noce c from the linked list a -> b -> c -> d -> e -> f
// Result: Nothing is returned, but the new linked list looks like a -> b -> d -> e -> f

#include "lists/Node.h"
#include "lists/utils.h"
#include "catch.hpp"

#include <iostream>

using namespace std;

bool deleteNode(Node* node) {
    if (!node || !node->next) {
        return false;
    }

    node->value = node->next->value;
    node->next = move(node->next->next);
    return true;
}

TEST_CASE( "delete node", "[lists]" ) {
    Node root(0);
    Node *tail = &root;

    for (int i=1; i<=5; i++) {
        tail = tail->appendToTail(i);
    }

    SECTION("delete inner node") {
        auto node = getNodeIt(&root, 3);
        REQUIRE(node != nullptr);
        REQUIRE(deleteNode(node) == true);
        REQUIRE(getNodeIt(&root, 3) == nullptr);
    }

    SECTION("does not delete a non existing node") {
        REQUIRE_FALSE(deleteNode(nullptr));
    }
}
