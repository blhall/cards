// This will hold the game and possibly the rule logic for poker.
#include "Deck.h"
#include "Player.h"
#include "Pot.h"
#include <iostream>
#include <vector>     //std::vector

void round() {
}

bool bettingLoop() {
  std::cout << "Betting starting." << std::endl;
  // This will loop through the players until all betting is done.
  // All players will have had to check or bet. It will continue to loop until
  // everyone's investment is the same or all-in.
  std::cout << "Betting is all done." << std::endl;
  return true;
}

void game(std::vector<Player*> players) {
  std::vector <Card*> discards;
  Hand* house = new Hand();
  //Pot* pot = new Pot(0,0);

  Deck* mydeck = new Deck;
  mydeck->shuffle();
  
  // Pocket Cards Dealt
  for(int i = 0; i < 2; i++) {
    // Cycle for 2 cards.
    for(unsigned int p = 0; p < players.size(); p++) {
      // For each player
      players[p]->addCard(mydeck->nextCard());
    }
  }
//  bettingLoop();

  //Flop Logic
  //Discard top Card
//  std::cout << "Discarding top card." << std::endl;
  //discards.push_back(mydeck->nextCard());
  mydeck->discardNext();  
//  std::cout << "The flop is..." << std::endl;
  for(int i = 0; i < 3; i++) {
    // We want three cards.
    house->addCard(mydeck->nextCard());
  }
//  bettingLoop();
  
  //Turn Logic
  //Discard top Card
//  std::cout << "Discarding top card." << std::endl;
  //discards.push_back(mydeck->nextCard());
  mydeck->discardNext();
//  std::cout << "The turn is..." << std::endl;
  //Draw turn card
  house->addCard(mydeck->nextCard());
//  bettingLoop();
  
  //River Logic
  //Discard top Card
//  std::cout << "Discarding top card." << std::endl;
  //discards.push_back(mydeck->nextCard());
  mydeck->discardNext();
//  std::cout << "The river is..." << std::endl;
  //Draw river card.
  house->addCard(mydeck->nextCard());
//  bettingLoop();
  //ShowDown Logic
//  std::cout << "The house has:" << std::endl;
  house->listCards();

  //For each player, determine hands
  for(unsigned int p = 0; p < players.size(); p++) {
     // For each player
    std::cout << "Player " << players[p]->getName() << " has:" << std::endl;
    players[p]->hand->checkHand(house);
  }
}

int main ()
{
  std::vector<Player*> players;

  // Create players
  Player * p1 = new Player("Brandon", 500, 1);
  Player * p2 = new Player("Dave", 500, 1);

  // Add players to list.
  players.push_back(p1);
  players.push_back(p2);

  // Start a game with given players.
  game(players);

  return 0;
}
