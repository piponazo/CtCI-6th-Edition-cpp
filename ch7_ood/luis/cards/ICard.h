#pragma once

#include <string>

// This file should be part of the library API

struct ICard {
    virtual ~ICard() = default;

    virtual std::string suitName() const = 0;

    // Digital value, from 1 to 13
    virtual int number() const = 0;

    // Numbers can have different values depending on the games
    virtual int value() const = 0;
};
