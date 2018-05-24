// Search in rotated array: Given a sorted array of n integers that has been rotated an unknown
// number of times, write code to find an element in the array. You may assume that the array was
// originally sorted in increasing order.
// EXAMPLE
// Input: find 5 in (15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14) [12 elements]
// Output: 8 (The index of 5 in the array)

#include "catch.hpp"
#include <vector>

// Give the index where the element is found
int binarySearch(const std::vector<int>& a, int value) {
    int low = 0;
    int high = a.size()-1;
    int mid;

    while(low <= high) {
        int mid = (low + high)/2;
        if (a[mid] < value) {
            low = mid+1;
        } else if (a[mid] > value) {
            high = mid-1;
        } else {
            return mid;
        }
    }
    return -1;
}

int binarySearchRecursive(const std::vector<int>& a, int value, int low, int high) {
    if (low > high) {
        return -1;
    }

    int mid = (low + high)/2;
    if (value < a[mid]) {
        return binarySearchRecursive(a, value, low, mid-1);
    } else if (value > a[mid]) {
        return binarySearchRecursive(a, value, mid+1, high);
    } else {
        return mid;
    }
}

// Give the index where the element is found
int binarySearchModified(const std::vector<int>& a, int value, int left, int right) {
// Input: find 5 in (15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14) [12 elements]
    int mid = (left + right)/2;

    if (a[left] < a[mid]) {         // Left is normally ordered

    } else if (a[right] > a[mid]) { // Right is normally ordered
        if (value >= a[left] && value < a[mid]) {   // search right
            return binarySearchModified(a, value, mid+1, right);
        } else {                                    // search left
            return binarySearchModified(a, value, left, mid-1);
        }
    }

    if (value < a[mid]) {
        return binarySearchRecursive(a, value, left, mid-1);
    } else if (value > a[mid]) {
        return binarySearchRecursive(a, value, mid+1, right);
    } else {
        return mid;
    }
}

TEST_CASE("binary search (iterative) in sorted array") {
    std::vector<int> a {1,2,3,4,5,6,7,8,9,10};
    SECTION("finds existing element") {
        REQUIRE(binarySearch(a, 3) == 2);
    }
    SECTION("returns -1 with non existing element") {
        REQUIRE(binarySearch(a, 500) == -1);
    }
}

TEST_CASE("binary search (recursieve) in sorted array") {
    std::vector<int> a {1,2,3,4,5,6,7,8,9,10};
    SECTION("finds existing element") {
        REQUIRE(binarySearchRecursive(a, 3, 0, a.size()-1) == 2);
    }
    SECTION("returns -1 with non existing element") {
        REQUIRE(binarySearchRecursive(a, 500, 0, a.size()-1) == -1);
    }
}

TEST_CASE("binary search in rotated sorted array") {
    std::vector<int> a {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
    SECTION("finds existing element") {
        REQUIRE(binarySearchModified(a, 5, 0, a.size()-1) == 8);
//        REQUIRE(binarySearchModified(a, 20) == 4);
    }
//    SECTION("returns -1 with non existing element") {
//        REQUIRE(binarySearch(a, 500) == -1);
//    }
}
