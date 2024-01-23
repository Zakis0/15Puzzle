#include "Shop.h"
#include "../Menu/Menu.h"

//                             1  2   3   4    5    6    7     8     9
vector<int> PRICE_OF_UPGRADES {2, 20, 50, 100, 300, 700, 1700, 4000, 10000};

//                           0  1  2  3  4   5   6   7   8   9
vector<int> ADDITIONAL_TIME {0, 1, 3, 6, 10, 15, 25, 40, 60, 90};

void shopInit(Player& player) {
    printShopInfo(player);
}

void shop(Player& player) {
    shopInit(player);

    char input;
    while (true) {
        cin >> input;
        switch (input) {
            // Global control
            case CHAR_TO_GET_CONTROL_INFO: printControlOptions(); break;
            case CHAR_TO_QUIT: {
                cout << "Back to menu" << endl;
                return;
            }
            case CHAR_TO_CLOSE_GAME: exit(0);

            // Shop control
            case CHAR_TO_UPGRADE: upgrade(player); break;
            case CHAR_TO_GET_INFO: printShopInfo(player); break;
            case CHAR_TO_SAVE_GAME: player.saveData(); break;

            // Cheats
            case CHAR_TO_GET_MONEY: addMoney(player); break;
            case CHAR_TO_CLEAR_PLAYER: clearPlayer(player); break;

            default: break;
        }
    }
}

void upgrade(Player& player) {
    if (player.getTimeBuffLevelValue() < ADDITIONAL_TIME.size() and
        player.getAmountOfMoney() >= PRICE_OF_UPGRADES[player.getTimeBuffLevelValue() + 1]) {
        player.changeMoney(-1 * PRICE_OF_UPGRADES[player.getTimeBuffLevelValue() + 1]);
        player.changeTimeBuff(1);

        cout << endl << "Upgrade done!" << endl << endl;
        printShopInfo(player);
    }
    else {
        cout << "Not enough money" << endl;
    }
}

void printShopInfo(Player& player) {
    printInfo(player);
    cout << "Current time buff: " << ADDITIONAL_TIME[player.getTimeBuffLevelValue()] << " seconds" << endl;

    cout << "-----------" << endl;

    if (player.getTimeBuffLevelValue() < ADDITIONAL_TIME.size()) {
        cout << "Next additional time: " << ADDITIONAL_TIME[player.getTimeBuffLevelValue() + 1] << endl;
        cout << "Price of upgrade: " << PRICE_OF_UPGRADES[player.getTimeBuffLevelValue() + 1] << endl;
    }
    else {
        cout << "All upgrades done!" << endl;
    }
}

void addMoney(Player& player) {
    player.changeMoney(1000);
}

void clearPlayer(Player& player) {
    player.changeMoney(-player.getAmountOfMoney());
    player.changeTimeBuff(-player.getTimeBuffLevelValue());
}