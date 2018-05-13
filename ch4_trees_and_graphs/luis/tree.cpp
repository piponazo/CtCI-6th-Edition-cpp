#include "tree.h"

#include <random>
#include <queue>

#include <iostream>

using namespace std;

set<int> getRandomSequence() {
    random_device rd;  //Will be used to obtain a seed for the random number engine
    mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> dis(1, 50);

    set<int> seq;
    for(int i = 0; i<20; i++) {
        seq.insert(dis(gen));
    }
    return seq;
}

unique_ptr<Node> createBinarySearchTree(const set<int>& seq) {
    if (seq.empty()) {
        return nullptr;
    }

    int m = median(seq);
    unique_ptr<Node> root = make_unique<Node>(m);

    auto its = seq.equal_range(m);

    root->left = createBinarySearchTree({seq.begin(), its.first});
    root->right = createBinarySearchTree({its.second, seq.end()});

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

int height(const unique_ptr<Node>& root) {
    if (!root) {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

int  median(const std::set<int>& seq)
{
    return *next(seq.begin(), seq.size()/2);
}
