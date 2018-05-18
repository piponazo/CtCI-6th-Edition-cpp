// Deck of cards: Design the data structures for a generic deck of cards. Explain how you would
// subclass the data structures to implement blackjack.
//
// Notes about the generic deck of cards:
// - 13 ranks of the four French suits: clubs, diamonds, hearts, spades.
// - Each suit includes:
//      - ace (single symbol of its suit)
//      - king
//      - queen
//      - jack
//      - 2 to 10
// - Additionally from 1 to 6 jokers, one being more colorful (some games require these cards)
// - king, queen and jack are called Face Cards, because they have pictures of their names.
//
// Notes about the blackjack:
// Players: 2 to 7
// Cards: 52 to 416

#include <cards/DeckFactory.h>

#include <iostream>

using namespace std;

ostream& operator<< (ostream& os, const ICard& c) {
    os << "Card: " << c.suitName() << " - number: " << c.number() << " - value: " << c.value();
}

int main() {
    {
        cout << "Default deck: \n";
        auto deck = createDeck(CardType::Default);
        for (const auto& card: deck->getCards()) {
            cout << *card << endl;
        }
    }

    {
        cout << "Blackjack deck: \n";
        auto deck = createDeck(CardType::Blackjack);
        for (const auto& card: deck->getCards()) {
            cout << *card << endl;
        }
    }
}
