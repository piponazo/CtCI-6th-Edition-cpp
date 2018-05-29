// Check Permutation: Given two strings, write a method to decide if one is a permutation of the
// other.

#include "catch.hpp"

#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

// This solution does not use any additional space, but time complexity is O(N log N)
bool isPermutationSort(string& ref, string& comp) {
    sort(begin(ref), end(ref));
    sort(begin(comp), end(comp));

    // Some day in a near future ...
    //sort(std::execution::par_unseq, begin(ref), end(ref));
    //sort(std::execution::par_unseq, begin(comp), end(comp));
    return ref == comp;
}

// This solution uses some space but its runtime is O(N)
bool isPermutation(const string& ref, const string& comp) {
    if (ref.size() != comp.size()) {
        return false;
    }

    unordered_map<char, int> charsInRef;
    for (auto c: ref) {
        charsInRef[c]++;
    }

    for (auto c: comp) {
        charsInRef[c]--;
        if (charsInRef[c]<0) {
            return false;
        }
    }
}

TEST_CASE("It is permutation (with unique chars)") {
    string str1 ("asdfghjklñ");
    string str2 ("ñlkjhgfdsa");
    REQUIRE(isPermutation(str1, str2));
    REQUIRE(isPermutationSort(str1, str2));
}

TEST_CASE("It is permutation (with repeated chars)") {
    string str1 ("asdfghjklñd");
    string str2 ("ñlkjhgfdsad");
    REQUIRE(isPermutation(str1, str2));
    REQUIRE(isPermutationSort(str1, str2));
}

TEST_CASE("It isn't permutation") {
    string str1 ("asdfghjklñ");
    string str2 ("ñlkjhgfdso");
    REQUIRE_FALSE(isPermutation(str1, str2));
    REQUIRE_FALSE(isPermutationSort(str1, str2));
}
