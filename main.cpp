#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>

#include "input.h"
#include "tools.h"
#include "solve.h"

static int getCoefs(double* const a, double* const b, double* const c);
static int printAnswer(const eqRoots* const roots);
static int execute();

int main(int argc, char* argv[]) {
    int nEq = 1000;
    if (argc >= 3 && strcmp(argv[1], "--file") == 0) {
        const char* fileName = argv[2];
        FILE* ptrFile = fopen(fileName, "r");
        if (ptrFile == NULL) {
            printf("Файл не найден, используется ввод с клавиатуры\n");
        } else {
            nEq = atoi(argv[3]);
            freopen(fileName, "r", stdin);
        }
    }
    int status = CONTINUE;
    for (int i = 0; i < nEq && status == CONTINUE; i++) {
        status = execute();
    }
    return 0;
}

static int execute() {
    printf("Введите коэффициенты уравнения ax^2 + bx + c = 0\na b c:\n");

    eqCoef coef = {};
    int status = getCoefs(&(coef.a), &(coef.b), &(coef.c));
    if (status == EOF) {
        return 0;
    }
    while (status == INCORRECT_INPUT) {
        printf("Неправильный формат, укажите 3 числа через пробел:\n");
        if ((status = getCoefs(&(coef.a), &(coef.b), &(coef.c))) == EOF) {
            return EOF;
        }
    }

    eqRoots roots = {};
    solve(&coef, &roots);

    printAnswer(&roots);
    return 0;
}

static int getCoefs(double* const a, double* const b, double* const c) {
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);

    int status = 0;
    if ((status = readNum(a)) != 0) {
        return status;
    }

    if ((status = readNum(b)) != 0) {
        return status;
    }

    if ((status = readNum(c)) != 0) {
        return status;
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
