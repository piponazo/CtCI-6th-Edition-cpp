#include "CardDefault.h"

#include "utils.h"

#include <stdexcept>

CardDefault::CardDefault(const std::string& suit, int number):
    _suit(suit)
  , _number(number) {
      if (!validSuit(suit) || !validNumber(number)) {
          throw std::invalid_argument("Invalid suit or number");
      }
}

std::string CardDefault::suitName() const{
    return _suit;
}

int CardDefault::number() const{
    return _number;
}

int CardDefault::value() const{
    return _number;
}
