require 'deck'

puts "Creating Deck Class."
d = Deck.new
puts "Deck Created."
puts "#{d.deck_size} cards in the deck."
puts "First card in deck is #{d.next_card}"
puts "Shuffling deck."
d.shuffle
puts "First card in deck is #{d.next_card}"
puts "#{d.deck_size} cards in the deck."
