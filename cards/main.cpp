#include <iostream>
#include <vector>
#include <cstdlib>
#include <random>

enum NUMBER : uint8_t {invalid_number, ace, two, three, four, five, six, seven,
                       eight, nine, ten, jack, queen, king};
enum SUIT : uint8_t {invalid_suit, club, diamond, heart, spade};

#define ENUM_TO_CSTR(e) case e: return #e; break

struct Card {
  
  union {
    uint8_t i;
    NUMBER e;
  } number;
  union {
    uint8_t i;
    SUIT e;
  } suit;
  
  Card(int n, int s) {
    number.i = n;
    suit.i = s;
  }

  Card(NUMBER n, SUIT s) {
    number.e = n;
    suit.e = s;
  }
  
  bool isValid() const {
    return ace <= number.i && number.i <= king && club <= suit.i && suit.i <= spade;
  }
  
  operator bool() const {
    return isValid();
  }

  std::string number_str() const {
      switch (number.e)
      {
          ENUM_TO_CSTR(ace);
          ENUM_TO_CSTR(two);
          ENUM_TO_CSTR(three);
          ENUM_TO_CSTR(four);
          ENUM_TO_CSTR(five);
          ENUM_TO_CSTR(six);
          ENUM_TO_CSTR(seven);
          ENUM_TO_CSTR(eight);
          ENUM_TO_CSTR(nine);
          ENUM_TO_CSTR(ten);
          ENUM_TO_CSTR(jack);
          ENUM_TO_CSTR(queen);
          ENUM_TO_CSTR(king);
        default:
          return "<invalid card number>";
          break;
      }
  }
  std::string suit_str() const
  {
      switch (suit.e)
      {
          ENUM_TO_CSTR(club);
          ENUM_TO_CSTR(diamond);
          ENUM_TO_CSTR(heart);
          ENUM_TO_CSTR(spade);
          default:
            return "<invalid card suit>";
            break;
      }
  }

  void dump() const {
    printf("Your card is a %s of %s\n",
           number_str().c_str(), suit_str().c_str());
  }
};

class Cards
{
private:
  std::vector<Card> m_cards;

public:
  static Cards makeStandardDeck(bool shuffle)
  {
      Cards deck;
      for (int suit = club; suit != spade+1; suit++)
        for (int number = ace; number != king+1; number++)
              deck.append(Card(number, suit));
      if (shuffle)
          deck.shuffle();
      return deck;
  }

  void shuffle()
  {
      std::random_device rd;
      std::mt19937 gen(rd());
      std::shuffle(m_cards.begin(), m_cards.end(), gen);
  }

  void append(Card card) {
    m_cards.push_back(card);
  }

  const Card &operator[](size_t i) {
    return m_cards[i];
  }
  
  void dump() const {
    for (Card card: m_cards)
      card.dump();
  }
  
  Card getTopCard() {
    assert(!m_cards.empty());
    Card card = m_cards.back();
    m_cards.pop_back();
    return card;
  }
  
  Cards getCards(size_t count)
  {
    Cards cards;
    for (size_t i=0; i<count; ++i)
      cards.append(getTopCard());
    return cards;
  }
};


int main(int argc, const char * argv[])
{
    Cards deck = Cards::makeStandardDeck(true);
    Cards six = deck.getCards(6);
    six.dump();

    return 0;
}
