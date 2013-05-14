require 'deck'

class Game
  attr_accessor :game_over, :money, :deck, :player_cards, :dealer_cards

  def initialize
    @game_over = false
    @hand_over = false
    @deck = Deck.new
    @player_cards = Array.new
    @dealer_cards = Array.new
  end

  def run!

    @deck.shuffle

  puts "Welcome to blackjack!"
  while(!@game_over)
      @hand_over = false
      #Initial Hand
      @player_cards << @deck.next_card
      @dealer_cards << @deck.next_card
      @player_cards << @deck.next_card
      @dealer_cards << @deck.next_card

      sleep(2)
      puts "++++++++++++\n+ New Hand +\n++++++++++++"

      while(!@hand_over)
        dealer_score = score_hand(@dealer_cards)
        player_score = score_hand(@player_cards)

        puts "Dealer has #{dealer_score}"
        puts "You have #{player_score}"

        puts "Enter your move. (hit, stay, quit)"
        move = gets.chomp

        if move == 'stay'
          while(dealer_score < 17)
            puts "Dealer hits."
            @dealer_cards << deck.next_card
            dealer_score = score_hand(@dealer_cards)
            puts "Dealer now has #{dealer_score}"
          end
          check_scores(score_hand(@player_cards), score_hand(@dealer_cards))

        elsif move == 'hit'
          card = deck.next_card
          @player_cards << card
          player_score = score_hand(@player_cards)
          puts "You now have #{player_score}"

          if score_hand(@player_cards) > 21
            puts "You Bust!"
            end_hand
          end

        elsif move == 'quit'
          @game_over = true
          end_hand
          puts "Thank you for playing!"
        end
      end
    end
  end

  def check_scores(player_score, dealer_score)
    puts "======================"
    puts "Dealer #{dealer_score} You #{player_score}"
    if player_score > 21
      puts "You bust!"
    elsif player_score == 21
      puts "You Win!"
    elsif dealer_score > 21
      puts "Dealer Busts, you win!"
    elsif player_score > dealer_score
      puts "You Win!"
    elsif player_score < dealer_score
      puts "Dealer Wins!"
    elsif player_score == dealer_score
      puts "Draw!"
    end

    end_hand
  end

  def score_hand(hand)
    score = 0
    hand.each do |card|
      score += card.values
    end
    return score
  end

  def end_hand
    @hand_over = true
    @dealer_cards.clear
    @player_cards.clear
    puts "======================"
  end

  def update
  end

  def draw
  end
end

game = Game.new
game.run!

