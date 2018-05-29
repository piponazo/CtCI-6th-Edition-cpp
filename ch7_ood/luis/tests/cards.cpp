#include "catch.hpp"

#include "cards/CardFactory.h"
#include "cards/DeckFactory.h"

TEST_CASE("createsDefaultCard", "CardFactory")
{
    const std::string expectedSuit {"clubs"};
    const int expectedNumber {1};

    auto card = createCard (CardType::Default, expectedSuit, expectedNumber);
    REQUIRE(card);
    REQUIRE(expectedSuit == card->suitName());
    REQUIRE(expectedNumber == card->number());
}

TEST_CASE("createsBlackjackCard", "CardFactory")
{
    const std::string expectedSuit {"clubs"};
    const int expectedNumber {11};

    auto card = createCard (CardType::Blackjack, expectedSuit, expectedNumber);
    REQUIRE(card);
    REQUIRE(expectedSuit == card->suitName());
    REQUIRE(expectedNumber == card->number());
    REQUIRE(10 == card->value());
}

TEST_CASE("throwWithInvalidSuitName", "CardFactory")
{
    REQUIRE_THROWS_AS(createCard(CardType::Default, "yeah", 1), std::exception);
    REQUIRE_THROWS_AS(createCard(CardType::Blackjack, "yeah", 1), std::exception);
}

TEST_CASE("throwWithInvalidNumber", "CardFactory")
{
    REQUIRE_THROWS_AS(createCard(CardType::Default, "clubs", 0), std::exception);
    REQUIRE_THROWS_AS(createCard(CardType::Default, "clubs", 14), std::exception);
    REQUIRE_THROWS_AS(createCard(CardType::Blackjack, "clubs", 0), std::exception);
    REQUIRE_THROWS_AS(createCard(CardType::Blackjack, "clubs", 14), std::exception);
}


TEST_CASE("createsDefaultDeck", "DeckFactory")
{
    auto deck = createDeck(CardType::Default);
    REQUIRE(deck);
    REQUIRE(52 == deck->getCards().size());
    REQUIRE(13 == deck->getCards()[12]->value());
}

TEST_CASE("createsBlackjackDeck", "DeckFactory")
{
    auto deck = createDeck(CardType::Blackjack);
    REQUIRE(deck);
    REQUIRE(52 == deck->getCards().size());
    REQUIRE(10 == deck->getCards()[12]->value());
}
