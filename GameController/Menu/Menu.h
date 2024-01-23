#ifndef INC_15PUZZLE_MENU_H
#define INC_15PUZZLE_MENU_H

#include <iostream>

#include "../../Options.h"
#include "../GameController/GameController.h"
#include "../Shop/Shop.h"

using namespace std;

void menuInit(Player& player);
void menu();
void printInfo(Player& player);
void printControlOptions();

#endif //INC_15PUZZLE_MENU_H
