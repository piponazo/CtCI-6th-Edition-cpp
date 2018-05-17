#pragma once

// This file should be part of the private implementation of the library

#include "ICard.h"

struct CardDefault final: public ICard
{
public:
    CardDefault(const std::string& suit, int number);
    std::string suitName() const override;
    int number() const override;
    int value() const override;
private:
    std::string _suit;
    int _number;
};
