#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>

#include "input.h"
#include "tools.h"
#include "solve.h"

static int getCoefs(double* const a, double* const b, double* const c);
static int printAnswer(const int rootCount,
                    const double root1, const double root2);
void execute();

static int getCoefs(double* const a, double* const b, double* const c) {
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);

    int status = readNum(a);
    if (status == INCORRECT_INPUT) {
        return INCORRECT_INPUT;
    }

    status = readNum(b);
    if (status == INCORRECT_INPUT) {
        return INCORRECT_INPUT;
    }

    status = readNum(c);
    if (status == INCORRECT_INPUT) {
        return INCORRECT_INPUT;
    }
    return 0;
}
static int printAnswer(const eqRoots* const roots) {
    if (roots->nRoots == 0) {
        printf("Уравнение не имеет действительных решений\n");
        return 0;
    } else if (roots->nRoots == 1) {
        printf("Единственное действительное решение уравнения: %lf\n", roots->root1);
        return 0;
    } else if (roots->nRoots == 2) {
        printf("Действительные решения уравнения: \n%.4lf\n%.4lf\n", roots->root1, roots->root2);
        return 0;
    } else if (roots->nRoots == INF_SOLVES) {
        printf("Решение уравнения - множество действительных чисел\n");
        return 0;
    }
    return -1;
}
void execute() {
    printf("Введите коэффициенты уравнения ax^2 + bx + c = 0\na b c:\n");

    eqCoef coef = {};
    int status = getCoefs(&(coef.a), &(coef.b), &(coef.c));
    while (status == INCORRECT_INPUT) {
        printf("Неправильный формат, укажите 3 числа через пробел:\n");
        status = getCoefs(&(coef.a), &(coef.b), &(coef.c));
    }

    eqRoots roots = {};
    solve(&coef, &roots);

    printAnswer(&roots);
}
int main() {
    while (1) {
        execute();
    }
    return 0;
}

// enum exit struct
