#include "Coordinates.h"

Coords Coords::operator+(Coords &coords) {
    return Coords(i + coords.i, j + coords.j);
}

Coords Coords::operator-(Coords &coords) {
    return Coords(i - coords.i, j - coords.j);
}

std::ostream &operator<<(std::ostream &stream, Coords &coords) {
    stream << "[" << coords.i << ", " << coords.j <<"]";
    return stream;
}
