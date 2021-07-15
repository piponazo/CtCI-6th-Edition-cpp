// 2.6 Implement a function to check if a linked list is a palindrome.

// HINTS:
// #05  A palindrome is something which is the same when written forwards and backwards. What if you reversed the
//      linked list?
// #13  Try using a stack
// #29  Assume you have the length of the linked list. Can you implement this recursively?
// #61
// #109

#include "catch.hpp"
#include "lists/utils.h"
#include <iostream>
#include <stack>

using namespace std;

//unique_ptr<Node> reverseList(const Node*n)
//{
//    if (!n->next) {
//        // create head of new list here
//        return make_unique<Node>(n->value);
//    }

//    auto newNode = reverseList(n->next.get());
//    newNode->next = make_unique<Node>(n->value);
//    return newNode;
//}

// Time complexity:  O(N)
// Space complexity: O(N)
bool isPalindromeStack(const Node* n)
{
    std::stack<int> reversedValues;

    const Node* runner = n;
    while (runner) {
        reversedValues.push(runner->value);
        runner = runner->next.get();
    }

    runner = n;
    while (runner) {
        if (reversedValues.top() != runner->value)
            return false;
        reversedValues.pop();
        runner = runner->next.get();
    }
    return true;
}

bool checkReverse(const Node* backwards, const Node* forward, size_t& count)
{
    if (count == 1) {
        bool ret = forward->value == backwards->value;
        forward = forward->next.get();
        return ret;
    }

    return checkReverse(backwards->next.get(), forward, --count);
}

// 1,2,3,2,1
// 1            4       b=1, f=1, c=5
//   2          3       b=2, f=1, c=4
//     3        2       b=3, f=1, c=3
//       2      1       b=2, f=1, c=2
//         1    0       b=1, f=1, c=1

bool isPalindromeRec(const Node* n, size_t count)
{
    return checkReverse(n->next.get(), n, --count);
}

TEST_CASE("linked list is a palindrome", "[2.6]") {
    auto l1 = createList({1,2,3,2,1});
    size_t count = countNodes(l1.get());

    REQUIRE(isPalindromeStack(l1.get()));
    REQUIRE(isPalindromeRec(l1.get(), count));
}

TEST_CASE("linked list is not a palindrome", "[2.6]") {
    auto l1 = createList({1,2,3,7,1});
    size_t count = countNodes(l1.get());

    REQUIRE_FALSE(isPalindromeStack(l1.get()));
    REQUIRE_FALSE(isPalindromeRec(l1.get(), count));
}
