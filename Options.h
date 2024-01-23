#ifndef INC_15PUZZLE_OPTIONS_H
#define INC_15PUZZLE_OPTIONS_H

#include "GameController/Params/Constants.h"

////Interface options
// Field options
const int DISTANCE_BETWEEN_BLOCKS = 1;
const int OFFSET_FROM_BOUNDARIES = 1;

const char EMPTY_PIXEL = ' ';
const char BLOCK_EMPTY_PIXEL = '.';
const char BLOCK_PIXEL = '#';

const int FIELD_SCALE = 2;

const GRAPHICS_MODES GRAPHICS_MODE = COLORS;

// Time options
const int TIME_ROUND_DIGITS = 2;

//// Control options
// Global control
const char CHAR_TO_GET_CONTROL_INFO = 'i';
const char CHAR_TO_GET_INFO = 'e';
const char CHAR_TO_SAVE_GAME = 'h';
const char CHAR_TO_QUIT = 'g';
const char CHAR_TO_CLOSE_GAME = ']';

// Menu control
const char CHAR_TO_START_GAME = 's';
const char CHAR_TO_OPEN_SHOP = 'f';

//Shop control
const char CHAR_TO_UPGRADE = 'f';

// Game control
const char CHAR_TO_MOVE_UP = 'w';
const char CHAR_TO_MOVE_DOWN = 's';
const char CHAR_TO_MOVE_LEFT = 'a';
const char CHAR_TO_MOVE_RIGHT = 'd';

// Shop Cheats
const char CHAR_TO_GET_MONEY = '/';
const char CHAR_TO_CLEAR_PLAYER = '.';

//// Game options
const double SCRAMBLE_MULTIPLIER = 100;

//// Save options
const string SAVES_PATH = "ProgressSave";

#endif //INC_15PUZZLE_OPTIONS_H
