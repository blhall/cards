#include "Deck.h"
#include <iostream>
#include <algorithm>  //std::random_shiffle
#include <ctime>      //std::time
#include <cstdlib>    //std::rand, std::srand
#include <vector>     //std::vector

int myrandom (int i) { return std::rand()%i;}

Deck::Deck() {
  this->loadDeck();
}

Card Deck::nextCard() {
  Card c = this->deck.front();
  this->deck.erase(this->deck.begin());
  return c;
}

void Deck::shuffle(int times) {
  std::srand ( unsigned ( std::time(0) ) );
  std::cout << "Shuffling deck " << times << " times." << std::endl;

  for(int k = 0; k < times; k++) {
    std::random_shuffle ( this->deck.begin(), this->deck.end(), myrandom );
  }
}

void Deck::listCards() {
  int count = 1;
  for(unsigned int i = 0; i != this->deck.size(); i++) {
    count++;
    this->deck[i].toS();
  }
  std::cout << "There were " << count << " cards listed." << std::endl;
}

int Deck::deckSize() {
  return this->deck.size();
}

void Deck::loadDeck() {
  for(int i = 1; i <= 4; i++) {
    for(int j = 1; j <= 13; j++) {
      this->deck.push_back(Card(i, j));
    }
  }
}
