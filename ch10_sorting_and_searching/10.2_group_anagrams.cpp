// Group anagrams: Write a method to sort an array of strings so that all the anagrams are next to
// each other.

#include "catch.hpp"
#include <vector>
#include <string>

void groupAnagrams(std::vector<std::string>& strings) {
    for (auto &str: strings) {
        std::sort(str.begin(), str.end());
    }
    std::sort(strings.begin(), strings.end());
}

TEST_CASE("Group anagrams", "[sort]") {
    std::vector<std::string> strings {
        "hola",
        "jijo",
        "ahlo",
        "ojji",
    };

    groupAnagrams(strings);

    std::vector<std::string> expectedStrings {
        "ahlo",
        "ahlo",
        "ijjo",
        "ijjo",
    };
    REQUIRE(strings == expectedStrings);
}
