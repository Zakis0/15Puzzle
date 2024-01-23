#ifndef INC_15PUZZLE_ERRORS_H
#define INC_15PUZZLE_ERRORS_H

#include <string>
#include "Constants.h"

const std::string MAX_FIELD_SIZE_ERROR = "Size of field must be in 1.." + to_string(MAX_SIZE_OF_FIELD);
const std::string SAVE_LOAD_ERROR = "Save load error";
const std::string SAVE_READ_ERROR = "Save read error";

#endif //INC_15PUZZLE_ERRORS_H
