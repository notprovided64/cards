//
//  card.cpp
//  cards
//
//  Created by Preston Clayton on 3/24/20.
//  Copyright © 2020 Preston Clayton. All rights reserved.
//

#include "card.hpp"
#include "enum.h"
#include <iostream>
#include <vector>
#include <cstdlib>


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
