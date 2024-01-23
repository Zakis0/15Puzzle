#include "Graphics.h"

Color EMPTY_PIXEL_COLOR(75, 60, 57);
Color BLOCK_EMPTY_PIXEL_COLOR(0, 105, 170);
Color BLOCK_PIXEL_COLOR(240, 82, 43);

Matrix createBlockOfNumber(int number) {
    Matrix result, emptyMatrixVertical, digitDisplay;

    Matrix emptyMatrixHorizontal(2, BLOCK_SIZE, EMPTY_PIXEL, BLOCK_EMPTY_PIXEL);
    if (number >= 0 && number < 10) {
        PixelDigit* digitMatrix = PixelDigit::getPixelDigitByInt(number, BLOCK_EMPTY_PIXEL, BLOCK_PIXEL);
        digitDisplay.cloneMatrix(*digitMatrix->getDigitDisplay());
        emptyMatrixVertical.cloneMatrix(Matrix(DIGIT_HEIGHT, 3, EMPTY_PIXEL, BLOCK_EMPTY_PIXEL));
    }
    else if (number > 9 && number < 100) {
        digitDisplay.cloneMatrix(PixelDigit::createDigitPairMatrix(number / 10, number % 10, BLOCK_EMPTY_PIXEL, BLOCK_PIXEL, 1));
        emptyMatrixVertical.cloneMatrix(Matrix(DIGIT_HEIGHT, 1,     EMPTY_PIXEL, BLOCK_EMPTY_PIXEL));
    }
    else {
        return Matrix(BLOCK_SIZE, BLOCK_SIZE, EMPTY_PIXEL);
    }
    result.cloneMatrix(emptyMatrixVertical.connectMatrixHorizontal(digitDisplay));
    result.cloneMatrix(result.connectMatrixHorizontal(emptyMatrixVertical));
    result.cloneMatrix(emptyMatrixHorizontal.connectMatrixVertical(result));
    result.cloneMatrix(result.connectMatrixVertical(emptyMatrixHorizontal));
    return result;
}

Color getColorByChar(char pixel) {
    switch (pixel) {
        case BLOCK_PIXEL: return BLOCK_PIXEL_COLOR;
        case BLOCK_EMPTY_PIXEL: return BLOCK_EMPTY_PIXEL_COLOR;
        default: return EMPTY_PIXEL_COLOR;
    }
}

void printColorMatrix(const Matrix& matrix) {
    for (int i = 0; i < matrix.getHeight(); ++i) {
        Color::setConsoleBGC(getColorByChar(matrix.getField()[i][0]));
        cout << "  ";
        for (int j = 1; j < matrix.getWidth(); ++j) {
            Color::setConsoleBGC(getColorByChar(matrix.getField()[i][j]));
            cout << "  ";
        }
        Color::setDefaultConsoleBGC();
        cout << endl;
    }
}

