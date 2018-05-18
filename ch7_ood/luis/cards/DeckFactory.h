#pragma once

#include "IDeck.h"
#include "types.h"

#include <memory>

std::unique_ptr<IDeck> createDeck(CardType type);
