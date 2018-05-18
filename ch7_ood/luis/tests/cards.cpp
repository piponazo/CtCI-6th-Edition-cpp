#include <gtest/gtest.h>

#include "cards/CardFactory.h"
#include "cards/DeckFactory.h"

TEST(CardFactory, createsDefaultCard)
{
    const std::string expectedSuit {"clubs"};
    const int expectedNumber {1};

    auto card = createCard (CardType::Default, expectedSuit, expectedNumber);
    ASSERT_TRUE(card);
    ASSERT_EQ(expectedSuit, card->suitName());
    ASSERT_EQ(expectedNumber, card->number());
}

TEST(CardFactory, createsBlackjackCard)
{
    const std::string expectedSuit {"clubs"};
    const int expectedNumber {11};

    auto card = createCard (CardType::Blackjack, expectedSuit, expectedNumber);
    ASSERT_TRUE(card);
    ASSERT_EQ(expectedSuit, card->suitName());
    ASSERT_EQ(expectedNumber, card->number());
    ASSERT_EQ(10, card->value());
}

TEST(CardFactory, throwWithInvalidSuitName)
{
    EXPECT_THROW(createCard(CardType::Default, "yeah", 1), std::exception);
    EXPECT_THROW(createCard(CardType::Blackjack, "yeah", 1), std::exception);
}

TEST(CardFactory, throwWithInvalidNumber)
{
    EXPECT_THROW(createCard(CardType::Default, "clubs", 0), std::exception);
    EXPECT_THROW(createCard(CardType::Default, "clubs", 14), std::exception);
    EXPECT_THROW(createCard(CardType::Blackjack, "clubs", 0), std::exception);
    EXPECT_THROW(createCard(CardType::Blackjack, "clubs", 14), std::exception);
}


TEST(DeckFactory, createsDefaultDeck)
{
    auto deck = createDeck(CardType::Default);
    ASSERT_TRUE(deck);
    ASSERT_EQ(52, deck->getCards().size());
    ASSERT_EQ(13, deck->getCards()[12]->value());
}

TEST(DeckFactory, createsBlackjackDeck)
{
    auto deck = createDeck(CardType::Blackjack);
    ASSERT_TRUE(deck);
    ASSERT_EQ(52, deck->getCards().size());
    ASSERT_EQ(10, deck->getCards()[12]->value());
}
