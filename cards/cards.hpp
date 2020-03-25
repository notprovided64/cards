//
//  cards.hpp
//  cards
//
//  Created by Preston Clayton on 3/24/20.
//  Copyright © 2020 Preston Clayton. All rights reserved.
//

#ifndef cards_hpp
#define cards_hpp

#include <stdio.h>
#include <random>
#include "card.hpp"
#include "enum.h"

class Cards
{
private:
  std::vector<Card> m_cards;

public:
  static Cards makeStandardDeck(bool shuffle);
    void shuffle();
    void append(Card card);
    void dump() const;
    Card getTopCard();
    Cards getCards(size_t count);

};

#endif /* cards_hpp */
