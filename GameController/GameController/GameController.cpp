#include "GameController.h"

//                             2  3   4   5   6   7   8    9    10
vector<int> SECONDS_FOR_LEVEL {10, 60, 180, 300, 500, 900, 2000, 4000, 7000};

//                         1  2  3  4   5   6   7    8    9
vector<int> LEVEL_REWARDS {1, 2, 5, 10, 20, 50, 100, 400, 1000};

void play(Player& player) {
    auto totalTimeStart = chrono::high_resolution_clock::now();
    auto timeEnd = chrono::high_resolution_clock::now();
    double totalLevelTime, totalGameTime;
    GAME_ENDS gameEnds;
    int fieldSize = MIN_FIELD_SIZE;
    for (; fieldSize < MAX_SIZE_OF_FIELD; ++fieldSize) {
        auto levelTimeStart = chrono::high_resolution_clock::now();

        gameEnds = startGameAtFieldWithSize(player, fieldSize);
        timeEnd = chrono::high_resolution_clock::now();
        totalLevelTime = std::chrono::duration_cast<std::chrono::milliseconds>(levelTimeStart - timeEnd).count();
        totalLevelTime = round(0.0 - totalLevelTime / 1000, TIME_ROUND_DIGITS);
        totalGameTime = std::chrono::duration_cast<std::chrono::milliseconds>(totalTimeStart - timeEnd).count();
        totalGameTime = round(0.0 - totalGameTime / 1000, TIME_ROUND_DIGITS);
        switch (gameEnds) {
            case WIN: levelVictoryHandler(totalLevelTime); break;
            case LOSE: levelLoseHandler(); break;
            case QUIT: levelQuitHandler(player, fieldSize, totalGameTime); break;
        }
        if (gameEnds == LOSE || gameEnds == QUIT) {
            break;
        }
    }
    if (gameEnds != QUIT) {
        levelQuitHandler(player, fieldSize, totalGameTime);
    }
    if (gameEnds == WIN and fieldSize == MAX_SIZE_OF_FIELD) {
        gameEndHandler();
    }
}

GAME_ENDS startGameAtFieldWithSize(Player& player, unsigned short fieldSize) {
    GameField gameField(fieldSize);

    gameField.scramble();

    printField(gameField);

    char input;

    auto startTime = chrono::high_resolution_clock::now();
    while (true) {
        cin >> input;
        switch (input) {
            case CHAR_TO_MOVE_UP: gameField.movePieceUp(); break;
            case CHAR_TO_MOVE_DOWN: gameField.movePieceDown(); break;
            case CHAR_TO_MOVE_LEFT: gameField.movePieceLeft(); break;
            case CHAR_TO_MOVE_RIGHT: gameField.movePieceRight(); break;
            case CHAR_TO_QUIT: return QUIT;
            default: break;
        }
        printField(gameField);
        if (gameField.isWin()) {
            return WIN;
        }
        auto currentLevelTime = chrono::high_resolution_clock::now();
        double totalLevelTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentLevelTime - startTime).count();
        double leftTime = round(SECONDS_FOR_LEVEL[fieldSize - MIN_FIELD_SIZE] + SECONDS_FOR_LEVEL[player.getTimeBuffLevelValue()] - totalLevelTime / 1000, TIME_ROUND_DIGITS);
        cout << "Left time " << leftTime << " seconds" << endl;
        if (leftTime <= 0) {
            return LOSE;
        }
    }
}

void levelVictoryHandler(double totalLevelTime) {
    cout << "WIN!" << endl;
    cout << "Level duration " << totalLevelTime;
    cout << " seconds" << endl;
}
void levelLoseHandler() {
    cout << "Lose" << endl;
}
void levelQuitHandler(Player& player, int fieldSize, double totalGameTime) {
    cout << "Total time of game ";
    cout << totalGameTime;
    cout << " seconds" << endl;

    cout << endl << "--------------" << endl << endl;

    player.changeMoney(LEVEL_REWARDS[fieldSize - MIN_FIELD_SIZE]);
    cout << "Reward: " << LEVEL_REWARDS[fieldSize - MIN_FIELD_SIZE] << endl;
}
void gameEndHandler() {
    cout << "Game complete! Congratulations!" << endl;
}

void printField(GameField gameField) {
    switch (GRAPHICS_MODE) {
        case NUMBERS: gameField.printField(); break;
        case CHARS: gameField.GetFieldMatrix().scaleMatrix(FIELD_SCALE).printMatrix(); break;
        case COLORS: printColorMatrix(gameField.GetFieldMatrix().scaleMatrix(FIELD_SCALE)); break;
    }
}
