#pragma once
#ifndef INC_15PUZZLE_GAME_CONTROLLER_H
#define INC_15PUZZLE_GAME_CONTROLLER_H

#include <iostream>
#include <chrono>

#include "../GameField/GameField.h"
#include "../Graphics/Graphics.h"
#include "../../Options.h"
#include "../../libs/MathHandler/MathHandler.h"
#include "../Player/Player.h"

using namespace std;

void play(Player& player);
GAME_ENDS startGameAtFieldWithSize(Player& player, unsigned short fieldSize = 3);

void printField(GameField gameField);

void levelVictoryHandler(double totalLevelTime);
void levelLoseHandler();
void levelQuitHandler(Player& player, int fieldSize, double totalGameTime);
void gameEndHandler();

#endif //INC_15PUZZLE_GAME_CONTROLLER_H
