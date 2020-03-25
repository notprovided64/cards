//
//  cards.cpp
//  cards
//
//  Created by Preston Clayton on 3/24/20.
//  Copyright © 2020 Preston Clayton. All rights reserved.
//

#include "cards.hpp"
#include "card.hpp"
#include "enum.h"

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
