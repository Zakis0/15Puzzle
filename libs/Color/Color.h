#pragma once
#ifndef MY_COLOR_H
#define MY_COLOR_H

#include <iostream>

#define NUM_OF_COLORS_TYPE 3

using namespace std;

class Color {
public:
    unsigned short red, green, blue;

    Color();
    Color(unsigned short red, unsigned short green, unsigned short blue);
    Color(const Color &color);

    bool operator==(Color color) const;
    bool operator!=(Color color) const;

    void printColor() const;

    static void setConsoleBGC(unsigned short red, unsigned short green, unsigned short blue);
    static void setConsoleBGC(const Color &color);

    static void setDefaultConsoleBGC();

    static void printColoredPixel(const Color &color);
};

#endif // MY_COLOR_H
