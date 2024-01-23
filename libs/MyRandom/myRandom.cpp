#include "myRandom.h"

void initRand() {
    srand(time(nullptr));
}

int getRandInt(int start, int end) {
    return start + (rand() % (end - start));
}

double getRandDouble(float start, float end, int numOfDecimalPlaces) {
    return (double)getRandInt((int)(start * pow(10, numOfDecimalPlaces)), (int)(end * pow(10, numOfDecimalPlaces))) / pow(10, numOfDecimalPlaces);
}

bool getTrueWithProbability(int probability) {
    return getRandInt(0, 100) < probability;
}

void swapInVector(vector<any> &vec, int pos1, int pos2) {
    auto temp = vec[pos1];
    vec[pos1] = vec[pos2];
    vec[pos2] = temp;
}

void randSort(vector<any> &vec) {
    int pos1, pos2;
    int numOfSwapInRandSort = vec.size() * 3;

    for (int i = 0; i < numOfSwapInRandSort; ++i) {
        pos1 = getRandInt(0, vec.size());
        pos2 = getRandInt(0, vec.size());
        swapInVector(vec, pos1, pos2);
    }
}

