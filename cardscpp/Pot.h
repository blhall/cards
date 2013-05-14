class Pot {
  private:
    int value; //Keep track of each pots value.
    int potId; //An ID to keep track of open pots. Side pot and etc.
  public:
    Pot(int val, int id);
    int addPot(int amount); //Returns the new value of the pot
    int getValue();// Returns the current pot value.
};
