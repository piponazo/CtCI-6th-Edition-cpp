// Palindrome permutation:
// Given a string, write a function to check if it is a permutation of a palindrome. A palindrome
// is a word or phrase that is the same forwards and backwards. A permutation is a rearrangement of
// letters. The palindrome does not need to be limited to just dictionary words.
//
// EXAMPLE:
// Input: Tact Coa
// Output: True (Permutations: "taco cat", "atco cta", etc.)

// Questions: Should we consider lower/upper case?

#include <algorithm>
#include <bitset>
#include <string>
#include <unordered_map>

#include "catch.hpp"

using namespace std;

// Runtime O(N)
// Space O(1)
bool isPermutationPalindrome(const string& str)
{
    unordered_map<char, int> occurrences;
    std::for_each(str.begin(), str.end(), [&](char c) { occurrences[std::tolower(c)]++; });

    // For a word/sentence to be a palindrome, only 1 character can have an odd number of ocurrences
    int charsWithOddOccurrences = count_if(begin(occurrences), end(occurrences),
                                           [](const auto& it) { return it.first != ' ' && it.second % 2 != 0; });

    return charsWithOddOccurrences <= 1;
}

// Runtime O(N) . Only one pass instead of two. However, more logic.
// Space O(1)
bool isPermutationPalindromeOnline(const string& str)
{
    unordered_map<char, int> occurrences;
    int countOdds{0};
    std::for_each(str.begin(), str.end(), [&](char c) {
        if (std::isalnum(c)) {
            auto cLow = std::tolower(c);
            occurrences[cLow]++;
            if (occurrences[cLow] % 2 == 1) {
                countOdds++;
            } else {
                countOdds--;
            }
        }
    });

    return countOdds <= 1;
}

// Runtime O(N).
// Space O(1). Smaller memory footprint than in the other solutions.
// Actually this solution is quite elegant
bool isPermutationPalindromeSwitches(const string& str)
{
    std::bitset<128> switches(0);
    std::for_each(str.begin(), str.end(), [&](char c) {
        if (std::isalnum(c)) {
            switches.flip(std::tolower(c));
        }
    });
    return switches.count() <= 1;
}

namespace
{
    const std::vector<std::string> positiveCases{
        "tact coa", "      aaaaaaaabbddeellloorrrrzz", "TactCoa", "tactcoapapa", "dabale arroz a la zorra el abad",
    };
}

TEST_CASE("1.4 - strings are permutation of palindrome")
{
    for (auto& str : positiveCases) {
        REQUIRE(isPermutationPalindrome(str));
        REQUIRE(isPermutationPalindromeOnline(str));
        REQUIRE(isPermutationPalindromeSwitches(str));
    }
}

TEST_CASE("1.4 - strings are not permutation of palindrome")
{
    REQUIRE_FALSE(isPermutationPalindrome("fact coa"));
    REQUIRE_FALSE(isPermutationPalindromeOnline("fact coa"));
    REQUIRE_FALSE(isPermutationPalindromeSwitches("fact coa"));
}
