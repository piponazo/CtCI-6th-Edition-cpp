// Palindrome permutation:
// Given a string, write a function to check if it is a permutation of a palindrome. A palindrome
// is a word or phrase that is the same forwards and backwards. A permutation is a rearrangement of
// letters. The palindrome does not need to be limited to just dictionary words.
//
// EXAMPLE:
// Input: Tact Coa
// Output: True (Permutations: "taco cat", "atco cta", etc.)

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool isPermutationPalindrome(const string& str) {
    unordered_map<char, int> occurrences;

    for (auto c: str) {
        occurrences[c]++;
    }

    // For a word/sentence to be a palindrome, only 1 character can have an odd number of ocurrences
    int charsWithOddOccurrences = count_if(begin(occurrences), end(occurrences),
        [](const auto& it) { return it.first != ' ' && it.second % 2 != 0; } );

    return charsWithOddOccurrences <= 1;
}

int main() {
    string str("tact coa");
    //string str("tact coa");
//    string str("      aaaaaaaabbddeellloorrrrzz");

    cout << "Input string: " << str << endl;
    const bool ret = isPermutationPalindrome(str);
    cout << "Is permutation of a palindrome: " << ret << endl;
}
