#include "CardFactory.h"

#include "CardDefault.h"
#include "CardBlackjack.h"

std::unique_ptr<ICard> createCard (CardType type, const std::string& suit, int number) {
    switch (type) {
        case CardType::Default:
            return std::make_unique<CardDefault>(suit, number);
        case CardType::Blackjack:
            return std::make_unique<CardBlackjack>(suit, number);
    }
}
