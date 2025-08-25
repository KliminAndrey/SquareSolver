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

static int getCoefs(double* const a, double* const b, double* const c) {
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);

    int status = readNum(a);
    if (status != 0) {
        return INCORRECT_INPUT;
    }

    status = readNum(b);
    if (status != 0) {
        return INCORRECT_INPUT;
    }

    status = readNum(c);
    if (status != 0) {
        return INCORRECT_INPUT;
    }
    return 0;
}
static int printAnswer(const int RootCount, const double root1, const double root2) {
    if (RootCount == 0) {
        printf("Уравнение не имеет действительных решений\n");
        return 0;
    } else if (RootCount == 1) {
        printf("Единственное действительное решение уравнения: %lf\n", root1);
        return 0;
    } else if (RootCount == 2) {
        printf("Действительные решения уравнения: \n%.4lf\n%.4lf\n", root1, root2);
        return 0;
    } else if (RootCount == INF_SOLVES) {
        printf("Решение уравнения - множество действительных чисел\n");
        return 0;
    }
    return -1;
}
int main() {
    printf("Введите коэффициенты уравнения ax^2 + bx + c = 0\na b c:\n");

    double a = 0, b = 0, c = 0;

    int status = getCoefs(&a, &b, &c);
    while (status == INCORRECT_INPUT) {
        printf("Неправильный формат, укажите 3 числа через пробел:\n");
        status = getCoefs(&a, &b, &c);
    }

    double root1 = 0, root2 = 0;
    const int RootCount = solve(a, b, c, &root1, &root2);

    printAnswer(RootCount, root1, root2);
    return 0;
}

