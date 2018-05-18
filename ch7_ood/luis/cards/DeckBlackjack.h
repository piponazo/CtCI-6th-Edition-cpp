#pragma once

#include "IDeck.h"

struct DeckBlackjack final : public IDeck
{
public:
    DeckBlackjack();
    const std::vector<std::unique_ptr<ICard>>& getCards() const override;
private:
    std::vector<std::unique_ptr<ICard>> _cards;
};
