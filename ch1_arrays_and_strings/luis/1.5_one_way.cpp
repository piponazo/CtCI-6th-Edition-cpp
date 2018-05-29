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

#include "catch.hpp"
#include <algorithm>

//bool oneEditAway(const std::string& a, const std::string& b)  {
//    int diff = a.size() - b.size();
//    int countDifferences = std::abs(diff);
//    for (size_t i=0; i<a.size() || i<b.size(); i++) {
//        const bool diffInCharI = (a[i] != b[i]);
//        countDifferences += diffInCharI;
//    }
//    return countDifferences < 2;
//}

bool oneReplacement(const std::string& a, const std::string& b) {
    size_t counter=0;
    for (size_t i=0; i<a.size(); i++) {
        counter += (a[i] != b[i]);
    }
    return counter<=1;
}

bool moreThanOneInsert(const std::string& a, const std::string& b) {
    size_t idxA=0, idxB=0;
    while (idxA < a.size() && idxB < b.size()) {
        if (a[idxA] != b[idxB]) {
            if (idxA != idxB) { // if we go inside, we have >=2 insertions/removals
                return false;
            } else {
                idxB++;
            }
        } else {
            idxA++;
            idxB++;
        }
    }
    return true;
}

bool oneEditAway(const std::string& a, const std::string& b) {
    if (a.size() == b.size()) {
        return oneReplacement(a, b);
    } else if (a.size() + 1 == b.size()) {
        return moreThanOneInsert(a,b);
    } else if (a.size() == b.size() + 1) {
        return moreThanOneInsert(b,a);
    }
    return false;
}

TEST_CASE("oneEditAway return true when there is only one edit") {
    REQUIRE(oneEditAway("pale", "ple"));
    REQUIRE(oneEditAway("pales", "pale"));
    REQUIRE(oneEditAway("pale", "bale"));
}

TEST_CASE("oneEditAway return true when there strings are similar") {
    REQUIRE(oneEditAway("pale", "pale"));
}

TEST_CASE("oneEditAway return false when there are more than one edit") {
    REQUIRE_FALSE(oneEditAway("pale", "bake"));
}