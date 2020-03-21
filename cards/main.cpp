#include <iostream>
#include <vector>
#include <cstdlib>
#include <random>

enum NUMBER {one, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king};
enum SUIT {club, diamond, heart, spade};

struct Card
{
     int number;
     int suit;
};

struct Cards
{
	std::vector<Card> order;
};

std::string NUMBER_string(int card)
{
    switch (card)
    {
        case 0:
            return "one";
        case 1:
            return "two";
        case 2:
            return "three";
        case 3:
            return "four";
        case 4:
            return "five";
        case 5:
            return "six";
        case 6:
            return "seven";
        case 7:
            return "eight";
        case 8:
            return "nine";
        case 9:
            return "ten";
        case 10:
            return "jack";
        case 11:
            return "queen";
        case 12:
            return "king";
        default:
            return "error";
            break;
    }
}
std::string SUIT_string(int card)
{
    switch (card)
    {
        case 0:
            return "club";
        case 1:
            return "diamond";
        case 2:
            return "heart";
        case 3:
            return "spade";
        default:
            return "error";
            break;
    }
}

void printCards(Cards cards)
{
    for(int i=0; i<cards.order.size(); ++i)
    {
        printf("Your card is a %s of %s \n",NUMBER_string(cards.order[i].number).c_str(), SUIT_string(cards.order[i].suit).c_str());
    }
}

Cards makeStdDeck()
{
    Cards deck;
	for (int i = one; i != king+1; i++)
	{
   		for (int j = club; j != spade+1; j++)
   		{
			Card mid;
			mid.number=i;
			mid.suit=j;
			deck.order.push_back(mid);
   		}    
	}    return deck;
}

Cards shuffleCards(Cards cards)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::shuffle(cards.order.begin(), cards.order.end(), gen);
    return cards;
}

Cards dealHand(Cards cards)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<std::mt19937::result_type> dist6(1,6);
    
    return cards;
}

int main(int argc, const char * argv[])
{
    Card ThreeOfSpades;
    ThreeOfSpades.number=three;
    ThreeOfSpades.suit=spade;
	
	Cards deck = makeStdDeck();
    
    printCards(deck);
	
    printf("\nnow to shuffle \n\n");
    
    deck = shuffleCards(deck);
    
    printCards(deck);
    
    return 0;
}
