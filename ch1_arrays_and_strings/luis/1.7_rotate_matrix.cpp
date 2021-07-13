// 1.7 Rotate Matrix: Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes, write a
// method to rotate the image by 90 degrees. Can you do this in place?

// Example
// 1 2 3 4     5 1 5 1
// 5 6 7 8 --> 6 2 6 2
// 1 2 3 4     7 3 7 3
// 5 6 7 8     8 4 8 4
//
// rows go into columns
// in place?

// #51  - Try thinking about it layer by later. Can you rotate a specific layer?
// #100 - Rotating a specific alyer would just mean swapping the values in four arrays. If you were asked to swap
// values in two arrays, could you do this? can you then extend it to four arrays?

#include "catch.hpp"
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> rotateImage(const vector<vector<int>>&image) {
    if (image.empty()) {
        return {};
    }

    const size_t N = image.size();
    if (image.front().size() != N) {
        throw runtime_error("non square image");
    }

    vector<vector<int>> result(N, vector<int>(N));

    for(size_t r=0; r<N; r++) {
        for(size_t c=0; c<N; c++) {
            result[c][N-1-r] = image[r][c];
        }
    }

    return result;
}

bool rotateImageInPlace(vector<vector<int>>&image) {
    if (image.empty()) {
        return false;
    }

    const size_t N = image.size();
    if (image.front().size() != N) {
        return false;
    }

    for (size_t layer=0; layer<N/2; layer++) {
        size_t first = layer;
        size_t last = N - 1 - layer;
        for (size_t i=first; i<last; i++) {
            const size_t offset = i - first;
            const int top = image[first][i];

            // left -> top
            image[first][i] = image[last-offset][first];

            // bottom -> left
            image[last-offset][first] = image[last][last-offset];

            // right -> bottom
            image[last][last-offset] = image[i][last];

            // top -> right
            image[i][last] = top;
        }
    }
}

TEST_CASE("1.7 - rotate square image (4x4)") {
    SECTION("4x4")
    {
        vector<vector<int>> original { {1,2,3,4},
                                       {5,6,7,8},
                                       {1,2,3,4},
                                       {5,6,7,8}};

        vector<vector<int>> expected { {5,1,5,1},
                                       {6,2,6,2},
                                       {7,3,7,3},
                                       {8,4,8,4}};
        auto result = rotateImage(original);
        REQUIRE(result == expected);
    }
    SECTION("5x5")
    {
        vector<vector<int>> original { {1,2,3,4,5},
                                       {5,6,7,8,9},
                                       {1,2,3,4,5},
                                       {5,6,7,8,9},
                                       {1,2,3,4,5},
                                     };

        vector<vector<int>> expected { {1,5,1,5,1},
                                       {2,6,2,6,2},
                                       {3,7,3,7,3},
                                       {4,8,4,8,4},
                                       {5,9,5,9,5},
                                     };
        auto result = rotateImage(original);
        REQUIRE(result == expected);
    }
}

TEST_CASE("1.7 - rotate image of size 0") {
    vector<vector<int>> original;
    auto result = rotateImage(original);
    REQUIRE(result == original);
}


TEST_CASE("1.7 - does not rotate non-square image") {
    vector<vector<int>> original { {1,2,3,4},
                                   {5,6,7,8},
                                   {5,6,7,8}};
    REQUIRE_THROWS_AS(rotateImage(original), runtime_error);
}


TEST_CASE("1.7 - rotate square image (in-place)") {
    SECTION("4x4")
    {
        vector<vector<int>> original { {1,2,3,4},
                                       {5,6,7,8},
                                       {1,2,3,4},
                                       {5,6,7,8}};

        vector<vector<int>> expected { {5,1,5,1},
                                       {6,2,6,2},
                                       {7,3,7,3},
                                       {8,4,8,4}};

        REQUIRE(rotateImageInPlace(original));
        REQUIRE(original == expected);
    }
    SECTION("5x5")
    {
        vector<vector<int>> original { {1,2,3,4,5},
                                       {5,6,7,8,9},
                                       {1,2,3,4,5},
                                       {5,6,7,8,9},
                                       {1,2,3,4,5},
                                     };

        vector<vector<int>> expected { {1,5,1,5,1},
                                       {2,6,2,6,2},
                                       {3,7,3,7,3},
                                       {4,8,4,8,4},
                                       {5,9,5,9,5},
                                     };

        REQUIRE(rotateImageInPlace(original));
        REQUIRE(original == expected);
    }
}

TEST_CASE("1.7 - rotate image of size 0 (in-place)") {
    vector<vector<int>> original;
    REQUIRE_FALSE(rotateImageInPlace(original));
}


TEST_CASE("1.7 - does not rotate non-square image (in-place)") {
    vector<vector<int>> original { {1,2,3,4},
                                   {5,6,7,8},
                                   {5,6,7,8}};
    REQUIRE_FALSE(rotateImageInPlace(original));
}

//void printMat(const vector<vector<std::uint32_t>>& mat)
//{
//    const size_t N{mat.size()};
//    for(size_t row = 0; row<N; row++) {
//        for(size_t col = 0; col<N; col++) {
//            cout << mat[row][col] << " ";
//        }
//        cout << endl;
//    }
//}
