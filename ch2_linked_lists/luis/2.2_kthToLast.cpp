// Return Kth to Last: Implement an algorithm to find the kth to last element of a singly linked
// list.

#include "catch.hpp"
#include "lists/Node.h"
#include "lists/utils.h"

#include <iostream>
#include <unordered_set>

using namespace std;

// Time complexity: O(N)
// Space complexity: O(1)
const Node* findKtoLast(const Node* root, size_t k)
{
    if (!root) {
        return nullptr;
    }

    const Node* p1 = root; // Runner
    const Node* p2 = root;

    // Advance p1 alone k positions
    for (size_t i = 0; i < k; i++) {
        if (!p1->next) {
            throw runtime_error("k is greater than list size");
        }
        p1 = p1->next.get();
    }

    // Now the two pointers advance together
    while (p1->next) {
        p2 = p2->next.get();
        p1 = p1->next.get();
    }

    return p2;
}

// Time complexity: O(N)
// Space complexity: O(N)
const Node* findKtoLastRecursive(const Node* node, size_t k, size_t& i)
{
    if (!node) {
        return nullptr;
    }
    auto nd = findKtoLastRecursive(node->next.get(), k, i);
    if (i++ == k) {
        return node;
    }
    return nd;
}

// Time complexity: O(N)
// Space complexity: O(N)
const Node* findKtoLastRecursive(const Node* root, size_t k)
{
    size_t i = 0;
    const Node* ret = findKtoLastRecursive(root, k, i);
    if (i == 0) {
        return nullptr;
    } else if (k > i)  {
        throw runtime_error("k is greater than list size");
    }
    return ret;
}

TEST_CASE("return Kth to last element when list exists", "[2.2]")
{
    auto list = createList({5, 1, 2, 3, 4, 5});
    REQUIRE(countNodes(list.get()) == 6);

    SECTION("return last element")
    {
        REQUIRE(findKtoLast(list.get(), 0)->value == 5);
        REQUIRE(findKtoLastRecursive(list.get(), 0)->value == 5);
    }

    SECTION("return 3th last element")
    {
        REQUIRE(findKtoLast(list.get(), 2)->value == 3);
        REQUIRE(findKtoLastRecursive(list.get(), 2)->value == 3);
    }

    SECTION("throw when k is greater than number of elements")
    {
        REQUIRE_THROWS(findKtoLast(list.get(), 8));
        REQUIRE_THROWS(findKtoLastRecursive(list.get(), 8));
    }
}

TEST_CASE("return nullptr with empty list", "[2.2]")
{
    REQUIRE(findKtoLast(nullptr, 1) == nullptr);
    REQUIRE(findKtoLastRecursive(nullptr, 1) == nullptr);
}
