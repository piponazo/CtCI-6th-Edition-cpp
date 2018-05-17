// You are given two 32-bit numbers, N and M, and two bit positions, i and j. Write a method to
// insert M into N such that M starts at bit j and ends at bit i. You can assume that the bits j
// through i have enough space to fit all of M. That is, if M=10011, you can assume that there are
// at least 5 bits between j and i. You would not, for example, have j=3, and i=2, because M could
// not fully fit between bit 3 and bit 2.
//
// Example:
// Input: N=10000000000, M=10011, i=2, j=6
// Output:N=10001001100

#include <iostream>
#include <bitset>
#include <cstdint>
#include <climits>
#include <cassert>
#include <cmath>

using namespace std;

void clearBits(bitset<32>& N, int j, int i);
void intersect(bitset<32>& N, bitset<32>&M, int i);

int main() {
    //bitset<32> N("10000000000"), M("10011");
    //int i=2, j=6;

    bitset<32> N("10110011001"), M("10011");
    int i=2, j=6;

    cout << "N: " << N << endl;
    cout << "M: " << M << endl;
    cout << "i: " << i << endl;
    cout << "j: " << j << endl;

    clearBits(N, j, i);
    intersect(N, M, i);
    cout << "N-f:\t" << N << endl;
}

void clearBits(bitset<32>& N, int j, int i) {
    assert(j>i);

    int bitsTo1 = j-i+1;
    bitset<32> mask(pow(2., bitsTo1)-1);
    mask <<= i;
    N &= ~mask;
    //cout << "mask:\t\t" << mask << endl;
    //cout << "~mask:\t\t" << ~mask << endl;
    //cout << "N-clear:\t" << N << endl;
}

void intersect(bitset<32>& N, bitset<32>&M, int i) {
    M <<= i;
    N |= M;
    //cout << "M-s:\t" << M << endl;
}
