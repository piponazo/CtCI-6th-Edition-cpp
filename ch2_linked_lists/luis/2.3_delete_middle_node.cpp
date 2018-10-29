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

TEST_CASE( "delete node", "[2.3]" ) {
    auto l1 = createList({0,1,2,3,4,5});

    SECTION("delete inner node") {
        auto node = getNodeIt(l1.get(), 3);
        REQUIRE(deleteNode(node) == true);
        REQUIRE(getNodeIt(l1.get(), 3) == nullptr);

        auto newList = convertListToVector(l1.get());
        REQUIRE(newList == std::vector<int>{0,1,2,4,5});
    }

    SECTION("does not delete a non existing node") {
        REQUIRE_FALSE(deleteNode(nullptr));
    }

    SECTION("does not delete last node") {
        auto node = getNodeIt(l1.get(), 5);
        REQUIRE_FALSE(deleteNode(node));
    }
}
