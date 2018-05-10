// Is unique: Implement an algorithm to determine if a string has all unique characters. What if you
// cannot use additional data structures.
//
// Hints: hash table, could a bit vector be useful, could you solve it in O(N logN) time?
//

#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <unordered_set> // available from c++11. Search and insertion have average O(1)

#include <iostream>

using namespace std;

// Implementation with has table. 
bool uniqueCharactersSet(const string& str);

bool uniqueCharactersBitset(const string& str);

// Without using additional data structures. 
bool uniqueCharactersInPlace(string str);

int main() {
    vector<string> inputs {
        "",
        "abc",
        "abcdefgha",
        "hello",
        "kite",
        "padle",
        "mamonazo",
    };

    for (const auto& str: inputs) {
        cout << "str: " << str << endl;
        cout << "unique (method set)?: " << uniqueCharactersSet(str) << endl;
        cout << "unique (method Bitset)?: " << uniqueCharactersBitset(str) << endl;
        cout << "unique (method InPlace)?: " << uniqueCharactersInPlace(str) << endl;
    }

    return EXIT_SUCCESS;
}


bool uniqueCharactersSet(const string& str) {
    if (str.size() > 256) return false;

    unordered_set<char> charSet;
    for (const auto &c: str) {
        const bool inserted = charSet.insert(c).second;
        if (!inserted) {
            return false;
        }
    }
    return true;
}

// Implementation with bitset. Useful for this case since we know the max size of a char (256)
// Time complexity: always less than O(N)
// Space complexity: O(1).
bool uniqueCharactersBitset(const string& str) {
    if (str.size() > 256) return false;

    bitset<256> bits(0);
    for (const int c: str) {
        if (bits.test(c)) {
            return false;
        }
        bits.set(c);
    }
    return true;
}

bool uniqueCharactersInPlace(string str) {
    if (str.size() > 256) return false;

    sort(begin(str), end(str)); // O(N log N)
    for (size_t i = 0; i < str.size()-1; i++) {
        if (str[i] == str[i+1]) {
            return false;
        }
    }
    return true;
}

