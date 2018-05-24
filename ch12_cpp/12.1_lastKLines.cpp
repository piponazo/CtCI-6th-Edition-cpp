// Last K Lines: Write a method to print the last K lines of an input file using C++

#include "catch.hpp"
#include <fstream>

std::vector<std::string> getKLines(std::ifstream& file, int number) {
    std::vector<std::string> lines(number);
    std::string line;
    size_t counter = 0;
    while(std::getline(file, line)) {
        lines[counter++ % number] = line;
    }
    return lines;
}

TEST_CASE("get last K lines from file") {
    const std::string fileName{"tmpFile.txt"};

    {
        std::ofstream outFile(fileName);
        for (int i = 0; i<10; i++) {
            outFile << "line " << std::to_string(i) << std::endl;
        }
    }

    SECTION("number of lines is the expected") {
        const size_t number{5};
        std::ifstream inFile(fileName);
        REQUIRE(inFile.is_open());
        std::vector<std::string> lines = getKLines(inFile, number);
        REQUIRE(lines.size() == number);
    }

    SECTION("content of lines is expected") {
        const size_t number{2};
        std::ifstream inFile(fileName);
        REQUIRE(inFile.is_open());
        std::vector<std::string> lines = getKLines(inFile, number);
        REQUIRE(lines[0] == "line 8");
        REQUIRE(lines[1] == "line 9");
    }

    std::remove(fileName.c_str());
}
