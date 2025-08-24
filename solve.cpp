#include "header.h"

int solve(const double a, const double b, const double c,
                  double* const root1, double* const root2) {
    assert(root1 != NULL);
    assert(root2 != NULL);

    if (compareDoubles(a, 0)) { // проверяем степень уравнения // int solveLinear()
        return solveLinear(b, c, root1);
    } else {
        return solveSquare(a, b, c, root1, root2);
    }
}

int solveLinear(const double a, const double b, double* const root) {
    assert(root != NULL);

    if (compareDoubles(a, 0) && compareDoubles(b, 0)) { // уравнение вида 0 * x = 0
        return INF_SOLVES;
    } else if (compareDoubles(a, 0)) {
        return 0;
    } else {
        *root = -b / a;
        return 1;
    }
}

int solveSquare(const double a, const double b, const double c,
                    double* const root1, double* const root2) {
    assert(root1 != NULL);
    assert(root2 != NULL);

    const double discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        return 0;
    } else if (compareDoubles(discriminant, 0)) {
        *root1 = -b / (2 * a);
        return 1;
    } else {
        *root1 = (-b - sqrt(discriminant)) / (2 * a);
        *root2 = (-b + sqrt(discriminant)) / (2 * a);
        return 2;
    }
}
