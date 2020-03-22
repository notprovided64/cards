#include <iostream>
#include <vector>
#include <cstdlib>
#include <random>

enum NUMBER : uint8_t {invalid_number, ace, two, three, four, five, six, seven,
                       eight, nine, ten, jack, queen, king};
enum SUIT : uint8_t {invalid_suit, club, diamond, heart, spade};

constexpr const char * SPADE_UNICODE = "\u2660";
constexpr const char * CLUB_UNICODE = "\u2663";
constexpr const char * HEART_UNICODE = "\u2665";
constexpr const char * DIAMONG_UNICODE = "\u2666";

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
          case ace: return "A";
          case two: return "2";
          case three: return "3";
          case four: return "4";
          case five: return "5";
          case six: return "6";
          case seven: return "7";
          case eight: return "8";
          case nine: return "9";
          case ten: return "10";
          case jack: return "J";
          case queen: return "Q";
          case king: return "K";
          default:
            return "<invalid card number>";
            break;
      }
  }
  std::string suit_str() const
  {
      switch (suit.e)
      {
        case club: return CLUB_UNICODE;
        case diamond: return DIAMONG_UNICODE;
        case heart: return HEART_UNICODE;
        case spade: return SPADE_UNICODE;
          default:
            return "<invalid card suit>";
            break;
      }
  }

  void dump() const {
    printf("%s%s\n",
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
    deck.dump();
    puts("\n6 cards from deck:");
    Cards six = deck.getCards(6);
    six.dump();

    return 0;
}
