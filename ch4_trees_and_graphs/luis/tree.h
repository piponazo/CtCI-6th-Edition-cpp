#pragma one

#include <memory>
#include <set>

// Node of a binary tree
struct Node {
    Node(int v) : value(v) {}

    int value{0};

    std::unique_ptr<Node> left;  ///< left child
    std::unique_ptr<Node> right; ///< right child
};

std::unique_ptr<Node> createBinarySearchTree(const std::set<int>& seq);

void preOrderTraversal(const std::unique_ptr<Node>& root);
void printLevelOrder(const std::unique_ptr<Node>& root);
int depth(const Node *root);
int  median(const std::set<int>& seq);
