#include "Color.h"

Color::Color() {
    red = 0;
    green = 0;
    blue = 0;
}

Color::Color(unsigned short red, unsigned short green, unsigned short blue) {
    this->red = red;
    this->green = green;
    this->blue = blue;
}

Color::Color(const Color &color) {
    this->red = color.red;
    this->green = color.green;
    this->blue = color.blue;
}

bool Color::operator==(Color color) const {
    return this->red == color.red && this->green == color.green && this->blue == color.blue;
}

bool Color::operator!=(Color color) const {
    return this->red != color.red || this->green != color.green || this->blue != color.blue;
}

void Color::printColor() const {
    cout << red << " " << green << " " << blue << endl;
}

void Color::setConsoleBGC(unsigned short red, unsigned short green, unsigned short blue) {
    cout << "\033[48;2;";
    cout << red << ";";
    cout << green << ";";
    cout << blue;
    cout << ";120m";
}

void Color::setConsoleBGC(const Color &color) {
    cout << "\033[48;2;";
    cout << color.red << ";";
    cout << color.green << ";";
    cout << color.blue;
    cout << ";120m";
}

void Color::printColoredPixel(const Color &color) {
    setConsoleBGC(color);
    cout << ' ';
}

void Color::setDefaultConsoleBGC() {
    cout << "\033[0;0m";
}
