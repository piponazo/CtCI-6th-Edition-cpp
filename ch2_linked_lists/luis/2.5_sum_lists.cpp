// Sum lists: You have two numbers represented by a linked list, where each node contains a single digit. The digits
// are stored in reverse order, such that the 1's digit is at the head of the list. Write a function that adds the two
// numbers and returns the sum as a linked list:
// Example:
// Input   (7->1->6) + (5->9->2) : that is 617+295   -->   2->1->9 (912)
// Suppose the digits are stored in forward order. Repeat the above problem:
// Input   (6->1->7) + (2->9->5) : that is 617+295   -->   9->1->2 (912)

#include "catch.hpp"
#include "lists/utils.h"
#include <iostream>

//std::unique_ptr<Node> sumListsReversed(const Node* l1, const Node* l2) {
//    int sum = l1->value + l2->value;
//    int carried = sum < 10 ? 0: 1;
//    int digit = sum%10;

//    auto root = std::make_unique<Node>(digit);
//    Node* n = root.get();

//    while(1) {
//        int v1=0, v2=0;
//        if (l1 && l1->next) {
//            l1 = l1->next.get();
//            v1 = l1->value;
//        } else {
//            l1 = nullptr;
//        }
//        if (l2 && l2->next) {
//            l2 = l2->next.get();
//            v2 = l2->value;
//        } else {
//            l2 = nullptr;
//        }
//        if (!l1 && !l2) {
//            break;
//        }

//        sum = v1 + v2 + carried;
//        carried = (numDigits(sum) == 2);
//        digit = sum%10;

//        n->appendToTail(digit);
//        n = n->next.get();

//    };

//    if (carried)
//        n->appendToTail(1);

//    return root;
//}

std::tuple<int,int> sumDigits(const int a, const int b) {
    const int sum = a + b;
    int carried = sum < 10 ? 0 : 1;
    int digit = sum%10;
    return std::make_tuple(digit, carried);
}

std::unique_ptr<Node> sumListsReversed(const Node* l1, const Node* l2, int carried=0) {
    int value = carried;
    if (l1) {
        value += l1->value;
    }
    if (l2) {
        value += l2->value;
    }
    auto root = std::make_unique<Node>(value%10);

    if (l1->next || l2->next) {
        root->next = std::move(sumListsReversed(l1->next.get(), l2->next.get(), value < 10? 0:1));
    }
    return root;
}

TEST_CASE("sum lists in reversed order (same lengths)") {
    auto l1 = createList({7,1,6});
    auto l2 = createList({5,9,2});
    auto l3 = sumListsReversed(l1.get(), l2.get());
    REQUIRE(convertListToVector(l3.get()) == std::vector<int>{2,1,9});
}

TEST_CASE("sum lists in reversed order (same lengths with carried value)") {
    auto l1 = createList({7,1,6});
    auto l2 = createList({5,9,3});
    auto l3 = sumListsReversed(l1.get(), l2.get());
    REQUIRE(convertListToVector(l3.get()) == std::vector<int>{2,1,0,1});
}

TEST_CASE("sum lists in reversed order (different lengths)") {
    auto l1 = createList({7,1,6});
    auto l2 = createList({5,9,2,1});
    auto l3 = sumListsReversed(l1.get(), l2.get());
    REQUIRE(convertListToVector(l3.get()) == std::vector<int>{2,1,9,1});
}
