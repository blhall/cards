#include "Player.h"

Player::Player(std::string n, int startingCash, int seat) {
  this->name = n;
  this->cash = startingCash;
  this->seat = seat;
  this->allIn = false;
  this->hand = new Hand();
}

Hand* Player::getHand() {
  return this->hand;
}

void Player::clearHand() {
  this->hand->clear();
}

void Player::setHand(Hand* h) {
  this->hand = h;
}

void Player::addCard(Card c) {
  this->hand->addCard(c);
}

std::string Player::getName() {
  return this->name;
}

int Player::getCash() {
  return this->cash;
}

int Player::getInvested() {
  return this->invested;
}

int Player::getSeat() {
  return this->seat;
}

int Player::addWinnings(int cash) {
  this->cash += cash;
  return this->cash;
}

bool Player::bet(int wager) {
 if (wager > this->cash) {
   return 0;
 }
 else {
   if (wager == this->cash) {
     this->allIn = true;
   }
   this->cash -= wager;
   this->invested += wager;
   return true;
 }
}
