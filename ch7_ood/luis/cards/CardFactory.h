#pragma once

#include "ICard.h"
#include "types.h"

#include <memory>

std::unique_ptr<ICard> createCard (CardType type, const std::string& suit, int number);
