// Zero Matrix: Write an algorithm such that if an element in an MxN matrix is 0, its entire row and colmn are set to 0

#include "catch.hpp"
#include <vector>
#include <queue>

using namespace std;

void setRowToZero(vector<vector<int>> &matrix, size_t rowIndex, size_t N);
void setColToZero(vector<vector<int>> &matrix, size_t colIndex, size_t M);

void zeroMatrixIndexes(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix.front().empty()) {
        return;
    }
    const size_t M = matrix.size();
    const size_t N = matrix.front().size();
    vector<pair<size_t, size_t>> indexes;

    for(size_t i=0; i<M; i++) {
        if (matrix[i].size() != N) {
            throw runtime_error("internal vector with different size than the first one");
        }

        for(size_t j=0; j<N; j++) {
            if (matrix[i][j] == 0) {
                indexes.push_back(make_pair(i,j));
            }
        }
    }

    std::for_each(indexes.begin(), indexes.end(), [&](auto pair){
        setRowToZero(matrix, pair.first, N);
        setColToZero(matrix, pair.second, M);
    });
}

void zeroMatrixInPlace(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix.front().empty()) {
        return;
    }
    const size_t M = matrix.size();
    const size_t N = matrix.front().size();
    bool zeroInFirstRow {false};
    bool zeroInFirstCol {false};

    // Check first row
    for(size_t j=0; j<N; j++) {
        if (matrix[0][j] == 0) {
            zeroInFirstRow = true;
            break;
        }
    }

    // Check first column
    for(size_t i=0; i<M; i++) {
        if (matrix[i][0] == 0) {
            zeroInFirstCol = true;
            break;
        }
    }

    // Check zeros in the rest of the matrix
    for(size_t i=1; i<M; i++) {
        if (matrix[i].size() != N) {
            throw runtime_error("internal vector with different size than the first one");
        }

        for(size_t j=1; j<N; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Nullify columns based on values in first row
    for(size_t j=1; j<N; j++) {
        if (matrix[0][j] == 0) {
            setColToZero(matrix, j, M);
        }
    }

    // Nullify rows based on values in first column
    for(size_t i=1; i<M; i++) {
        if (matrix[i][0] == 0) {
            setRowToZero(matrix, i, N);
        }
    }

    if (zeroInFirstCol) {
        setColToZero(matrix, 0, M);
    }

    if (zeroInFirstRow) {
        setRowToZero(matrix, 0, N);
    }

}

void setRowToZero(vector<vector<int>> &matrix, size_t rowIndex, size_t N)
{
    for(size_t j=0; j<N; j++) {
        matrix[rowIndex][j] = 0;
    }
}

void setColToZero(vector<vector<int>> &matrix, size_t colIndex, size_t M)
{
    for(size_t i=0; i<M; i++) {
        matrix[i][colIndex] = 0;
    }
}

TEST_CASE("1.8 - Set row and column to 0") {
    vector<vector<int>> matrix { {1,2,3,4,5},
                                 {1,2,0,4,5},
                                 {1,2,3,4,5},
                                 {1,2,3,4,5}};
    vector<vector<int>> matrix2 {{1,2,0,4,5},
                                 {1,2,3,4,5},
                                 {0,2,3,4,5},
                                 {1,2,3,4,5}};

    vector<vector<int>> output { {1,2,0,4,5},
                                 {0,0,0,0,0},
                                 {1,2,0,4,5},
                                 {1,2,0,4,5}};
    vector<vector<int>> output2 {{0,0,0,0,0},
                                 {0,2,0,4,5},
                                 {0,0,0,0,0},
                                 {0,2,0,4,5}};

    SECTION("Indexes") {
        zeroMatrixIndexes(matrix);
        zeroMatrixIndexes(matrix2);
        REQUIRE(matrix == output);
        REQUIRE(matrix2 == output2);
    }

    SECTION("InPlace") {
        zeroMatrixInPlace(matrix);
        zeroMatrixInPlace(matrix2);
        REQUIRE(matrix == output);
        REQUIRE(matrix2 == output2);
    }
}
