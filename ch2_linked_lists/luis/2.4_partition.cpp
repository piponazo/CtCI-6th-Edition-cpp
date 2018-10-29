// Partition: Write code to partition a linked list around a value x, such that all nodes less than
// x come before all nodes greater than or equal to x. If x is contained within the list, the
// values of x only need to be after the elements less than x (see below). The partition element x
// can appear anywhere in the "right partition"; it does not need to appear between the left and
// right partitions.
//
// EXAMPLE
//
// Input: 3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 [partition = 5]
// Output: 3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8

#include "lists/Node.h"
#include "lists/utils.h"
#include "catch.hpp"

#include <iostream>

using namespace std;

unique_ptr<Node> partition(Node *root, int value) {
    if (!root) {
        return nullptr;
    }

    unique_ptr<Node> smallerValues;
    unique_ptr<Node> biggerValues;
    Node* smallerValuesNext = nullptr;
    Node* biggerValuesNext= nullptr;

    while(root) {
        if (root->value < value) {
            if (!smallerValues) {
                smallerValues = make_unique<Node>(root->value);
                smallerValuesNext = smallerValues.get();
            } else {
                smallerValuesNext = smallerValuesNext->appendToTail(root->value);
            }
        } else {
            if (!biggerValues) {
                biggerValues = make_unique<Node>(root->value);
                biggerValuesNext = biggerValues.get();
            } else {
                biggerValuesNext = biggerValuesNext->appendToTail(root->value);
            }
        }
        root = root->next.get();
    }

    if (!smallerValues) {
        smallerValues = make_unique<Node>(biggerValues->value);
        smallerValuesNext = smallerValues.get();
        biggerValuesNext = biggerValues->next.get();
    } else {
        biggerValuesNext = biggerValues.get();
    }

    while(biggerValuesNext) {
        smallerValuesNext = smallerValuesNext->appendToTail(biggerValuesNext->value);
        biggerValuesNext = biggerValuesNext->next.get();
    }
    return smallerValues;
}

TEST_CASE("partition list around X value, with lower and higher values", "[2.4]") {
    auto list = createList({3,5,8,5,10,2,1});
    auto listPartitioned = partition(list.get(), 5);
    auto outputValues = convertListToVector(listPartitioned.get());
    REQUIRE(outputValues == std::vector<int>{3, 2, 1, 5, 8, 5, 10});
}

TEST_CASE("partition list around X value, only with lower values", "[2.4]") {
    std::vector<int> originalValues({3,5,8,5,10,2,1});
    auto list = createList(originalValues);
    auto listPartitioned = partition(list.get(), 11);
    auto outputValues = convertListToVector(listPartitioned.get());
    REQUIRE(outputValues == originalValues);
}

TEST_CASE("partition list around X value, only with higher values", "[2.4]") {
    std::vector<int> originalValues({3,5,8,5,10,2,1});
    auto list = createList(originalValues);
    auto listPartitioned = partition(list.get(), 0);
    auto outputValues = convertListToVector(listPartitioned.get());
    REQUIRE(outputValues == originalValues);
}

TEST_CASE("partition list around X value, do nothing with empty list", "[2.4]") {
    REQUIRE(nullptr == partition(nullptr, 0));
}
