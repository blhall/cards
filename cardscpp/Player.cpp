#include "Player.h"
#include <iostream>

Player::Player(std::string n, int startingCash, int seat) {
  this->name = n;
  this->cash = startingCash;
  this->seat = seat;
  this->allIn = false;
  this->hand = new Hand();
  this->invested = 0;
  this->betCount = 0;
}

int Player::getBetCount() {
//  std::cout << this->name << " has " << this->betCount << "bet counts" << std::endl;
  return this->betCount;
}

void Player::clearBetCount() {
  this->betCount = 0;
}

void Player::check() {
  this->betCount += 1;
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
  std::cout << "Added " << c.toS() << " to player " << this->name << "'s hand." << std::endl;
  this->hand->addCard(c);
}

std::string Player::getName() {
  return this->name;
}

int Player::getCash() {
  return this->cash;
}

int Player::getInvested() {
 // std::cout << "Player " << this->name << " has invested $" << this->invested << " to the current pot." << std::endl;
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
   //Remove bet from wallet
   this->cash -= wager;
   //Add bet to invested.
   this->invested += wager;
   //Add bet to count.
   this->betCount += 1;
   return true;
 }
}
