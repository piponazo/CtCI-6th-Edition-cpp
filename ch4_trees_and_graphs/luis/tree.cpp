#include "tree.h"

#include <random>
#include <queue>

#include <iostream>

using namespace std;

unique_ptr<Node> createBinarySearchTree(const set<int>& seq) {
    if (seq.empty()) {
        return nullptr;
    }

    int medianValue = median(seq);
    unique_ptr<Node> root = make_unique<Node>(medianValue);

    auto iteratorsRange = seq.equal_range(medianValue);

    root->left = createBinarySearchTree({seq.begin(), iteratorsRange.first});
    root->right = createBinarySearchTree({iteratorsRange.second, seq.end()});

    return root;
}

void preOrderTraversal(const unique_ptr<Node>& root) {
    if (root) {
        cout << root->value << endl;
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void printLevelOrder(const unique_ptr<Node>& root) {
    if (!root) {
        return;
    }

    queue<Node*> q;
    q.push(root.get());

    while(!q.empty()) {
        auto node = q.front();
        cout << node->value << " " << flush;
        q.pop();

        if (node->left != nullptr) {
            q.push(node->left.get());
        }
        if (node->right != nullptr) {
            q.push(node->right.get());
        }
    }
}

int depth(const unique_ptr<Node>& root) {
    if (!root) {
        return -1;
    }
    return 1 + max(depth(root->left), depth(root->right));
}

int  median(const std::set<int>& seq)
{
    return *next(seq.begin(), seq.size()/2);
}
