#ifndef INC_15PUZZLE_PLAYER_H
#define INC_15PUZZLE_PLAYER_H

#include <fstream>

#include "../../Options.h"
#include "../../libs/Error/error.h"
#include "../Params/ERRORS.h"


class Player {
    unsigned int money;
    unsigned int timeBuffLevel;
public:
    Player(unsigned int money = 0, unsigned int timeBuff = 0);

    unsigned int getAmountOfMoney() const;
    unsigned int getTimeBuffLevelValue() const;

    void changeMoney(int amount);
    void changeTimeBuff(int amount);

    void saveData() const;
    void loadData();

    void printInfo() const;
};


#endif //INC_15PUZZLE_PLAYER_H
