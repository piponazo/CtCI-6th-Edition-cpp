// Reverse String: Implement a funcion void reverse(char *str) in C or C++ which reverses a
// null terminated string.

#include "catch.hpp"
#include <algorithm>
#include <iostream>

void reverseStringC(std::string& str) {
    size_t left = 0;
    size_t right = str.size()-1;
    while (left < right) {
        std::swap(str[left++], str[right--]);
    }
}

void reverseString(std::string& str) {
    auto itReverse = str.rbegin();
    for(auto itBegin = str.begin(); itBegin != std::next(str.begin(), str.size()/2); itBegin++, itReverse++) {
        std::swap(*itBegin, *itReverse);
    }
}

TEST_CASE("Reverse string with C-style algorithm") {
    std::string str("asdfghjkl");
    reverseString(str);
    REQUIRE(str == "lkjhgfdsa");

    std::string str2("asdfghjklp");
    reverseString(str2);
    REQUIRE(str2 == "plkjhgfdsa");
}

TEST_CASE("Reverse string with algorithm using iterators") {
    std::string str("asdfghjkl");
    reverseString(str);
    REQUIRE(str == "lkjhgfdsa");

    std::string str2("asdfghjklp");
    reverseString(str2);
    REQUIRE(str2 == "plkjhgfdsa");
}

TEST_CASE("Reverse string with STL algorithm") {
    std::string str("asdfghjkl");
    std::reverse(str.begin(), str.end());
    REQUIRE(str == "lkjhgfdsa");
}

// Drawback: we need to duplicate space in memory
TEST_CASE("Reverse string with string constructor") {
    std::string str("asdfghjkl");
    std::string reversed(str.rbegin(), str.rend());
    REQUIRE(reversed == "lkjhgfdsa");
}
