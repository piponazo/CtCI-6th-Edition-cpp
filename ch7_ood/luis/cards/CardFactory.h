#pragma once

#include "ICard.h"

#include <memory>

enum class CardType {
    Default,
    Blackjack,
};

std::unique_ptr<ICard> createCard (CardType type, const std::string& suit, int number);
