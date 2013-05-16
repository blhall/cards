#include "Hand.h"
#include <vector> //std::Vector
#include <algorithm> //std::sort
#include <iostream>

Hand::Hand() {
}

void Hand::addCard(Card card) {
 // std::cout << "Added " << card.toS() << " to hand." << std::endl;
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

int Hand::checkHand(Hand* house) {
  // This will run through each of the possibilities from highest ranked hand to lowest.
  //
  // First I think it would be easier to make a list of all suites in hand and all ranks in hand.
  std::vector<int> suits;
  std::vector<int> ranks;

  //This hand
  for(unsigned int i = 0; i < this->cards.size(); i++) {
    suits.push_back(this->cards[i].getSuit());
    ranks.push_back(this->cards[i].getRank());
    if (this->cards[i].getRank() == 1) {
      //Also add ace to end (14) for consecutive checks
      ranks.push_back(14);
    }
  }

  //House hand
  for(unsigned int h = 0; h < house->cards.size(); h++) {
    suits.push_back(house->cards[h].getSuit());
    ranks.push_back(house->cards[h].getRank());
    if (house->cards[h].getRank() == 1) {
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
  // Duplicate checks
  int pairCount = 0;
  int tripCount = 0;
  int highCard  = 0;
  bool fourOfKind = false;

  for(int i = 1; i < 15; i++) {
    int mycount  = std::count (ranks.begin(), ranks.end(), i);
    if (mycount == 1) {
      highCard = i;
    }
    else if (mycount == 2) {
      std::cout << "----> A Pair of " << i << "'s" << std::endl;
      pairCount++;
    }
    else if (mycount == 3) {
      std::cout << "----> Three of a kind with " << i << "'s" << std::endl;
      tripCount++;
    }
    else if (mycount == 4) {
      std::cout << "----> Four of a kind with " << i << "'s" << std::endl;
      fourOfKind = true;
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
    std::cout << "---->  Straight flush!" << std::endl;
    this->handValue = 5000 + rankTotals;
    return this->handValue;
  }
  //Four of a Kind
  //4000 + value of 4 added together
  if (fourOfKind) {
    std::cout << "---->  Four of a Kind!" << std::endl;
    this->handValue = 4000 + rankTotals;
    return this->handValue;
  }
  //Full House: 1 Pair and 3 of a kind
  //3000 + values of ranks added
  if (tripCount >= 1) {
    if (pairCount >= 1) {
      std::cout << "---->  Full House!" << tripCount << std::endl;
      this->handValue = 2000 + rankTotals;
      return this->handValue;
    }
  }
  //Flush: 5 of same suit
  //2000 + values of ranks added
  if (flush) {
    std::cout << "---->  Flush!" << std::endl;
    this->handValue = 2000 + rankTotals;
    return this->handValue;
  }
  //Straight: any 5 ranks in a row
  //1000 + values of ranks added
  if (straight) {
    std::cout << "---->  Straight!" << std::endl;
    this->handValue = 1000 + rankTotals;
    return this->handValue;
  }
  //Three of a Kind
  //900 + values
  if (tripCount > 0) {
    std::cout << "---->  Three of a Kind!" << std::endl;
    this->handValue = 900 + rankTotals;
    return this->handValue;
  }
  //Two Pair
  //800 + values
  if (pairCount > 1) {
    std::cout << "---->  Two Pairs!" << std::endl;
    this->handValue = 800 + rankTotals;
    return this->handValue;
  }
  //One Pair
  //500 + values
  if (pairCount > 0) {
    std::cout << "---->  A pair!" << std::endl;
    this->handValue = 500 + rankTotals;
    return this->handValue;
  }
  // High Card
  std::cout << "---->  High card of !" << highCard << std::endl;
  this->handValue = 100 + rankTotals;

  return this->handValue;
}
