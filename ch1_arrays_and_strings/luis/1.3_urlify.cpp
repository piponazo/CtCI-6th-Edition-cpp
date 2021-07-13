// URLify: Write a method to replace all spaces in a string with '%20'. You may assume that the string has sufficient
// space at the end to hold the additional characters, and that you are given the 'true' length of the string. (Note: If
// implementing in Java, please use a character array so that you can perform this operation in place).
//
// Example
// Input:  "Mr John Smith", 13
// Output: "Mr%20John%20Smith"
//
// Input:  "Mr John"
// processing:  "Mr John"
//                 *
//                 %20 ... How do we shift the next chars to the right?
//
// Let's try backward processing
// Input:       "Mr John Smith"
// processing:  "Mr John Smith      "
//                           *----->
//                          *----->
//                         *----->
//                        *----->
//                       *----->
//                 %20 ... How do we shift the next chars?

#include "catch.hpp"

#include <algorithm>
#include <string>
#include <limits>

using namespace std;

// Reserve enough space at the end + return original length
size_t reserveEnoughSpace(string& str)
{
    const size_t trueLen = str.size();
    const size_t spaces = static_cast<size_t>(count(begin(str), end(str), ' '));
    str.resize(str.size() + spaces * 3 - spaces);
    return trueLen;
}

// This version can be O(N^2) in the worst case.
string urlifySlow(const string& str)
{
    string out {str};
    for(size_t i=0; i<out.size(); i++) {
        if (out[i] == ' ') {
            std::copy(out.begin()+i+1, out.end(), out.begin()+i+3);
            out[i] = '%';
            out[i+1] = '2';
            out[i+2] = '0';
        }
    }
    return out;
}

// Time complexity:  O(N)
// Space complexity: O(1)
string urlify(const string& str, size_t originalLength)
{
    size_t indexOut = str.size() - 1;
    string out (str.size(), '0');
    for (size_t i = originalLength - 1; i != numeric_limits<size_t>::max(); i--) {
        if (str[i] == ' ') {
            // Replace ' ' by '%20'
            out[indexOut] = '0';
            out[indexOut - 1] = '2';
            out[indexOut - 2] = '%';
            indexOut = indexOut - 3;
        } else {
            // Copy input char
            out[indexOut] = str[i];
            indexOut--;
        }
    }
    return out;
}

TEST_CASE("1.3 - urlify string with spaces")
{
    string str("Mr John Smith");
    size_t originalLen = reserveEnoughSpace(str);
    REQUIRE(urlify(str, originalLen) == "Mr%20John%20Smith");
    REQUIRE(urlifySlow(str) == "Mr%20John%20Smith");
}

TEST_CASE("1.3 - urlify string without spaces")
{
    string str("JohnSmith");
    size_t originalLen = reserveEnoughSpace(str);
    REQUIRE(urlify(str, originalLen) == "JohnSmith");
    REQUIRE(urlifySlow(str) == "JohnSmith");
}
