#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "solve.h"
#include "tools.h"

static void solveLinear(const double a, const double b, eqRoots* const roots);
static void solveSquare(const eqCoef* const coef,
                eqRoots* const roots);


void solve(const eqCoef* const coef,
                eqRoots* const roots) {
    assert(coef != NULL);
    assert(roots != NULL);

    if (compareDoubles(coef->a, 0)) { // проверяем степень уравнения // int solveLinear()
        solveLinear(coef->b, coef->c, roots);
    } else {
        solveSquare(coef, roots);
    }
}

static void solveLinear(const double a, const double b, eqRoots* const roots) {
    assert(roots != NULL);
    roots->nRoots = 1;

    if (compareDoubles(a, 0)) {
        roots->nRoots = 0;
    } if (compareDoubles(a, 0) && compareDoubles(b, 0)) { // уравнение вида 0 * x = 0
        roots->nRoots = INF_SOLVES;
    } else {
        roots->nRoots = 1;
        roots->root1 = -b / a;
    }
}

static void solveSquare(const eqCoef* const coef,
                eqRoots* const roots) {
    assert(coef != NULL);
    assert(roots != NULL);

    const double discriminant = coef->b * coef->b - 4 * coef->a * coef->c;
    if (discriminant < 0) {
        roots->nRoots = 0;
    } else if (compareDoubles(discriminant, 0)) {
        roots->nRoots = 1;
        roots->root1 = -coef->b / (2 * coef->a);
    } else {
        roots->nRoots = 2;
        if (coef->a > 0) {
            roots->root1 = (-coef->b - sqrt(discriminant)) / (2 * coef->a);
            roots->root2 = (-coef->b + sqrt(discriminant)) / (2 * coef->a);
        } else {
            roots->root1 = (-coef->b + sqrt(discriminant)) / (2 * coef->a);
            roots->root2 = (-coef->b - sqrt(discriminant)) / (2 * coef->a);
        }
    }
}
