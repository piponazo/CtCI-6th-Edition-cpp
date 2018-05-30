// Zero Matrix: Write an algorithm such that if an element in an MxN matrix is 0, its entire row and colmn are set to 0

#include "catch.hpp"
#include <vector>
#include <queue>

using namespace std;

void zeroMatrix(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix.front().empty()) {
        return;
    }
    const size_t M = matrix.size();
    const size_t N = matrix.front().size();
    queue<size_t> rows, columns;

    for(size_t i=0; i<M; i++) {
        if (matrix[i].size() != N) {
            throw runtime_error("internal vector with different size than the first one");
        }

        for(size_t j=0; j<N; j++) {
            if (matrix[i][j] == 0) {
                rows.push(i);
                columns.push(j);
                break;
            }
        }
    }

    while (rows.size()) {
        const size_t row = rows.front();
        rows.pop();
        for(size_t j=0; j<N; j++) {
            matrix[row][j] = 0;
        }
    }

    while(columns.size()) {
        const size_t column = columns.front();
        columns.pop();
        for(size_t i=0; i<M; i++) {
            matrix[i][column] = 0;
        }

    }
}

TEST_CASE("Set row and column to 0") {
    vector<vector<int>> matrix { {1,2,3,4,5},
                                 {1,2,0,4,5},
                                 {1,2,3,4,5},
                                 {1,2,3,4,5}};
    zeroMatrix(matrix);
    REQUIRE(matrix ==  vector<vector<int>>{ {1,2,0,4,5},
                                            {0,0,0,0,0},
                                            {1,2,0,4,5},
                                            {1,2,0,4,5}});
}
