#include "CardBlackjack.h"

#include "utils.h"

#include <stdexcept>

CardBlackjack::CardBlackjack(const std::string& suit, int number):
    _suit(suit)
  , _number(number)
  , _value(number)
{
      if (!validSuit(suit) || !validNumber(number)) {
          throw std::invalid_argument("Invalid suit or number");
      }
      // Face cards --> value = 10
      if (number > 10) {
          _value = 10;
      }
      // Ace can be worth 1 or 11
}

std::string CardBlackjack::suitName() const{
    return _suit;
}

int CardBlackjack::number() const{
    return _number;
}

int CardBlackjack::value() const{
    return _number;
}
