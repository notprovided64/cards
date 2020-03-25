#include <iostream>
#include <vector>
#include <cstdlib>
#include <random>
#include "card.hpp"
#include "cards.hpp"

int main(int argc, const char * argv[])
{
    Cards deck = Cards::makeStandardDeck(true);
    deck.dump();
    puts("\n6 cards from deck:");
    Cards six = deck.getCards(6);
    six.dump();

    return 0;
}
