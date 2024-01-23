#pragma once
#ifndef INC_15PUZZLE_CONSTANTS_H
#define INC_15PUZZLE_CONSTANTS_H

#include "../../libs/Color/Color.h"

const int MAX_SIZE_OF_FIELD = 10;

const int BLOCK_SIZE = 9;

const int MIN_FIELD_SIZE = 2;

const int EMPTY_PIECE_VALUE = -1;

enum GRAPHICS_MODES {NUMBERS, CHARS, COLORS};

enum GAME_ENDS {WIN, LOSE, QUIT};

#endif //INC_15PUZZLE_CONSTANTS_H
