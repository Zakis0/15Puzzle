#pragma once
#ifndef MY_PIXEL_DIGITS_H
#define MY_PIXEL_DIGITS_H

#include "../Matrix/matrix.h"

#define DIGIT_HEIGHT 5
#define DIGIT_WIDTH 3

class PixelDigit {
public:
    unsigned short type;

    void printDigit();
    Matrix* getDigitDisplay();

    static PixelDigit* getPixelDigitByInt(unsigned short digit, char emptyPixel, char digitPixel);
    static Matrix intToPixelDigits(unsigned int number, char emptyPixel, char digitPixel, unsigned short spaceBetweenDigits);
    static Matrix createDigitPairMatrix(unsigned short firstDigit, unsigned short secondDigit, char emptyPixel, char digitPixel, unsigned int spaceBetweenDigits);
protected:
    char digitPixel, emptyPixel;
    Matrix *display;

    void createDisplay();
};

class Zero: public PixelDigit {
public:
    Zero(char emptyPixel, char digitPixel);
};

class One: public PixelDigit {
public:
    One(char emptyPixel, char digitPixel);
};

class Two: public PixelDigit {
public:
    Two(char emptyPixel, char digitPixel);
};

class Three: public PixelDigit {
public:
    Three(char emptyPixel, char digitPixel);
};

class Four: public PixelDigit {
public:
    Four(char emptyPixel, char digitPixel);
};

class Five: public PixelDigit {
public:
    Five(char emptyPixel, char digitPixel);
};

class Six: public PixelDigit {
public:
    Six(char emptyPixel, char digitPixel);
};

class Seven: public PixelDigit {
public:
    Seven(char emptyPixel, char digitPixel);
};

class Eight: public PixelDigit {
public:
    Eight(char emptyPixel, char digitPixel);
};

class Nine: public PixelDigit {
public:
    Nine(char emptyPixel, char digitPixel);
};


#endif // MY_PIXEL_DIGITS_H
