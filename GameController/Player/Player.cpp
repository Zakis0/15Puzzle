#include "Player.h"

Player::Player(unsigned int money, unsigned int timeBuff) {
    this->money = money;
    this->timeBuffLevel = timeBuff;
}

void Player::changeMoney(int amount) {
    money += amount;
}

void Player::changeTimeBuff(int amount) {
    timeBuffLevel += amount;
}

unsigned int Player::getAmountOfMoney() const {
    return money;
}

unsigned int Player::getTimeBuffLevelValue() const {
    return timeBuffLevel;
}

void Player::saveData() const {
    std::ofstream fout;
    fout.open(SAVES_PATH);
    if (!fout.is_open()) {
        error(SAVE_LOAD_ERROR);
    }
    fout.write((char*)this, sizeof(*this));
    fout.close();
    cout << "Date saved" << endl;
}

void Player::loadData() {
    std::ifstream fin;
    fin.open(SAVES_PATH);
    if (!fin.is_open()) {
        error(SAVE_READ_ERROR);
    }
    fin.read((char*)this, sizeof(*this));
    fin.close();
}

void Player::printInfo() const {
    cout << "Amount of money: " << money << endl;
    cout << "Current time buff level: " << timeBuffLevel << endl;
}
