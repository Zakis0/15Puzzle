#include "PixelDigits.h"



void PixelDigit::createDisplay() {
    display = new Matrix(DIGIT_HEIGHT, DIGIT_WIDTH, emptyPixel);
}

void PixelDigit::printDigit() {
    display->printMatrix();
}

Matrix *PixelDigit::getDigitDisplay() {
    return display;
}

PixelDigit* PixelDigit::getPixelDigitByInt(unsigned short digit, char emptyPixel, char digitPixel) {
    if (digit < 0 || digit > 9) {
        error("Is not digit");
    }
    switch (digit) {
        case 1: return new One(emptyPixel, digitPixel);
        case 2: return new Two(emptyPixel, digitPixel);
        case 3: return new Three(emptyPixel, digitPixel);
        case 4: return new Four(emptyPixel, digitPixel);
        case 5: return new Five(emptyPixel, digitPixel);
        case 6: return new Six(emptyPixel, digitPixel);
        case 7: return new Seven(emptyPixel, digitPixel);
        case 8: return new Eight(emptyPixel, digitPixel);
        case 9: return new Nine(emptyPixel, digitPixel);
        default: return new Zero(emptyPixel, digitPixel);
    }
}

Matrix PixelDigit::createDigitPairMatrix(unsigned short firstDigit, unsigned short secondDigit, char emptyPixel, char digitPixel, unsigned int spaceBetweenDigits) {
    PixelDigit* firstDigitMatrix = PixelDigit::getPixelDigitByInt(firstDigit, emptyPixel, digitPixel);
    PixelDigit* secondDigitMatrix = PixelDigit::getPixelDigitByInt(secondDigit, emptyPixel, digitPixel);

    Matrix* firstDigitDisplay = firstDigitMatrix->getDigitDisplay();
    Matrix* secondDigitDisplay = secondDigitMatrix->getDigitDisplay();

    Matrix DigitPair = firstDigitDisplay->connectMatrixHorizontal(*secondDigitDisplay, spaceBetweenDigits);

    return DigitPair;
}

string intToString(unsigned int number) {
    string str;
    while (number != 0) {
        str = (char)(number % 10 + '0') + str;
        number /= 10;
    }
    return str;
}

Matrix PixelDigit::intToPixelDigits(unsigned int number, char emptyPixel, char digitPixel, unsigned short spaceBetweenDigits) {
    string numStr = intToString(number);
    PixelDigit* digitMatrix = PixelDigit::getPixelDigitByInt(numStr[0] - '0', emptyPixel, digitPixel);
    Matrix* digitDisplay = digitMatrix->getDigitDisplay();
    Matrix* connectedDigitsMatrix = new Matrix(*digitDisplay);

    for (int i = 1; i < numStr.size(); ++i) {
        digitMatrix = PixelDigit::getPixelDigitByInt(numStr[i] - '0', emptyPixel, digitPixel);
        digitDisplay = digitMatrix->getDigitDisplay();

        Matrix temp = connectedDigitsMatrix->connectMatrixHorizontal(*digitDisplay, spaceBetweenDigits);
        connectedDigitsMatrix = new Matrix(temp);
    }
    return *connectedDigitsMatrix;
}

Zero::Zero(char emptyPixel, char digitPixel) {
    this->emptyPixel = emptyPixel;
    this->digitPixel = digitPixel;
    createDisplay();

    type = 0;

    display->fillMatrixByVector({{digitPixel, digitPixel, digitPixel},
                                 {digitPixel, emptyPixel, digitPixel},
                                 {digitPixel, emptyPixel, digitPixel},
                                 {digitPixel, emptyPixel, digitPixel},
                                 {digitPixel, digitPixel, digitPixel}});
}

One::One(char emptyPixel, char digitPixel) {
    this->emptyPixel = emptyPixel;
    this->digitPixel = digitPixel;
    createDisplay();

    type = 1;

//    display->fillMatrixByVector({{emptyPixel, emptyPixel, digitPixel},
//                                 {emptyPixel, emptyPixel, digitPixel},
//                                 {emptyPixel, emptyPixel, digitPixel},
//                                 {emptyPixel, emptyPixel, digitPixel},
//                                 {emptyPixel, emptyPixel, digitPixel}});
    display->fillMatrixByVector({{emptyPixel, digitPixel, emptyPixel},
                                 {emptyPixel, digitPixel, emptyPixel},
                                 {emptyPixel, digitPixel, emptyPixel},
                                 {emptyPixel, digitPixel, emptyPixel},
                                 {emptyPixel, digitPixel, emptyPixel}});
}

