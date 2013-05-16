class Pot {
  private:
    int highest; // Keeps track of current highest investment.
    int value; //Keep track of each pots value.
    int potId; //An ID to keep track of open pots. Side pot and etc.
  public:
    Pot(int id, int val);
    int getHighest();
    int addPot(int amount); //Returns the new value of the pot
    int getValue();// Returns the current pot value.
};
