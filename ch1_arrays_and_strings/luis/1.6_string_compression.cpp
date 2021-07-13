// String compression: Implement a method to perform basic string compressin using the counts of repeated characters.
// For example, the string aabcccccaaa would become a2b1c5a3. If the "compressed" string would not become smaller than
// the original string, your method return the original string. You can assume the string has only uppercase and
// lowercase letters (a-z)

// Hints:
// #92 : Compress the string first, then compare the lengths
// #110: Be careful, you aren't repeatedly concatenating strings together. This can be very inefficient

// Questions:
// the repeated characters are always consecutive? or do we need to sort first the string?
//   oh no, I see already that the example string has a's at the beginning and at the end.

#include <sstream>

#include "catch.hpp"

using namespace std;

// This was the first solution. But it is bad, since it is concatenating strings.
// string compressStr(const string& str) {
//    if (str.empty()) {
//        return str;
//    }

//    string tmp;
//    char previous = str[0];
//    size_t counterPrevious = 1;
//    for (size_t i = 1; i<str.size(); i++) {
//        if (str[i] != previous || i == str.size()-1) {
//            tmp.append(1, previous);
//            tmp.append(to_string(counterPrevious));
//            previous = str[i];
//            counterPrevious = 1;
//        } else {
//            counterPrevious++;
//        }
//    }

//    if (tmp.size() >= str.size()) {
//        return str;
//    }
//    return tmp;
//}

// With this function we can prevent to accumulate builds and then find out the final string is bigger than the original
size_t sizeOfNewString(const string& str)
{
    char previousChar{str[0]};
    size_t counterPrevious{1};
    size_t finalSize{0};
    for (size_t i = 1; i < str.size(); i++) {
        if (str[i] != previousChar) {
            finalSize += (1 + to_string(counterPrevious).size());
            previousChar = str[i];
            counterPrevious = 1;
        } else {
            counterPrevious++;
        }
    }
    finalSize += (1 + to_string(counterPrevious).size());
    return finalSize;
}

// This solution uses ostringstream as a StringBuilder
// See https://www.codeproject.com/articles/647856/4350-performance-improvement-with-the-stringbuilde
// In principle it should be also possible to use string + reserve
string compressStr(const string& str)
{
    if (str.empty() || sizeOfNewString(str) >= str.size()) {
        return str;
    }

    char previousChar{str[0]};
    size_t counterPrevious{1};
    ostringstream strBuilder;
    for (size_t i = 1; i < str.size(); i++) {
        if (previousChar == str[i]) {
            counterPrevious++;
        } else {
            strBuilder << (previousChar + to_string(counterPrevious));
            previousChar = str[i];
            counterPrevious = 1;
        }
    }
    strBuilder << (previousChar + to_string(counterPrevious));
    return strBuilder.str();
}

TEST_CASE("1.6 - compress when new string is shorter than the original", "stringCompression")
{
    std::string src("aabcccccaaa");
    std::string tgt("a2b1c5a3");
    REQUIRE(compressStr(src) == tgt);
}

TEST_CASE("1.6 - don't compress when new string isn't shorter than the original", "stringCompression")
{
    std::string src("abcdefg");
    std::string src1("a");
    std::string src2("aa");
    std::string src3("aabbcc");
    std::string src4("");
    REQUIRE(compressStr(src) == src);
    REQUIRE(compressStr(src1) == src1);
    REQUIRE(compressStr(src2) == src2);
    REQUIRE(compressStr(src3) == src3);
    REQUIRE(compressStr(src4) == src4);
}
