#include "Pot.h"
#include <iostream>

Pot::Pot(int id, int val) {
  this->value = val;
  this->potId = id;
  this->highest = 0;
}

int Pot::getValue() {
  return this->value;
}

int Pot::getHighest() {
//  std::cout << "Highest investment in the pot is $" << this->highest << std::endl;
  return this->highest;
}

int Pot::addPot( int amount) {
  this->value += amount;
  if (amount > this->getHighest()) {
    highest = amount;
  }
  //std::cout << "Added $" << amount << " to the pot. Current value is $" << this->getValue() << std::endl;
  return this->value;
}
