#include "Hand.h"
#include <vector> //std::Vector
#include <algorithm> //std::sort
#include <iostream>

Hand::Hand() {
}

void Hand::addCard(Card card) {
  std::cout << "Added " << card.toS() << " to hand." << std::endl;
  this->cards.push_back(card);
}

void Hand::clear() {
  this->cards.erase( this->cards.begin(), this->cards.end() );
}

void Hand::listCards() {
  for(unsigned int i = 0; i < this->cards.size(); i++) {
    std::cout << this->cards[i].toS() << std::endl;
  }
}

int Hand::checkHand() {
  // This will run through each of the possibilities from highest ranked hand to lowest.
  //
  // First I think it would be easier to make a list of all suites in hand and all ranks in hand.
  std::vector<int> suits;
  std::vector<int> ranks;
  for(unsigned int i = 0; i < this->cards.size(); i++) {
    suits.push_back(this->cards[i].getSuit());
    ranks.push_back(this->cards[i].getRank());
    if (this->cards[i].getRank() == 1) {
      //Also add ace to end (14) for consecutive checks
      ranks.push_back(14);
    }
  }
  //Sort both Vectors.
  std::sort (suits.begin(), suits.end());
  std::sort (ranks.begin(), ranks.end());

  bool flush = false;
  bool straight = false;

  //Determine if we have a flush
  for(unsigned int i = 0; i < suits.size(); i++) {
    switch (suits[i]) {
      case 1:
        this->heartCount++;
        break;
      case 2:
        this->diamondCount++;
        break;
      case 3:
        this->clubCount++;
        break;
      case 4:
        this->spadeCount++;
        break;
    }
  }
  if((heartCount >= 5) ||
     (diamondCount >= 5) ||
     (clubCount >= 5) ||
     (spadeCount >= 5)) 
  {
    flush = true;
  }

  //Determine if we have a straight.
  int previous = 0;
  int conCnt = 0;
  int rankTotals;
  for(unsigned int i = 0; i < ranks.size(); i++) {
    rankTotals += ranks[i];
    if (i == 0) {
      previous = ranks[i];
    }
    else {
      if (previous + 1 == ranks[i]) {
        conCnt++;
        previous = ranks[i];
      }
      else {
        conCnt = 0;
        previous = ranks[i];
      }
    }
    if (conCnt >= 5) {
      straight = true;
    }
  }

  // At this point we should know if we have a Straight or Flush so we can start to filter
  // out impossible hands.
  //
  //Royal Flush: 10-Jack-Queen-King-Ace
  //6000 +value of 4 added together
  if (flush && straight) {
  }
  //Straight Flush: Any 5 in a row of same suit
  //5000 + values of faces added
  if (flush && straight) {
   this->handValue = 5000 + rankTotals;
  }
  //Four of a Kind
  //4000 + value of 4 added together
  //
  //Full House: 1 Pair and 3 of a kind
  //3000 + values of ranks added
  //
  //Flush: 5 of same suit
  //2000 + values of ranks added
  if (flush) {
    this->handValue = 2000 + rankTotals;
  }
  //Straight: any 5 ranks in a row
  //1000 + values of ranks added
  if (straight) {
    this->handValue = 1000 + rankTotals;
  }
  //Three of a Kind
  //900 + values
  //
  //Two Pair
  //800 + values
  //
  //One Pair
  //500 + values
  return this->handValue;
}
