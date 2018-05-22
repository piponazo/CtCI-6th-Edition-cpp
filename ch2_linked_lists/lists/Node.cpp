#include "Node.h"

Node::Node(int _value):
    value(_value)
{
}

Node* Node::appendToTail(int value) {
    next = std::make_unique<Node>(value);
    return next.get();
}
