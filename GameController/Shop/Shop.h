#ifndef INC_15PUZZLE_SHOP_H
#define INC_15PUZZLE_SHOP_H

#include <vector>

#include "../Player/Player.h"

void shopInit(Player& player);
void shop(Player& player);
void upgrade(Player& player);
void printShopInfo(Player& player);

void addMoney(Player& player);
void clearPlayer(Player& player);

#endif //INC_15PUZZLE_SHOP_H
