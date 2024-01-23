#pragma once
#ifndef MY_RANDOM_H
#define MY_RANDOM_H

#include <vector>
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <any>

using namespace std;

void initRand();
int getRandInt(int start, int end);
double getRandDouble(float start, float end, int numOfDecimalPlaces);
bool getTrueWithProbability(int probability);
void randSort(vector<any> &vec);

#endif // MY_RANDOM_H