Two::Two(char emptyPixel, char digitPixel) {
    this->emptyPixel = emptyPixel;
    this->digitPixel = digitPixel;
    createDisplay();

    type = 2;

    display->fillMatrixByVector({{digitPixel, digitPixel, digitPixel},
                                 {emptyPixel, emptyPixel, digitPixel},
                                 {digitPixel, digitPixel, digitPixel},
                                 {digitPixel, emptyPixel, emptyPixel},
                                 {digitPixel, digitPixel, digitPixel}});
}

Three::Three(char emptyPixel, char digitPixel) {
    this->emptyPixel = emptyPixel;
    this->digitPixel = digitPixel;
    createDisplay();

    type = 3;

    display->fillMatrixByVector({{digitPixel, digitPixel, digitPixel},
                                 {emptyPixel, emptyPixel, digitPixel},
                                 {emptyPixel, digitPixel, digitPixel},
                                 {emptyPixel, emptyPixel, digitPixel},
                                 {digitPixel, digitPixel, digitPixel}});
}

Four::Four(char emptyPixel, char digitPixel) {
    this->emptyPixel = emptyPixel;
    this->digitPixel = digitPixel;
    createDisplay();

    type = 4;

    display->fillMatrixByVector({{digitPixel, emptyPixel, digitPixel},
                                 {digitPixel, emptyPixel, digitPixel},
                                 {digitPixel, digitPixel, digitPixel},
                                 {emptyPixel, emptyPixel, digitPixel},
                                 {emptyPixel, emptyPixel, digitPixel}});
}

Five::Five(char emptyPixel, char digitPixel) {
    this->emptyPixel = emptyPixel;
    this->digitPixel = digitPixel;
    createDisplay();

    type = 5;

    display->fillMatrixByVector({{digitPixel, digitPixel, digitPixel},
                                 {digitPixel, emptyPixel, emptyPixel},
                                 {digitPixel, digitPixel, digitPixel},
                                 {emptyPixel, emptyPixel, digitPixel},
                                 {digitPixel, digitPixel, digitPixel}});
}

Six::Six(char emptyPixel, char digitPixel) {
    this->emptyPixel = emptyPixel;
    this->digitPixel = digitPixel;
    createDisplay();

    type = 6;

    display->fillMatrixByVector({{digitPixel, digitPixel, digitPixel},
                                 {digitPixel, emptyPixel, emptyPixel},
                                 {digitPixel, digitPixel, digitPixel},
                                 {digitPixel, emptyPixel, digitPixel},
                                 {digitPixel, digitPixel, digitPixel}});
}

Seven::Seven(char emptyPixel, char digitPixel) {
    this->emptyPixel = emptyPixel;
    this->digitPixel = digitPixel;
    createDisplay();

    type = 7;

    display->fillMatrixByVector({{digitPixel, digitPixel, digitPixel},
                                 {emptyPixel, emptyPixel, digitPixel},
                                 {emptyPixel, digitPixel, digitPixel},
                                 {digitPixel, digitPixel, emptyPixel},
                                 {digitPixel, emptyPixel, emptyPixel}});
//    display->fillMatrixByVector({{digitPixel, digitPixel, digitPixel},
//                                 {emptyPixel, emptyPixel, digitPixel},
//                                 {emptyPixel, emptyPixel, digitPixel},
//                                 {emptyPixel, emptyPixel, digitPixel},
//                                 {emptyPixel, emptyPixel, digitPixel}});
}

Eight::Eight(char emptyPixel, char digitPixel) {
    this->emptyPixel = emptyPixel;
    this->digitPixel = digitPixel;
    createDisplay();

    type = 8;

    display->fillMatrixByVector({{digitPixel, digitPixel, digitPixel},
                                 {digitPixel, emptyPixel, digitPixel},
                                 {digitPixel, digitPixel, digitPixel},
                                 {digitPixel, emptyPixel, digitPixel},
                                 {digitPixel, digitPixel, digitPixel}});
}

Nine::Nine(char emptyPixel, char digitPixel) {
    this->emptyPixel = emptyPixel;
    this->digitPixel = digitPixel;
    createDisplay();

    type = 9;

    display->fillMatrixByVector({{digitPixel, digitPixel, digitPixel},
                                 {digitPixel, emptyPixel, digitPixel},
                                 {digitPixel, digitPixel, digitPixel},
                                 {emptyPixel, emptyPixel, digitPixel},
                                 {emptyPixel, emptyPixel, digitPixel}});
}
