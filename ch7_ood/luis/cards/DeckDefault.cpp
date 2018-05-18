#include "DeckDefault.h"
#include "CardFactory.h"
#include "utils.h"
#include "types.h"

DeckDefault::DeckDefault()
{
    _cards.reserve(validSuits.size() * 13);

    for (const auto& suit: validSuits) {
        std::string suitStr(suit.data(), suit.size());
        for (int i=1; i<=13; i++) {
            _cards.push_back(createCard(CardType::Default, suitStr, i));
        }
    }
}

const std::vector<std::unique_ptr<ICard> > &DeckDefault::getCards() const
{
    return _cards;
}
