// Return Kth to Last: Implement an algorithm to find the kth to last element of a singly linked
// list.
// #8   What if you know the linked list size? What is the difference between finding the Kth-to-last element and
//      finding the Xth element?
// #25  If you don't know the linked list size, can you compute it? How does this impact the runtime?
// #41  Try implementing it recursively. If you could find the (K-1)th to last element, can you find the Kth element?
// #67  You might find useful to return multiple values. Some languages don't directly support this, but there are
//      workarounds in essentially any language. What are some of those workarounds?
// #126 Can you do it iteratively? Imagine if you had two pointers pointing to adjacent nodes and they were moving at
//      the same speed through the linked list. When one hits the end of the linked list, where will the other be?

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

    const Node* runner = root; // Runner
    const Node* node = root;

    // Advance runner k positions
    for (size_t i = 0; i < k; i++) {
        if (!runner->next) {
            throw runtime_error("k is greater than list size");
        }
        runner = runner->next.get();
    }

    // Now the two pointers advance together
    while (runner->next) {
        node = node->next.get();
        runner = runner->next.get();
    }

    return node;
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
