// Remove Dups: Write code to remove duplicates from an unsorted linked list.
// FOLLOW UP
// How would you solve this problem if a temporary buffer is not allowed?

#include "catch.hpp"
#include "lists/Node.h"
#include "lists/utils.h"

#include <iostream>
#include <unordered_set>

using namespace std;

// Use a hash table to identify if a value has been already added:
// Time complexity: O(N)
// Space complexity: O(N)
void removeDuplicates(Node* node)
{
    unordered_set<int> set;
    Node* previous = nullptr;

    while (node != nullptr) {
        auto ret = set.insert(node->value);
        if (ret.second == false) {
            previous->next = std::move(node->next);
            node = previous->next.get();
        } else {
            previous = node;
            node = node->next.get();
        }
    }
}

// Temporary buffer not allowed -> ues a second pointer to search ahead the first one.
// Time complexity: O(N^2)
// Space complexity: O(1)
void removeDuplicatesNoBuffer(Node* node)
{
    Node* current = node;
    while (current)
    {
        Node* runner = current;
        while (runner->next) {
            if (runner->next->value == current->value) {
                runner->next = std::move(runner->next->next);
            } else {
                runner = runner->next.get();
            }
        }
        current = current->next.get();
    }
}

TEST_CASE("Remove duplicates when they are in non consecutive positions", "[2.1]")
{
    auto list = createList({5, 1, 2, 3, 4, 5});
    REQUIRE(countNodes(list.get()) == 6);

    SECTION("with hash table version")
    {
        removeDuplicates(list.get());
        REQUIRE(countNodes(list.get()) == 5);
    }

    SECTION("with no space version")
    {
        removeDuplicatesNoBuffer(list.get());
        REQUIRE(countNodes(list.get()) == 5);
    }
}

TEST_CASE("Remove duplicates when they are in consecutive positions", "[2.1]")
{
    auto list = createList({1, 2, 2, 2, 3, 4, 5});
    REQUIRE(countNodes(list.get()) == 7);

    SECTION("with hash table version")
    {
        removeDuplicates(list.get());
        REQUIRE(countNodes(list.get()) == 5);
    }

    SECTION("with no space version")
    {
        removeDuplicatesNoBuffer(list.get());
        REQUIRE(countNodes(list.get()) == 5);
    }
}

TEST_CASE("Do not crash with empty lists", "[2.1]")
{
    REQUIRE_NOTHROW(removeDuplicates(nullptr));
    REQUIRE_NOTHROW(removeDuplicatesNoBuffer(nullptr));
}
