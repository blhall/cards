#include "Card.h"
#include <iostream>
#include <string>

Card::Card(int s, int r) {
  this->suit = s;
  this->rank = r;

  switch ( s ) {
    case 1:
      this->suitName = "Hearts";
      break;
    case 2:
      this->suitName = "Diamonds";
      break;
    case 3:
      this->suitName = "Clubs";
      break;
    case 4:
      this->suitName = "Spades";
      break;
  }

  switch ( r ) {
    case 1:
      this->rankName = "Ace";
      break;
    case 2:
      this->rankName = "Two";
      break;
    case 3:
      this->rankName = "Three";
      break;
    case 4:
      this->rankName = "Four";
      break;
    case 5:
      this->rankName = "Five";
      break;
    case 6:
      this->rankName = "Six";
      break;
    case 7:
      this->rankName = "Seven";
      break;
    case 8:
      this->rankName = "Eight";
      break;
    case 9:
      this->rankName = "Nine";
      break;
    case 10:
      this->rankName = "Ten";
      break;
    case 11:
      this->rankName = "Jack";
      break;
    case 12:
      this->rankName = "Queen";
      break;
    case 13:
      this->rankName = "King";
      break;
  }
}

int Card::getSuit() {
  return this->suit;
}

int Card::getRank() {
  return this->rank;
}

std::string Card::getSuitName() {
  return this->suitName;
}

std::string Card::getRankName() {
  return this->rankName;
}

std::string Card::toS() {
  return this->rankName+" of "+this->suitName;
}
