// Given a sorted (increasing order) array with unique integer elements, write an algorithm to
// create a binary search tree with minimal height

#include "tree.h"
#include "catch.hpp"

#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

TEST_CASE("create binary search tree with minimal height", "[tree]"){
    {
        std::set<int> seq {10, 14, 19, 27, 31, 35, 42};
        auto root =createBinarySearchTree(seq);
        REQUIRE(depth(root.get()) == 2);

        REQUIRE(root->value == 27);
        REQUIRE(root->left->value == 14);
        REQUIRE(root->left->left->value == 10);
        REQUIRE(root->left->right->value == 19);
        REQUIRE(root->right->value == 35);
        REQUIRE(root->right->left->value == 31);
        REQUIRE(root->right->right->value == 42);
    }

    {
        std::set<int> seq {1, 3, 4, 6, 7, 8, 10, 13, 14};
        auto root =createBinarySearchTree(seq);
        REQUIRE(depth(root.get()) == 3);
    }

}
