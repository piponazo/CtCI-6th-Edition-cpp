#include <gtest/gtest.h>

#include "cards/CardFactory.h"

TEST(CardFactory, createsDefaultCard)
{
    const std::string expectedSuit {"clubs"};
    const int expectedNumber {1};

    auto card = createCard (CardType::Default, expectedSuit, expectedNumber);
    ASSERT_TRUE(card);
    ASSERT_EQ(expectedSuit, card->suitName());
    ASSERT_EQ(expectedNumber, card->number());
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
