#pragma once

#include "ICard.h"

#include <vector>
#include <memory>

// This file should be part of the library API

struct IDeck
{
    virtual ~IDeck() = default;

    virtual const std::vector<std::unique_ptr<ICard>>& getCards() const = 0;
};
