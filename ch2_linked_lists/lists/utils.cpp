#include "utils.h"

#include <iostream>

void printLinkedList(const Node* root) {
    if (root) {
        std::cout << root->value << " ";
        printLinkedList(root->next.get());
    }
}

size_t countNodes(const Node *root) {
    if (root) {
        return countNodes(root->next.get()) + 1;
    } else {
        return 0;
    }
}

const Node *getNode(const Node *root, int value)
{
    if (root) {
        if (root->value == value) {
            return root;
        }
        return getNode(root->next.get(), value);
    }
    return nullptr;
}

Node *getNodeIt(Node *root, int value)
{
    while (root) {
        if (root->value == value) {
            return root;
        }
        root = root->next.get();
    }
    return nullptr;
}

std::unique_ptr<Node> createList(const std::vector<int> &values)
{
    if (values.empty()) {
        return nullptr;
    }

    auto root = std::make_unique<Node>(values.front());
    Node* node = root.get();
    for(size_t i=1; i<values.size(); i++) {
        node = node->appendToTail(values[i]);
    }
    return root;
}

std::vector<int> convertListToVector(const Node *root)
{
    std::vector<int> values;
    while (root) {
        values.push_back(root->value);
        root = root->next.get();
    }
    return values;
}
