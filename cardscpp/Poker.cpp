// This will hold the game and possibly the rule logic for poker.
#include "Deck.h"
#include "Player.h"
#include "Pot.h"
#include <iostream>
#include <vector>     //std::vector


void round() {
}

void clearBets(std::vector<Player*> players) {
  for(unsigned int i = 0; i < players.size(); i++) {
    players[i]->clearBetCount();
  }
}

bool doneBetting(std::vector<Player*> players) {
  int highestInvested = 0;
  
  //Find highest count
  for(unsigned int i = 0; i < players.size(); i++) {
    if (players[i]->getInvested() > highestInvested) {
      highestInvested = players[i]->getInvested();
    }
  }
  //std::cout << "Betting loop: " << highestInvested << std::endl;

  //Make sure everyone has same amount of bets
  for(unsigned int i = 1; i < players.size(); i++) {
    if (players[i]->getBetCount() == 0) {
      return false;
    }
    if (players[i]->getInvested() != highestInvested) {
      return false;
    }
  }
  return true;
}

bool bettingLoop(Pot* pot, std::vector<Player*> players) {
  std::cout << "Betting starting." << std::endl;


  // This will loop through the players until all betting is done.
  // All players will have had to check or bet. It will continue to loop until
  // everyone's investment is the same or all-in.

  while(!doneBetting(players)) {
    for(unsigned int i = 0; i < players.size(); i++) {
      if (players[i]->getInvested() != pot->getHighest()) {
        int diff = 0;
        diff = pot->getHighest() - players[i]->getInvested();
//        std::cout << "The pot has $" << pot->getValue() << " in it. Player owes: " << diff << std::endl;
        // Prompt with Bet, Raise, and Fold
        players[i]->bet(diff);
      }
      else {
        // Prompt with Check or Raise
        //players[i]->check();
      }
    }
  }
  return true;
}

void game(std::vector<Player*> players) {

  std::vector<Card> discards;
  Hand * house = new Hand();

  Deck * mydeck = new Deck();
  mydeck->shuffle();
 
  std::cout << "Done Shuffling, dealing." << std::endl;
  // Pocket Cards Dealt
  for(int i = 0; i < 2; i++) {
    // Cycle for 2 cards.
    for(unsigned int p = 0; p < players.size(); p++) {
      // For each player
      players[p]->addCard(mydeck->nextCard());
    }
  }

  // Setup pot and blinds.
  int potID = 0;
  int smBlind = 10;
  int bgBlind = 20;
  Pot* pot = new Pot(potID,0);

  // Blinds: The order of players will be re-ordered after each round
  // Small blind is always 0
  // Big blind is always 1

  clearBets(players); // Clear previous counts.

  pot->addPot(players[0]->bet(smBlind)); // Small blind
  pot->addPot(players[1]->bet(bgBlind)); // Big blind

  //Start betting.
  bettingLoop(pot, players);

  //Flop Logic
  //Discard top Card
//  std::cout << "Discarding top card." << std::endl;
  discards.push_back(mydeck->nextCard());
  //mydeck->discardNext();  
//  std::cout << "The flop is..." << std::endl;
  for(int i = 0; i < 3; i++) {
    // We want three cards.
    house->addCard(mydeck->nextCard());
  }
//  bettingLoop();
  
  //Turn Logic
  //Discard top Card
//  std::cout << "Discarding top card." << std::endl;
  discards.push_back(mydeck->nextCard());
  //mydeck->discardNext();
//  std::cout << "The turn is..." << std::endl;
  //Draw turn card
  house->addCard(mydeck->nextCard());
//  bettingLoop();
  
  //River Logic
  //Discard top Card
//  std::cout << "Discarding top card." << std::endl;
  discards.push_back(mydeck->nextCard());
//  mydeck->discardNext();
//  std::cout << "The river is..." << std::endl;
  //Draw river card.
  house->addCard(mydeck->nextCard());
//  bettingLoop();
  //ShowDown Logic
  std::cout << "The house has:" << std::endl;
  house->listCards();

  //For each player, determine hands
  for(unsigned int p = 0; p < players.size(); p++) {
     // For each player
    std::cout << players[p]->getName() << " has:" << std::endl;
    players[p]->hand->checkHand(house);
  }
}

int main ()
{
  std::vector<Player*> players;

  // Create players
  Player * p1 = new Player("Brandon", 500, 1);
  Player * p2 = new Player("Dave", 500, 1);
  Player * p3 = new Player("Ryan", 500, 1);
  Player * p4 = new Player("Chad", 500, 1);

  // Add players to list.
  players.push_back(p1);
  players.push_back(p2);
  players.push_back(p3);
  players.push_back(p4);

  // Start a game with given players.
  game(players);

  return 0;
}
