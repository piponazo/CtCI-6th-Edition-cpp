// String Rotation: Assume you have a method isSubstring which check if one word is a substring of another word. Given
// Two strings, s1 and s2, write code to check if s2 is a rotation of s1 using only one call to isSubstring. E.g:
// "waterbottle" is a rotation of "erbottlewat".
//
// #34 if a string is a rotation of another, the it's a rotation at a particular point. For example, a rotation of
// waterbottle at character 3 means cutting waterbottle at character 3 and putting the right half (erbottle) before the
// left half (wat).

// #88 We are essentially asking if there's a way of splitting the first string into two parts, x and y, such that the
// first string is xy and the second string is yx. For example, x = wat and y = erbottle. The first string is xy and
// the second string is yx.

// #104 Think about the earlier hint. Then think about what happens when you concatenate erbottlewat to itself.
// You get erbottlewaterbottlewat

#include "catch.hpp"

#include <string>

using namespace std;

bool isSubstring(const string& s1, const string& s2)
{
    auto idx = s1.find(s2);
    return idx != std::string::npos;
}

bool isStringRotation(const string& s1, const string& s2)
{
    string s2x2 = s2 + s2;
    return isSubstring(s2x2, s1);
}

TEST_CASE("1.9 - is rotation") {
    string s1 {"waterbottle"};
    string s2 {"erbottlewat"};
    REQUIRE(isStringRotation(s1, s2));
}

TEST_CASE("1.9 - isn't rotation") {
    string s1 {"waterbottle"};
    string s2 {"erbot2lewat"};
    REQUIRE_FALSE(isStringRotation(s1, s2));
}
