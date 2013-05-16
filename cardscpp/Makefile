CC = g++
CFLAGS = -Wall
PROG = game

SRCS = Card.cpp Deck.cpp Pot.cpp Hand.cpp Player.cpp Poker.cpp

all: $(PROG)

$(PROG): $(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS)

clean:
	rm -f $(PROG)
