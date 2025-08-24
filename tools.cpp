#include "header.h"

int compareDoubles(const double number1, const double number2) {
    const double dif = number1 - number2;
    if (dif > -EPS && dif < EPS) {
        return 1;
    } else {
        return 0;
    }
}
