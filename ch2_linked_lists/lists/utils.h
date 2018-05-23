#pragma once

#include "Node.h"

#include <vector>

void printLinkedList(const Node* root);

size_t countNodes(const Node* root);

/// Get a node by value or nullptr if it is not found. Recursive implementation
const Node *getNode(const Node* root, int value);

/// Get a node by value or nullptr if it is not found. Iterative implementation
Node *getNodeIt(Node *root, int value);

/// Create a single-linked list with values
std::unique_ptr<Node> createList(const std::vector<int>& values);

std::vector<int> convertListToVector(const Node* root);
