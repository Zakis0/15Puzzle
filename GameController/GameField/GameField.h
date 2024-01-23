#pragma once
#ifndef INC_15PUZZLE_GAME_FIELD_H
#define INC_15PUZZLE_GAME_FIELD_H

#include <iostream>
#include "../../libs/Matrix/matrix.h"
#include "../Params/Constants.h"
#include "../../Options.h"
#include "../../libs/Coordinates/Coordinates.h"
#include "../../libs/MyRandom/myRandom.h"
#include "../Graphics/Graphics.h"
#include "../Params/ERRORS.h"

using namespace std;

class GameField {
    unsigned short size;
    short** field;

    Coords emptyPieceCoords;
public:
    GameField(unsigned short size = 4);
    
    void printField() const;
    short getFieldSize() const;
    short** getField();
    Matrix GetFieldMatrix();

    void movePieceUp();
    void movePieceDown();
    void movePieceLeft();
    void movePieceRight();

    bool isCoordsInField(Coords coords) const;
    void swapPieceInCoord(Coords coordFrom, Coords coordTo) const;

    void scramble();

    bool isWin() const;
};


#endif //INC_15PUZZLE_GAME_FIELD_H
