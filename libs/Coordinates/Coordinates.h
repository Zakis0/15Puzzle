#pragma once
#ifndef INC_15PUZZLE_COORDINATES_H
#define INC_15PUZZLE_COORDINATES_H

#include <iostream>

struct Coords {
    short i, j;

    Coords operator+(Coords& counter);
    Coords operator-(Coords& counter);
    friend std::ostream& operator<<(std::ostream& stream, Coords& coords);
};

#endif //INC_15PUZZLE_COORDINATES_H
