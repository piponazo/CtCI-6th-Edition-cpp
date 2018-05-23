// List of depths: Given a binary tree, design an algorithm which creates a linked list of all the
// nodes at each depth (e.g, if you have a tree with depth D, you'll have D linked lists).

#include "tree.h"
#include "catch.hpp"

#include <vector>
#include <map>

#include <iterator>

using namespace std;

void createLinkedListPerLevel(const unique_ptr<Node>& root, map<int, vector<int>> &lists,
                               int level=0) {
    if (root) {
        lists[level].push_back(root->value);
        createLinkedListPerLevel(root->left, lists, level+1);
        createLinkedListPerLevel(root->right, lists, level+1);
    }
}

TEST_CASE("create list of depths", "[tree]") {
    std::set<int> seq {10, 14, 19, 27, 31, 35, 42};
    auto root =createBinarySearchTree(seq);

    map<int, vector<int>> lists;
    createLinkedListPerLevel(root, lists, 0);
    REQUIRE(lists.size() == 3);
    REQUIRE(lists[0] == std::vector<int>{27});
    REQUIRE(lists[1] == std::vector<int>{14, 35});
    REQUIRE(lists[2] == std::vector<int>{10, 19, 31, 42});
}

