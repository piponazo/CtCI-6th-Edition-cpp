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

#include <iostream>
#include <string>
#include <memory>
#include <vector>

using namespace std;

enum class Suits{
    Clubs,
    Diamonds,
    Hearts,
    Spades,
};
const int SUITS_NUMBER = 4;

//struct Suit {
//    string _name;
//};
// TODO: Consider to use a Suit structure to safe memory.
// If each card has a string, we will be duplicating strings.
// We could have a shared_ptr pointing to one of the four Suit instances.

struct Card {
    Card(const string& suit, int number);
    friend ostream& operator<< (ostream& os, const Card& c);

    string _suit;
    int _number;
};

struct Deck {
    Deck();
    vector<Card> _cards;
};


int main() {
    cout << "Deck of cards!\n";
    Deck deck;
    for (const auto& card: deck._cards) {
        cout << card << endl;
    }
}

Deck::Deck() {
    _cards.reserve(52);
    vector<string> suitNames {"Clubs", "Diamonds", "Hearts", "Spades"};

    for (const auto& suite: suitNames) {
        for (int number=1; number<=13; number++) {
            _cards.emplace_back(suite, number);
        }
    }
}

Card::Card(const string& suit, int number):
      _suit(suit)
    , _number(number)
{
}

ostream& operator<< (ostream& os, const Card& c) {
    os << "Card: " << c._suit << " - " << c._number;
}
