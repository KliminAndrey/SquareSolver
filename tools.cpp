#include "tools.h"

bool compareDoubles(const double number1, const double number2) {
    const double dif = number1 - number2;
    if (dif > -EPS && dif < EPS) {
        return true;
    } else {
        return false;
    }
}
