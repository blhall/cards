#ifndef CARD_H
#define CARD_H
#include <string>
class Card {
  private:
    int suit;
    int rank;
    std::string suitName;
    std::string rankName;
    int bitvalue;
  public:
    Card(int s, int r);
    int getSuit();
    int getRank();
    std::string getSuitName();
    std::string getRankName();
    std::string toS();
};
#endif
