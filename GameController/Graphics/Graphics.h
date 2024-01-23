#ifndef INC_15PUZZLE_FIELD_GENERATOR_H
#define INC_15PUZZLE_FIELD_GENERATOR_H

#include "../../libs/Matrix/matrix.h"
#include "../../libs/PixelDigits/PixelDigits.h"
#include "../Params/Constants.h"
#include "../../libs/Color/Color.h"
#include "../GameField/GameField.h"

Matrix createBlockOfNumber(int number);
void printColorMatrix(const Matrix& matrix);

#endif //INC_15PUZZLE_FIELD_GENERATOR_H
