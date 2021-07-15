// Sum lists: You have two numbers represented by a linked list, where each node contains a single digit. The digits
// are stored in reverse order, such that the 1's digit is at the head of the list. Write a function that adds the two
// numbers and returns the sum as a linked list:
//
// Example:
// Input   (7->1->6) + (5->9->2) : that is 617+295
// Output  (2->1->9). That is, 912
//
// Follow up:
// Suppose the digits are stored in forward order. Repeat the above problem
// Example:
// Input   (6->1->7) + (2->9->5) : that is 617+295
// Output  (9->1->2). That is, 912
//
// HINTS:
// #07 Of course, you could convert the linked list to integers, compute the sum, and then convert it back to a new
//      linked list. If you did this in an interview, your interviewer would likely accept the answer, and then see if
//      you could do this without converting it to a number and back.
// #30 try recursion. Suppose you have two lists, A = 1->5->9 (representing 951) and B = 2->3->6->7 (representing 7632),
//      and a function that operates on the remainder of the lists (5->9 and 3->6->7). Could you use this to create the
//      sum method? What is the relationship between sum (1->5->9,  2->3->6->7) and sum (5->9 and 3->6->7).
// #71  Make sure you have considered linked list that are not the same length.
// #95  Does your algorithm work on linked lists like 9->7->8 and 6->8->5? Double check that.
// #109 For the follow-up questions. The issue is that when the linked lists aren't the same length, the head of one
//      linked list might represent the 1000's place while the other represents the 10's place. What if you made them
//      the same length? is there a way to modify the linked list to do that, whithout changing the value it represents?

#include "catch.hpp"
#include "lists/utils.h"
#include <iostream>

//std::unique_ptr<Node> sumListsReversed(const Node* l1, const Node* l2) {
//    int sum = l1->value + l2->value;
//    int carried = sum < 10 ? 0: 1;
//    int digit = sum%10;

//    auto root = std::make_unique<Node>(digit);
//    Node* n = root.get();

//    while(1) {
//        int v1=0, v2=0;
//        if (l1 && l1->next) {
//            l1 = l1->next.get();
//            v1 = l1->value;
//        } else {
//            l1 = nullptr;
//        }
//        if (l2 && l2->next) {
//            l2 = l2->next.get();
//            v2 = l2->value;
//        } else {
//            l2 = nullptr;
//        }
//        if (!l1 && !l2) {
//            break;
//        }

//        sum = v1 + v2 + carried;
//        carried = (numDigits(sum) == 2);
//        digit = sum%10;

//        n->appendToTail(digit);
//        n = n->next.get();

//    };

//    if (carried)
//        n->appendToTail(1);

//    return root;
//}

/* July 2021 - Version with lists
unique_ptr<Node> sumListsReversed(const Node* l1, const Node* l2)
{
    unique_ptr<Node> result;
    Node* runner{nullptr};

    int carriage {0};
    while (l1 && l2) {
        int sum = l1->value + l2->value + carriage;
        if (sum > 10) {
            carriage = 1;
            sum = sum % 10;
        } else {
            carriage = 0;
        }

        if (!result) {
            result = make_unique<Node>(sum);
            runner = result.get();
        } else {
            runner = runner->appendToTail(sum);
        }

        l1 = l1->next.get();
        l2 = l2->next.get();
    }

    // Add missing values
    if (l1 || l2) {
        const Node* remaining = l1? l1 : l2;
        while (remaining) {
            runner = runner->appendToTail(remaining->value);
            remaining = remaining->next.get();
        }
    }

    return result;
}
*/


/* Version developed on July 2021. Not so nicely coded, but works.
int obtainValueFromListReversed(const Node* l1)
{
    const Node* runner = l1;
    int exp{0};
    int sum{0};

    while(runner) {
        sum += runner->value * std::pow(10, exp);
        runner = runner->next.get();
        exp++;
    }

    return sum;
}

unique_ptr<Node> createListFromValue(int value)
{
    unique_ptr<Node> result;
    Node* resultRunner{nullptr};

    do {
        int digit = value % 10;
        if (!result) {
            result = make_unique<Node>(digit);
            resultRunner = result.get();
        } else {
            resultRunner = resultRunner->appendToTail(digit);
        }
        value /= 10;
    } while (value > 0);

    return result;
}

unique_ptr<Node> sumListsReversed(const Node* l1, const Node* l2)
{
    int value1 = obtainValueFromListReversed(l1);
    int value2 = obtainValueFromListReversed(l2);
    int sum = value1 + value2;
    auto result = createListFromValue(sum);
    return result;
}
*/

std::tuple<int,int> sumDigits(const int a, const int b) {
    const int sum = a + b;
    int carried = sum < 10 ? 0 : 1;
    int digit = sum%10;
    return std::make_tuple(digit, carried);
}

std::unique_ptr<Node> sumListsReversed(const Node* l1, const Node* l2, int carried=0) {
    int value = carried;
    if (l1) {
        value += l1->value;
    }
    if (l2) {
        value += l2->value;
    }
    auto root = std::make_unique<Node>(value%10);
    bool carriedValue = (value >= 10);

    if ((l1 && l1->next) || (l2 && l2->next)) {
        root->next = std::move(sumListsReversed(l1->next.get(), l2->next.get(), carriedValue));
    } else if (carriedValue) {
        root->next = std::move(sumListsReversed(nullptr, nullptr, carriedValue));
    }

    return root;
}

TEST_CASE("sum lists in reversed order (same lengths)", "[2.5]") {
    auto l1 = createList({7,1,6});
    auto l2 = createList({5,9,2});
    auto l3 = sumListsReversed(l1.get(), l2.get());
    REQUIRE(convertListToVector(l3.get()) == std::vector<int>{2,1,9});
}

TEST_CASE("sum lists in reversed order (same lengths with carried value)", "[2.5]") {
    auto l1 = createList({7,1,6});
    auto l2 = createList({5,9,3});
    auto l3 = sumListsReversed(l1.get(), l2.get());
    REQUIRE(convertListToVector(l3.get()) == std::vector<int>{2,1,0,1});
}

TEST_CASE("sum lists in reversed order (different lengths)", "[2.5]") {
    auto l1 = createList({7,1,6});
    auto l2 = createList({5,9,2,1});
    auto l3 = sumListsReversed(l1.get(), l2.get());
    REQUIRE(convertListToVector(l3.get()) == std::vector<int>{2,1,9,1});
}
