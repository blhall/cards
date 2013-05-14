#include "Card.h"
#include <vector>
using namespace std;

class Deck {
  private:
    void loadDeck();
  public:
    Deck();
    vector<Card> deck;
    
    void shuffle(int times = 2);
    
    int deckSize();
    
    Card nextCard();
    
    void listCards();
};
