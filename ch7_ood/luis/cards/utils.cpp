#include "utils.h"

#include <vector>
#include <algorithm>

bool validSuit(const std::string& name) {
    return std::any_of(begin(validSuits), end(validSuits), [&name](const auto& s) {
        return s == name;});
}

bool validNumber(int number) {
    return number >= 1 && number <=13;
}
