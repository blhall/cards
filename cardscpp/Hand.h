#include "Card.h"
#include <vector>

class Hand {
  private:
    int checkHand();
    int handValue, heartCount, diamondCount, spadeCount, clubCount;
  public:
    Hand();
    std::vector<Card> cards;
    void addCard(Card c);
    void listCards();
    void clear();
};
