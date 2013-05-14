// This will hold the game and possibly the rule logic for poker.
#include "Deck.h"
#include "Player.h"
#include "Pot.h"
#include <iostream>
#include <vector>

std::vector <Card*> discards;
std::vector<Player*> players;

Hand* house = new Hand();
Pot* pot = new Pot(0,0);

Player * p1 = new Player("Brandon", 500, 1);
Player * p2 = new Player("Dave", 500, 1);

players.push_back(p1);
players.push_back(p2);

int main ()
{
  Deck* mydeck = new Deck;
  std::cout << "My deck has " << mydeck->deckSize() << " cards in it." << std::endl;
  mydeck->shuffle();
  std::cout << "My deck has " << mydeck->deckSize() << " cards in it." << std::endl;
  for(int i = 0; i < 5; i++) {
    Card card = mydeck->nextCard();
    std::cout << card.toS() << std::endl;
  }
  return 0;
}
