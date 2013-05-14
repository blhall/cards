require 'card'
class Array
  def shuffle!
    size.downto(1) { |n| push delete_at(rand(n)) }
    self
  end
end

class Deck

  @cards = Array.new

  def shuffle
    @cards.shuffle!
  end

  def initialize
    @cards = loadDeck()
  end

  def list_cards
    @cards.each do |card|
      puts card
    end
  end

  def deck_size
    @cards.length
  end

  def next_card
    @cards.shift
  end

private
  def loadDeck
    deck = Array.new
    suits = ['Hearts',
             'Spades',
             'Diamonds',
             'Clubs']

    numbers = {
              'Ace'   => 11,
              'Two'   => 2,
              'Three' => 3,
              'Four'  => 4,
              'Five'  => 5,
              'Six'   => 6,
              'Seven' => 7,
              'Eight' => 8,
              'Nine'  => 9,
              'Ten'   => 10,
              'Jack'  => 10,
              'Queen' => 10,
              'King'  => 10
             }

    suits.each do |suit|
      numbers.each do |number, value|
        card = Card.new(suit,number,value)
        deck <<  card
      end
    end
    return deck
  end
end
