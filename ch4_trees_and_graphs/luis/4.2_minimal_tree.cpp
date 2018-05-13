// Given a sorted (increasing order) array with unique integer elements, write an algorithm to
// create a binary search tree with minimal height

#include <memory>
#include <random>
#include <algorithm>
#include <iterator>
#include <set>
#include <queue>

#include <iostream>

using namespace std;

// Node of a binary tree
struct Node {
    Node(int v) : value(v) {}

    int value{0};

    unique_ptr<Node> left;  ///< left child
    unique_ptr<Node> right; ///< right child
};

// std::set contains a sorted set of unique objects
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

unique_ptr<Node> createBinarySearchTree(const set<int>& seq);

void preOrderTraversal(const unique_ptr<Node>& root);
void printLevelOrder(const unique_ptr<Node>& root);
int height(const unique_ptr<Node>& root);

// With an odd number of values --> the median is the middle number
// With an even number of values --> the median is the mean of the two central numbers
int  median(const set<int>& seq)
{
    return *next(seq.begin(), seq.size()/2);
}

int main() {
    auto seq = getRandomSequence();

    cout << "Random sequence (size " << seq.size() << "): \n";
    copy(begin(seq), end(seq), ostream_iterator<int>(cout, " "));
    cout << endl;

    auto root =createBinarySearchTree(seq);

    cout << "Height of tree created: " << height(root) << endl;

    preOrderTraversal(root);
    //printLevelOrder(root);

    return EXIT_SUCCESS;
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
