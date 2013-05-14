#include "Pot.h"

Pot::Pot(int val, int id) {
  this->value = val;
  this->potId = id;
}

int Pot::getValue() {
  return this->value;
}

int Pot::addPot( int amount) {
  this->value += amount;
  return this->value;
}
