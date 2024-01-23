#include "MathHandler.h"

double round(double number, int digits) {
    double result = number;
    result *= pow(10, digits);
    result = round(result);
    result /= pow(10, digits);
    return result;
}