// Sorted merge: You are given two sorted arrays, A and B, where A has a large enough buffer at
// the end to hold B. Write a method to merge B into A in sorted order.

#include "catch.hpp"
#include <vector>
#include <iostream>
#include <algorithm>

void sortedMerge(std::vector<int>&a, const std::vector<int>&b) {
    const size_t originalSizeA = a.size();
    a.resize(a.size() + b.size());

    int idxB = b.size()-1;
    int idxA = originalSizeA-1;
    int idxTgt = a.size()-1;
    while(idxB >= 0)
    {
        if (b[idxB] > a[idxA]) {
            a[idxTgt--] = b[idxB--];
        } else {
            a[idxTgt--] = a[idxA--];
        }
    }
}

TEST_CASE("Sorted merge with interleaved arrays", "[sort]") {
    std::vector<int> a{1,2,3,4,5,10};
    std::vector<int> b{8,9,12,14};
    sortedMerge(a, b);
    REQUIRE(a == std::vector<int>{1,2,3,4,5,8,9,10,12,14});
}

TEST_CASE("Sorted merge consecutive arrays", "[sort]") {
    std::vector<int> a{1,2,3,4,5};
    std::vector<int> b{8,9,12,14};
    sortedMerge(a, b);
    REQUIRE(a == std::vector<int>{1,2,3,4,5,8,9,12,14});
}

TEST_CASE("Sorted merge with a empty", "[sort]") {
    std::vector<int> a;
    std::vector<int> b{8,9,12,14};
    sortedMerge(a, b);
    REQUIRE(a == std::vector<int>{8,9,12,14});
}

TEST_CASE("Sorted merge with b empty", "[sort]") {
    std::vector<int> a{1,2,3,4};
    std::vector<int> b;
    sortedMerge(a, b);
    REQUIRE(a == std::vector<int>{1,2,3,4});
}

TEST_CASE("Sorted merge with a & b empty", "[sort]") {
    std::vector<int> a;
    std::vector<int> b;
    sortedMerge(a, b);
    REQUIRE(a.empty());
}
