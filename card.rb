class Card
  attr_reader :suit, :number, :values

  def initialize(suit, number,values)
    @suit = suit
    @number = number
    @values = values
  end

  def to_s
    "#{@number} of #{@suit}."
  end
end
