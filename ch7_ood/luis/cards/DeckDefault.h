#pragma once

#include "IDeck.h"

struct DeckDefault final : public IDeck
{
public:
    DeckDefault();
    const std::vector<std::unique_ptr<ICard>>& getCards() const override;
private:
    std::vector<std::unique_ptr<ICard>> _cards;
};
