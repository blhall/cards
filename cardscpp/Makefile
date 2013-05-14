CC = g++
CFLAGS = -Wall
PROG = poker

SRCS = Card.cpp Deck.cpp Pot.cpp Hand.cpp Player.cpp poker.cpp

all: $(PROG)

$(PROG): $(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS)

clean:
	rm -f $(PROG)
