//
//  enum.h
//  cards
//
//  Created by Preston Clayton on 3/24/20.
//  Copyright © 2020 Preston Clayton. All rights reserved.
//

#ifndef enum_h
#define enum_h

enum NUMBER : uint8_t {invalid_number, ace, two, three, four, five, six, seven,
                       eight, nine, ten, jack, queen, king};
enum SUIT : uint8_t {invalid_suit, club, diamond, heart, spade};

constexpr const char * SPADE_UNICODE = "\u2660";
constexpr const char * CLUB_UNICODE = "\u2663";
constexpr const char * HEART_UNICODE = "\u2665";
constexpr const char * DIAMONG_UNICODE = "\u2666";


#endif /* enum_h */
