// Check Permutation: Given two strings, write a method to decide if one is a permutation of the
// other.

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool isPermutation(const string& ref, const string& comp) {
    if (ref.size() != comp.size()) {
        return false;
    }

    unordered_map<char, int> charsInRef;
    for (auto c: ref) {
        charsInRef[c]++;
    }

    return all_of(begin(comp), end(comp), [&charsInRef](char c) {
            return charsInRef.count(c) == 1;
    });
}

int main() {
    //string str1 ("hola me llamo luis");
    //string str2 ("sell moh");

    string str1 ("asdfghjklñ");
    string str2 ("ñlkjhgfdsa");
    string str3 ("ñlkjhgfdso");

    cout << "String 1: " << str1 << endl;
    cout << "String 2: " << str2 << endl;
    cout << "String 3: " << str3 << endl;
    cout << "Is str2 a permutation of str1?: " << isPermutation(str1, str2) << endl;
    cout << "Is str3 a permutation of str1?: " << isPermutation(str1, str3) << endl;
}
