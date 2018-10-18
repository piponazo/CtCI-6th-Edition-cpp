// Remove Dups: Write code to remove duplicates from an unsorted linked list.
// FOLLOW UP
// How would you solve this problem if a temporary buffer is not allowed?

#include "lists/Node.h"
#include "lists/utils.h"
#include "catch.hpp"

#include <iostream>
#include <unordered_set>

using namespace std;

// Use a hash table to identify if a value has been already added:
// Time complexity: O(N)
// Space complexity: O(N)
// This implementation uses extra space (unordered_set)
// This implementation is not recursive.
void removeDuplicates(Node* node) {
    if (node == nullptr) {
        return;
    }

    unordered_set<int> set;
    set.insert(node->value);

    while(node && node->next) {
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

TEST_CASE( "Remove duplicates when they are in non consecutive positions", "[2.1]" ) {
    auto list = createList({5,1,2,3,4,5});
    REQUIRE(countNodes(list.get()) == 6);

    SECTION("with hash table version") {
        removeDuplicates(list.get());
        REQUIRE(countNodes(list.get()) == 5);
    }

    SECTION("with no space version") {
        removeDuplicatesNoBuffer(list.get());
        REQUIRE(countNodes(list.get()) == 5);
    }
}

TEST_CASE( "Remove duplicates when they are in consecutive positions", "[2.1]" ) {
    auto list = createList({1,2,2,2,3,4,5});
    REQUIRE(countNodes(list.get()) == 7);

    SECTION("with hash table version") {
        removeDuplicates(list.get());
        REQUIRE(countNodes(list.get()) == 5);
    }

    SECTION("with no space version") {
        removeDuplicatesNoBuffer(list.get());
        REQUIRE(countNodes(list.get()) == 5);
    }
}
