// URLify: Write a method to replace all spaces in a string with '%20'. You may assume that the string has sufficient
// space at the end to hold the additional characters, and that you are given the 'true' length of the string. (Note: If
// implementing in Java, please use a character array so that you can perform this operation in place).
//
// Example
// Input:  "Mr John Smith    ", 13
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

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void urlify(string& str) {
    int originalLenght = str.size();
    const int spaces = count(begin(str), end(str), ' ');
    str.resize(str.size() + spaces*3 - spaces);

    int index = str.size()-1;
    for (int i = originalLenght-1; i >= 0; i--) {
        if (str[i] == ' ') {
            str[index]   = '0';
            str[index-1] = '2';
            str[index-2] = '%';
            index = index - 3;
        } else {
            str[index] = str[i];
            index--;
        }
    }
}

int main() {
    string str("Mr John Smith");
    cout << "string: '" << str << "' -> size: " << str.size() << endl;
    urlify(str);
    cout << "string: '" << str << "' -> size: " << str.size() << endl;
}
