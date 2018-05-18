#pragma once

#include <string>
#include <array>

constexpr std::array<std::string_view, 4> validSuits {"clubs", "diamonds", "hearts", "spades"};

// Check if the suit name is valid.
bool validSuit(const std::string& name);

// Check if the card number is in the range [1,13].
bool validNumber(int number);
