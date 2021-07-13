// Remove Dups: Write code to remove duplicates from an unsorted linked list.
// FOLLOW UP
// How would you solve this problem if a temporary buffer is not allowed?
// #9
// #40

#include <iostream>

using namespace std;

void setRowAndColumnToZero(vector<vector<std::uint32_t>> &matrix, size_t indexI, size_t indexJ);


int main(int argc, char** argv)
{
    vector<vector<std::uint32_t>> original { {1,2,1,2},
                                             {2,0,2,3},
                                             {3,4,3,4},
                                             {4,5,4,5}};

    cout << "Print original matrix:\n";
    printMat(original);

    auto result = zeroMatrix(original);
    auto resultIndixes = zeroMatrixIndixesFirst(original);

    cout << "Print transformed matrix:\n";
    printMat(result);

    cout << "Print transformed matrix (2nd approach):\n";
    printMat(resultIndixes);

    return EXIT_SUCCESS;
}
