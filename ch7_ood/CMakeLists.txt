add_library(cards
    "luis/cards/ICard.h"
    "luis/cards/IDeck.h"
    "luis/cards/CardDefault.h"
    "luis/cards/CardDefault.cpp"
    "luis/cards/CardBlackjack.h"
    "luis/cards/CardBlackjack.cpp"
    "luis/cards/CardFactory.h"
    "luis/cards/CardFactory.cpp"
    "luis/cards/DeckFactory.h"
    "luis/cards/DeckFactory.cpp"
    "luis/cards/DeckDefault.h"
    "luis/cards/DeckDefault.cpp"
    "luis/cards/DeckBlackjack.h"
    "luis/cards/DeckBlackjack.cpp"
    "luis/cards/utils.h"
    "luis/cards/utils.cpp"
    "luis/cards/types.h"
)
target_include_directories(cards PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/luis)

add_executable(7.1_deck_of_cards luis/7.1_deck_of_cards.cpp)

target_link_libraries(7.1_deck_of_cards
    PRIVATE
        cards
)

add_executable(7_tests
    luis/tests/cards.cpp
    luis/tests/main.cpp
)

target_link_libraries(7_tests
    PRIVATE
        cards
)

target_include_directories(7_tests PRIVATE ${PROJECT_SOURCE_DIR}) # To find catch.hpp
