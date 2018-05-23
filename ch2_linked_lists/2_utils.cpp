#include "lists/utils.h"
#include "catch.hpp"

TEST_CASE( "get node: recursive", "[lists]" ) {
    Node root(0);
    Node *tail = &root;

    for (int i=1; i<=5; i++) {
        tail = tail->appendToTail(i);
    }

    SECTION("get existing node") {
        auto node = getNode(&root, 3);
        REQUIRE(node != nullptr);
        REQUIRE(node->value == 3);
    }

    SECTION("return nullptr with non existing value") {
        auto node = getNode(&root, 9);
        REQUIRE(node == nullptr);
    }
}


TEST_CASE( "get node: iterative", "[lists]" ) {
    Node root(0);
    Node *tail = &root;

    for (int i=1; i<=5; i++) {
        tail = tail->appendToTail(i);
    }

    SECTION("get existing node") {
        auto node = getNodeIt(&root, 3);
        REQUIRE(node != nullptr);
        REQUIRE(node->value == 3);
    }

    SECTION("return nullptr with non existing value") {
        auto node = getNodeIt(&root, 9);
        REQUIRE(node == nullptr);
    }
}


TEST_CASE( "create list with vector of values", "[lists]" ) {
    std::vector<int> values{1,2,3,4,5};
    auto list = createList(values);

    REQUIRE(list);
    REQUIRE(countNodes(list.get()) == 5);

    SECTION("All elements inserted are available") {
        for(auto value: values) {
            REQUIRE(getNodeIt(list.get(), value));
        }
    }

    SECTION("values not inserted are not in the list") {
        REQUIRE_FALSE(getNodeIt(list.get(), 0));
        REQUIRE_FALSE(getNodeIt(list.get(), 6));
    }
}

TEST_CASE( "does not create list with empty list of values", "[lists]" ) {
    auto list = createList({});
    REQUIRE_FALSE(list);
}

TEST_CASE( "convert list to vector of values", "[lists]" ) {
    std::vector<int> values{1,2,3,4,5};
    auto list = createList(values);
    auto valuesFromList = convertListToVector(list.get());
    REQUIRE(values == valuesFromList);
}

TEST_CASE( "convert list to vector return empty vector with empty list", "[lists]" ) {
    auto valuesFromList = convertListToVector(nullptr);
    REQUIRE(valuesFromList == std::vector<int>());
}
