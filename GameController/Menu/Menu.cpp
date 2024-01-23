#include "Menu.h"

void menuInit(Player& player) {
    printControlOptions();
    player.loadData();
}

void menu() {
    Player player;

    menuInit(player);

    char input;
    while (true) {
        cin >> input;
        switch (input) {
            // Global control
            case CHAR_TO_GET_CONTROL_INFO: printControlOptions(); break;
            case CHAR_TO_QUIT: exit(0);
            case CHAR_TO_CLOSE_GAME: exit(0);
            // Menu control
            case CHAR_TO_START_GAME: {
                play(player);
                printInfo(player);
                break;
            }
            case CHAR_TO_GET_INFO: printInfo(player); break;
            case CHAR_TO_OPEN_SHOP: shop(player); break;
            case CHAR_TO_SAVE_GAME: player.saveData(); break;

            default: break;
        }
    }
}

void printInfo(Player& player) {
    player.printInfo();
}

void printControlOptions() {
    // Global control
    cout << "Global control" << endl;
    cout << "CHAR_TO_GET_CONTROL_INFO: " << CHAR_TO_GET_CONTROL_INFO << endl;
    cout << "CHAR_TO_QUIT: " << CHAR_TO_QUIT << endl;
    cout << "CHAR_TO_CLOSE_GAME: " << CHAR_TO_CLOSE_GAME << endl;

    cout << endl << "-------------" << endl << endl;

    cout << "Menu control" << endl;
    cout << "CHAR_TO_START_GAME: " << CHAR_TO_START_GAME << endl;
    cout << "CHAR_TO_GET_INFO: " << CHAR_TO_GET_INFO << endl;
    cout << "CHAR_TO_OPEN_SHOP: " << CHAR_TO_OPEN_SHOP << endl;
    cout << "CHAR_TO_SAVE_GAME: " << CHAR_TO_SAVE_GAME << endl;

    cout << endl << "-------------" << endl << endl;

    cout << "Shop control" << endl;
    cout << "CHAR_TO_UPGRADE: " << CHAR_TO_UPGRADE << endl;
    cout << "CHAR_TO_GET_INFO: " << CHAR_TO_GET_INFO << endl;
    cout << "CHAR_TO_SAVE_GAME: " << CHAR_TO_SAVE_GAME << endl;

    cout << endl << "-------------" << endl << endl;

    cout << "Game control" << endl;
    cout << "CHAR_TO_MOVE_UP: " << CHAR_TO_MOVE_UP << endl;
    cout << "CHAR_TO_MOVE_DOWN: " << CHAR_TO_MOVE_DOWN << endl;
    cout << "CHAR_TO_MOVE_LEFT: " << CHAR_TO_MOVE_LEFT << endl;
    cout << "CHAR_TO_MOVE_RIGHT: " << CHAR_TO_MOVE_RIGHT << endl;

    cout << endl;
}