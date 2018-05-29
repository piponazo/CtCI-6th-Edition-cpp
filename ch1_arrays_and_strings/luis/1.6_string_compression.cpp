// String compression: Implement a method to perform basic string compressin using the counts of repeated characters.
// For example, the string aabcccccaaa would become a2b1c5a3. If the "compressed" string would not become smaller than
// the original string, your method return the original string. You can assume the string has only uppercase and
// lowercase letters (a-z)

#include "catch.hpp"
#include <sstream>

using namespace std;

// This was the first solution. But it is bad, since it is concatenating strings.
//string compressStr(const string& str) {
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
size_t sizeOfNewString(const string& str) {
    char previous = str[0];
    size_t counterPrevious = 1;
    size_t finalSize = 0;
    for (size_t i = 1; i<str.size(); i++) {
        if (str[i] != previous || i == str.size()-1) {
            finalSize +=  (1 + to_string(counterPrevious).size());
            previous = str[i];
            counterPrevious = 1;
        } else {
            counterPrevious++;
        }
    }
    return finalSize;
}

// This solution uses ostringstream as a StringBuilder
string compressStr(const string& str) {
    if (str.empty() || sizeOfNewString(str) >= str.size()) {
        return str;
    }

    char previous = str[0];
    size_t counterPrevious = 1;
    ostringstream strBuilder;
    for (size_t i = 1; i<str.size(); i++) {
        if (str[i] != previous || i == str.size()-1) {
            strBuilder << (previous + to_string(counterPrevious));
            previous = str[i];
            counterPrevious = 1;
        } else {
            counterPrevious++;
        }
    }
    return strBuilder.str();
}

TEST_CASE("compress when new string is shorter than the original", "stringCompression") {
    std::string src("aabcccccaaa");
    std::string tgt("a2b1c5a2");
    REQUIRE(compressStr(src) == tgt);
}

TEST_CASE("don't compress when new string isn't shorter than the original", "stringCompression") {
    std::string src("abcdefg");
    REQUIRE(compressStr(src) == src);
}
