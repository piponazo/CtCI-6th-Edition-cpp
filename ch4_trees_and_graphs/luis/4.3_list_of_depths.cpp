// List of depths: Given a binary tree, design an algorithm which creates a linked list of all the
// nodes at each depth (e.g, if you have a tree with depth D, you'll have D linked lists).

#include "tree.h"

#include <vector>
#include <map>

#include <iterator>
#include <iostream>

using namespace std;

void createLinkedListPerLevel(const unique_ptr<Node>& root, map<int, vector<int>> &lists,
    int depth=0);

int main() {
    //set<int> seq{5, 8, 10, 14, 15, 18, 26, 28, 29, 35, 42, 43, 44, 45, 47, 48};
    set<int> seq{1,2,4,8,10,11,12};
    auto root = createBinarySearchTree(seq);

    map<int, vector<int>> lists;
    createLinkedListPerLevel(root, lists, 0);

    for(auto it = lists.cbegin(); it != lists.end(); it++) {
        cout << "Lists at depth " << it->first << ": ";
        copy(begin(it->second), end(it->second), ostream_iterator<int>(cout, " "));
        cout << endl;
    }
}

void createLinkedListPerLevel(const unique_ptr<Node>& root, map<int, vector<int>> &lists,
    int level) {

    if (root) {
        lists[level].push_back(root->value);
        createLinkedListPerLevel(root->left, lists, level+1);
        createLinkedListPerLevel(root->right, lists, level+1);
    }
}
