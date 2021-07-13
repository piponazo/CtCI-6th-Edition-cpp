// One Way: There are three types of edits that can be performed on strings: insert a character,
// remove a character, or replace a characters. Given two strings, write a function to check if
// they are one edit (or zero edits) away.

// EXAMPLE
// pale, ple -> true
// pales, pale -> true
// pale, bale -> true
// pale, bake -> false

// idea0: check each of the things separately
// idea1: hash table --> unordered map
// idea2: compare char by char so that:
//  -> counter++ if one of the characters differ
//  -> counter++ if sizes differ

// My own notes:
// If only 1or0 edits are allowed, we just need to check for size differences of +-1

// Questions to interviewer:
// * Each of these operations happen once or more times?

#include "catch.hpp"

#include <cassert>
#include <algorithm>

bool oneReplacement(const std::string& a, const std::string& b) {
    assert(a.size() == b.size());
    size_t counter=0;
    for (size_t i=0; i<a.size(); i++) {
        counter += (a[i] != b[i]);
    }
    return counter<=1;
}

bool moreThanOneInsert(const std::string& a, const std::string& b) {
    size_t idxA{0}, idxB{0}, changes{0};
    while (idxA < a.size() && idxB < b.size()) {
        if (a[idxA] != b[idxB]) {
            changes++;
            idxB++;
        } else {
            idxA++;
            idxB++;
        }
    }
    return changes <= 1;
}

bool oneEditAway(const std::string& a, const std::string& b) {
    // If size is equal we just base our checks in the number of replacements
    if (a.size() == b.size()) {
        return oneReplacement(a, b);
    } else if (a.size() + 1 == b.size()) { // b > a
        return moreThanOneInsert(a,b);
    } else if (a.size() == b.size() + 1) { // a > b
        return moreThanOneInsert(b,a);
    }
    return false; // In this case we have strings with 2[or more] inserts or removals
}

TEST_CASE("1.5 - oneEditAway return true when there is only one edit") {
    REQUIRE(oneEditAway("pale", "ple"));
    REQUIRE(oneEditAway("pales", "pale"));
    REQUIRE(oneEditAway("pale", "bale"));
}

TEST_CASE("1.5 - oneEditAway return true when there strings are similar") {
    REQUIRE(oneEditAway("pale", "pale"));
}

TEST_CASE("1.5 - oneEditAway return false when there are more than one edit") {
    REQUIRE_FALSE(oneEditAway("pale", "bake"));
    REQUIRE_FALSE(oneEditAway("pale", "pa"));
    REQUIRE_FALSE(oneEditAway("pale", "palezz"));
}
