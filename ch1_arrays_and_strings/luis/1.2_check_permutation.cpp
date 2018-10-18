// Check Permutation: Given two strings, write a method to decide if one is a
// permutation of the other.
// Notes: 1) Ask yourself if chars are ASCII (128), Extended ascii (256) or Unicode ( >100.000)
//        2) Case sensitive?

#include "catch.hpp"

#include <algorithm>
#include <cstdint>
#include <string>
#include <unordered_map>

using namespace std;

// Time complexity:  O(NlogN)
// Space complexity: O(1)
bool isPermutationSort(string &ref, string &comp)
{
    sort(begin(ref), end(ref));
    sort(begin(comp), end(comp));

    // Some day in a near future ...
    // sort(std::execution::par_unseq, begin(ref), end(ref));
    // sort(std::execution::par_unseq, begin(comp), end(comp));
    return ref == comp;
}

// Time complexity:  O(N)
// Space complexity: O(N)
bool isPermutation(const string &ref, const string &comp)
{
    if (ref.size() != comp.size()) {
        return false;
    }

    // Note that the values could be ints of 8, 16, 32 or 64 bytes depending on the size of the strings to process.
    unordered_map<char, std::int8_t> charsInRef;
    for_each(begin(ref), end(ref), [&charsInRef](char c) { charsInRef[c]++; });
    return !any_of(begin(comp), end(comp), [&charsInRef](char c) { return --charsInRef[c] < 0; });
}

TEST_CASE("1.2 - Returns true with empty strings")
{
    string str1("");
    string str2("");
    REQUIRE(isPermutation(str1, str2));
    REQUIRE(isPermutationSort(str1, str2));
}

TEST_CASE("1.2 - Returns true with permutations of strings with unique chars")
{
    string str1("asdfghjklñ");
    string str2("ñlkjhgfdsa");
    REQUIRE(isPermutation(str1, str2));
    REQUIRE(isPermutationSort(str1, str2));
}

TEST_CASE(
    "1.2 - Returns true with permutations of strings with repeated "
    "characters")
{
    string str1("asdfghjklñd");
    string str2("ñlkjhgfdsad");
    REQUIRE(isPermutation(str1, str2));
    REQUIRE(isPermutationSort(str1, str2));
}

TEST_CASE("1.2 - Returns false with strings that are not permutated")
{
    string str1("asdfghjklñ");
    string str2("ñlkjhgfdso");
    REQUIRE_FALSE(isPermutation(str1, str2));
    REQUIRE_FALSE(isPermutationSort(str1, str2));
}
