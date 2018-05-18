// Check Permutation: Given two strings, write a method to decide if one is a permutation of the
// other.

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

// This solution does not use any additional space, but time complexity is O(N log N)
bool isPermutationSort(string& ref, string& comp) {
    sort(begin(ref), end(ref));
    sort(begin(comp), end(comp));

    // Some day in a near future ...
    //sort(std::execution::par_unseq, begin(ref), end(ref));
    //sort(std::execution::par_unseq, begin(comp), end(comp));
    
    return ref == comp;
}

// This solution uses some space but its runtime is O(N)
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
    string str1 ("asdfghjklñ");
    string str2 ("ñlkjhgfdsa");
    string str3 ("ñlkjhgfdso");

    cout << "String 1: " << str1 << endl;
    cout << "String 2: " << str2 << endl;
    cout << "String 3: " << str3 << endl;
    cout << "Is str2 a permutation of str1?: methodMap" << isPermutation(str1, str2) << endl;
    cout << "Is str3 a permutation of str1?: methodMap" << isPermutation(str1, str3) << endl;
    cout << "Is str2 a permutation of str1?: methodSort" << isPermutationSort(str1, str2) << endl;
    cout << "Is str3 a permutation of str1?: methodSort" << isPermutationSort(str1, str3) << endl;
}
