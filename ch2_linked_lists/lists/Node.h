#pragma once

#include <memory>

class Node
{
public:
    Node(int _value);

    /// Create node and append it to this one.
    /// @return Pointer to the new node
    Node* appendToTail(int value);

    int value;
    std::unique_ptr<Node> next;
};
