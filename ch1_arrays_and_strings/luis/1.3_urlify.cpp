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
//                 %20 ... How do we shift the next chars?
//
// Let's try backward processing
// Input:       "Mr John Smith"
// processing:  "Mr John Smith      "
//                           *
//                          *
//                         *
//                        *
//                       *
//                 %20 ... How do we shift the next chars?

#include "catch.hpp"

#include <algorithm>
#include <string>
#include <limits>

using namespace std;

// Time complexity:  O(N)
// Space complexity: O(1)
void urlify(string& str)
{
    size_t originalLenght = str.size();
    const size_t spaces = static_cast<size_t>(count(begin(str), end(str), ' '));
    str.resize(str.size() + spaces * 3 - spaces);

    size_t index = str.size() - 1;
    for (size_t i = originalLenght - 1; i != numeric_limits<size_t>::max(); i--) {
        if (str[i] == ' ') {
            // Replace ' ' by '%20'
            str[index] = '0';
            str[index - 1] = '2';
            str[index - 2] = '%';
            index = index - 3;
        } else {
            // Copy input char
            str[index] = str[i];
            index--;
        }
    }
}

TEST_CASE("1.3 - urlify string with spaces")
{
    string str("Mr John Smith");
    urlify(str);
    REQUIRE(str == "Mr%20John%20Smith");
}

TEST_CASE("1.3 - urlify string without spaces")
{
    string str("JohnSmith");
    urlify(str);
    REQUIRE(str == "JohnSmith");
}
