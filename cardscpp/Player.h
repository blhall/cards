#include "Hand.h"
#include <string>
#include <vector>

class Player {
  private:
    //static int newUID;
    //const int uid;
    std::string name;
    int cash;
    int invested;
    bool allIn;
    int seat;
    int betCount;
  public:
    Hand* hand;
    Player(std::string n, int startingCash, int seat);
    Hand* getHand();
    int getBetCount();
    void clearBetCount();
    void check();
    void clearHand();
    void setHand(Hand* h);
    void addCard(Card c);
    //int getUid();
    std::string getName();
    int getInvested();
    int getCash();
    int getSeat();
    int addWinnings(int cash);
    bool bet(int wager);
};
