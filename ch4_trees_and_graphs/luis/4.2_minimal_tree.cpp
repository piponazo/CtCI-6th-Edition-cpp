// Given a sorted (increasing order) array with unique integer elements, write an algorithm to
// create a binary search tree with minimal height

#include "tree.h"

#include <algorithm>
#include <iterator>

#include <iostream>

using namespace std;

int main() {
    auto seq = getRandomSequence();

    cout << "Random sequence (size " << seq.size() << "): \n";
    copy(begin(seq), end(seq), ostream_iterator<int>(cout, " "));
    cout << endl;

    auto root =createBinarySearchTree(seq);

    cout << "Height of tree created: " << height(root) << endl;

    preOrderTraversal(root);

    return EXIT_SUCCESS;
}

