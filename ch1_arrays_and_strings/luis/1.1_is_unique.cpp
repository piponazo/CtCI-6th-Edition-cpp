// Is unique: Implement an algorithm to determine if a string has all unique characters. What if you
// cannot use additional data structures.
//
// Hints: hash table, could a bit vector be useful, could you solve it in O(N logN) time?
// Notes: 1) Ask yourself if chars are ASCII (128), Extended ascii (256) or Unicode ( >100.000)

#include "catch.hpp"

#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <unordered_set> // available from c++11. Search and insertion have average O(1)

#include <iostream>

using namespace std;

// Implementation with has table + range-for loops
// Time complexity:   O(N)
// Space complexity:  O(N)
// Notes: This version is a bit longer than the one in line 36. But probably more performant
//bool uniqueCharactersSet(const string& str) {
//    if (str.size() > 256)
//        return false;
//    unordered_set<char> charSet;
//    for (const auto &c: str) {
//        const bool inserted = charSet.insert(c).second;
//        if (!inserted) {
//            return false;
//        }
//    }
//    return true;
//}

// Implementation with has table + std::all_of + lambda
// Time complexity:   O(N)
// Space complexity:  O(N)
// Notes: This version is a bit longer than the one in line 36. But probably more performant
bool uniqueCharactersSet(const string& str) {
    if (str.size() > 256)
        return false;

    unordered_set<char> charSet;
    return all_of(begin(str), end(str), [&charSet](char c){return charSet.insert(c).second;});
}

// Implementation with bitset. Useful for this case since we know the max size of a char (256)
// Time complexity:  O(N)
// Space complexity: O(1)
bool uniqueCharactersBitset(const string& str) {
    if (str.size() > 256)
        return false;

    bitset<256> bits(0);
    for (const int c: str) {
        if (bits.test(c)) {
            return false;
        }
        bits.set(c);
    }
    return true;
}

// Without using additional data structures. 
// Time complexity:  O(N logN)
// Space complexity: O(1)
bool uniqueCharactersInPlace(string str) {
    if (str.empty())
        return true;
    if (str.size() > 256)
        return false;

    sort(begin(str), end(str)); // O(N log N)
    for (size_t i = 0; i < str.size()-1; i++) {
        if (str[i] == str[i+1]) {
            return false;
        }
    }
    return true;
}

TEST_CASE("1.1 - unique characters in string returns true") {
    vector<string> inputs {
        "",
        "abc",
        "kite",
        "padle",
    };

    for (const auto& str: inputs) {
        CHECK(uniqueCharactersSet(str));
        CHECK(uniqueCharactersBitset(str));
        CHECK(uniqueCharactersInPlace(str));
    }
}

TEST_CASE("1.1 - repeated characters in string returns false") {
    vector<string> inputs {
        "abcdefgha",
        "hello",
        "mamonazo",
    };

    for (const auto& str: inputs) {
        CHECK_FALSE(uniqueCharactersSet(str));
        CHECK_FALSE(uniqueCharactersBitset(str));
        CHECK_FALSE(uniqueCharactersInPlace(str));
    }
}
