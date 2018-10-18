#include "catch.hpp"
#include "lists/utils.h"

TEST_CASE("getNode - recursive version", "[lib]")
{
    Node root(0);
    Node *tail = &root;

    for (int i = 1; i <= 5; i++) {
        tail = tail->appendToTail(i);
    }

    SECTION("return pointer to existing node")
    {
        auto node = getNode(&root, 3);
        REQUIRE(node != nullptr);
        REQUIRE(node->value == 3);
    }

    SECTION("return nullptr for a non existing node")
    {
        REQUIRE(nullptr == getNode(&root, 9));
    }
}

TEST_CASE("getNode - iterative version", "[lib]")
{
    Node root(0);
    Node *tail = &root;

    for (int i = 1; i <= 5; i++) {
        tail = tail->appendToTail(i);
    }

    SECTION("return pointer to existing node")
    {
        auto node = getNodeIt(&root, 3);
        REQUIRE(node != nullptr);
        REQUIRE(node->value == 3);
    }

    SECTION("return nullptr for a non existing value")
    {
        REQUIRE(nullptr == getNodeIt(&root, 9));
    }
}

TEST_CASE("create list with vector of values", "[lib]")
{
    std::vector<int> values{1, 2, 3, 4, 5};
    auto list = createList(values);

    REQUIRE(list);
    REQUIRE(countNodes(list.get()) == 5);

    SECTION("All elements inserted are available")
    {
        for (auto value : values) {
            REQUIRE(getNodeIt(list.get(), value));
        }
    }

    SECTION("values not inserted are not in the list")
    {
        REQUIRE_FALSE(getNodeIt(list.get(), 0));
        REQUIRE_FALSE(getNodeIt(list.get(), 6));
    }
}

TEST_CASE("does not create list with empty list of values", "[lib]")
{
    auto list = createList({});
    REQUIRE_FALSE(list);
}

TEST_CASE("convertListToVector does its job with vector.size() >= 1", "[lib]")
{
    std::vector<int> expectedValues{1, 2, 3, 4, 5};
    auto list = createList(expectedValues);
    auto valuesFromList = convertListToVector(list.get());
    REQUIRE(expectedValues == valuesFromList);
}

TEST_CASE("convertListToVector return empty vector with empty list", "[lib]")
{
    auto valuesFromList = convertListToVector(nullptr);
    REQUIRE(valuesFromList.empty());
}
