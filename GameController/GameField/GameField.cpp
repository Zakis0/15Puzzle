#include "GameField.h"

Coords positionDown(1, 0);
Coords positionUp(-1, 0);
Coords positionLeft(0, -1);
Coords positionRight(0, 1);

GameField::GameField(unsigned short size) {
    if (size > MAX_SIZE_OF_FIELD) {
        error(MAX_FIELD_SIZE_ERROR);
    }
    emptyPieceCoords = Coords(size - 1, size - 1);
    this->size = size;
    field = new short*[size];
    for (int i = 0; i < size; ++i) {
        field[i] = new short[size];
        for (int j = 0; j < size; ++j) {
            field[i][j] = i * size + j + 1;
        }
    }
    field[size - 1][size - 1] = EMPTY_PIECE_VALUE;
}

void GameField::printField() const {
    for (int i = 0; i < size; ++i) {
        cout << field[i][0];
        for (int j = 1; j < size; ++j) {
            cout << "\t" << field[i][j];
        }
        cout << endl;
    }
}

short GameField::getFieldSize() const {
    return size;
}

short **GameField::getField() {
    return field;
}

Matrix GameField::GetFieldMatrix() {
    Matrix result(
            DISTANCE_BETWEEN_BLOCKS,
            (BLOCK_SIZE + DISTANCE_BETWEEN_BLOCKS) * size - 1,
            EMPTY_PIXEL);
    Matrix emptyMatrixHorizontal(
            DISTANCE_BETWEEN_BLOCKS,
            (BLOCK_SIZE + DISTANCE_BETWEEN_BLOCKS) * size - 1,
            EMPTY_PIXEL);
    for (int i = 0; i < size; ++i) {
        Matrix lineOfNumbers = createBlockOfNumber(field[i][0]);
        for (int j = 1; j < size; ++j) {
            Matrix blockOfNumber = createBlockOfNumber(field[i][j]);
            lineOfNumbers.cloneMatrix(lineOfNumbers.connectMatrixHorizontal(blockOfNumber, DISTANCE_BETWEEN_BLOCKS));
        }
        result.cloneMatrix(result.connectMatrixVertical(lineOfNumbers)
                                   .connectMatrixVertical(emptyMatrixHorizontal));
    }
    return result.shiftMatrix(true, 2 * DISTANCE_BETWEEN_BLOCKS).shiftMatrix(false, -1 * DISTANCE_BETWEEN_BLOCKS);
}

void GameField::movePieceUp() {
    Coords pieceCoords = emptyPieceCoords + positionDown;
    if (isCoordsInField(pieceCoords)) {
        swapPieceInCoord(pieceCoords, emptyPieceCoords);
        emptyPieceCoords = pieceCoords;
    }
}

void GameField::movePieceDown() {
    Coords pieceCoords = emptyPieceCoords + positionUp;
    if (isCoordsInField(pieceCoords)) {
        swapPieceInCoord(pieceCoords, emptyPieceCoords);
        emptyPieceCoords = pieceCoords;
    }
}

void GameField::movePieceLeft() {
    Coords pieceCoords = emptyPieceCoords + positionRight;
    if (isCoordsInField(pieceCoords)) {
        swapPieceInCoord(pieceCoords, emptyPieceCoords);
        emptyPieceCoords = pieceCoords;
    }
}

void GameField::movePieceRight() {
    Coords pieceCoords = emptyPieceCoords + positionLeft;
    if (isCoordsInField(pieceCoords)) {
        swapPieceInCoord(pieceCoords, emptyPieceCoords);
        emptyPieceCoords = pieceCoords;
    }
}

bool GameField::isCoordsInField(Coords coords) const {
    return coords.i >= 0 and coords.i < size and
        coords.j >= 0 and coords.j < size;
}

void GameField::swapPieceInCoord(Coords coordFrom, Coords coordTo) const {
    field[coordTo.i][coordTo.j] = field[coordFrom.i][coordFrom.j];
    field[coordFrom.i][coordFrom.j] = EMPTY_PIECE_VALUE;
}

bool GameField::isWin() const {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (field[i][j] != i * size + j + 1) {
                return i == size - 1 and j == size - 1;
            }
        }
    }
    return true;
}

void GameField::scramble() {
    initRand();
    for (int i = 0; i < ceil(size * size * SCRAMBLE_MULTIPLIER); ++i) {
        switch (getRandInt(0, 4)) {
            case 0: movePieceUp(); break;
            case 1: movePieceDown(); break;
            case 2: movePieceLeft(); break;
            case 3: movePieceRight(); break;
            default: break;
        }
    }
    if (isWin()) {
        scramble();
    }
}
