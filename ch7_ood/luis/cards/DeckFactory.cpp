#include "DeckFactory.h"
#include "DeckDefault.h"
#include "DeckBlackjack.h"

std::unique_ptr<IDeck> createDeck(CardType type) {
    switch (type) {
        case CardType::Default:
            return std::make_unique<DeckDefault>();
        case CardType::Blackjack:
            return std::make_unique<DeckBlackjack>();
            return nullptr;
    }
}
