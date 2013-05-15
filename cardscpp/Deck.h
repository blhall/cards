#include "Card.h"
#include <vector>

class Deck {
  private:
    void loadDeck();
  public:
    Deck();
    std::vector<Card> deck;
    
    void shuffle(int times = 2);    
    int deckSize();    
    Card nextCard();
    void discardNext();    
    void listCards();
};
