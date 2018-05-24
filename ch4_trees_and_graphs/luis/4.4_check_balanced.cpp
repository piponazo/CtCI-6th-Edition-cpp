// Check balanced: Implement a function to check if a binary tree is balanced.For the purposes of
// this question, a balanced tree is defined to be a tree such that the heights of the two subtress
// of any node never differ by more than one.

#include "catch.hpp"
#include "tree.h"
#include <limits>

bool isBalancedSlow(const Node* root) {
    if (!root) {
        return true;
    }
    int heightsDiff = std::abs(depth(root->left.get()) - depth(root->right.get()));
    if (heightsDiff <= 1) {
        return isBalancedSlow(root->left.get()) && isBalancedSlow(root->right.get());
    } else {
        return false;
    }
}

int checkHeight(const Node *root) {
    if (!root) {
        return -1;
    }

    int leftHeight = checkHeight(root->left.get());
    if (leftHeight == std::numeric_limits<int>::min()) {
        return std::numeric_limits<int>::min(); // pass error up
    }

    int rightHeight = checkHeight(root->right.get());
    if (rightHeight == std::numeric_limits<int>::min()) {
        return std::numeric_limits<int>::min(); // pass error up
    }

    if (std::abs(leftHeight - rightHeight) > 1) {
        return std::numeric_limits<int>::min();
    } else {
        return std::max(leftHeight, rightHeight) + 1;
    }
}

bool isBalancedFast(const Node* root) {
    return checkHeight(root) != std::numeric_limits<int>::min();
}

TEST_CASE("balancedSlow: is not balanced tree", "[tree]") {
    Node root(10);
    root.left = std::make_unique<Node>(8);
    root.right = std::make_unique<Node>(12);
    root.left->left = std::make_unique<Node>(6);
    root.left->left->left = std::make_unique<Node>(4);
    REQUIRE_FALSE(isBalancedSlow(&root));
}

TEST_CASE("balancedSlow: is not balanced tree 2", "[tree]") {
    Node root(10);
    root.left = std::make_unique<Node>(8);
    root.left->left = std::make_unique<Node>(6);
    root.right = std::make_unique<Node>(14);
    root.right->left = std::make_unique<Node>(12);
    root.right->left->left = std::make_unique<Node>(11);
    REQUIRE_FALSE(isBalancedSlow(&root));
}

TEST_CASE("balancedSlow: is balanced tree", "[tree]") {
    std::set<int> seq {10, 14, 19, 27, 31, 35, 42};
    auto root =createBinarySearchTree(seq);
    REQUIRE(depth(root.get()) == 2);
    REQUIRE(isBalancedSlow(root.get()));
}

TEST_CASE("balancedSlow: tree with one single node is balanced", "[tree]") {
    Node root(10);
    REQUIRE(isBalancedSlow(&root));
}


TEST_CASE("balancedFast: is not balanced tree", "[tree]") {
    Node root(10);
    root.left = std::make_unique<Node>(8);
    root.right = std::make_unique<Node>(12);
    root.left->left = std::make_unique<Node>(6);
    root.left->left->left = std::make_unique<Node>(4);
    REQUIRE_FALSE(isBalancedFast(&root));
}

TEST_CASE("balancedFast: is not balanced tree 2", "[tree]") {
    Node root(10);
    root.left = std::make_unique<Node>(8);
    root.left->left = std::make_unique<Node>(6);
    root.right = std::make_unique<Node>(14);
    root.right->left = std::make_unique<Node>(12);
    root.right->left->left = std::make_unique<Node>(11);
    REQUIRE_FALSE(isBalancedFast(&root));
}

TEST_CASE("balancedFast: is balanced tree", "[tree]") {
    std::set<int> seq {10, 14, 19, 27, 31, 35, 42};
    auto root =createBinarySearchTree(seq);
    REQUIRE(depth(root.get()) == 2);
    REQUIRE(isBalancedFast(root.get()));
}

TEST_CASE("balancedFast: tree with one single node is balanced", "[tree]") {
    Node root(10);
    REQUIRE(isBalancedFast(&root));
}
