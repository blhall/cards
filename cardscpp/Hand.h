#include "Card.h"
#include <vector>

class Hand {
  private:
    int handValue, heartCount, diamondCount, spadeCount, clubCount;
  public:
    Hand();
    std::vector<Card> cards;
    int checkHand(Hand* house);
    void addCard(Card c);
    void listCards();
    void clear();
};
