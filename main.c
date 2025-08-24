#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>
#include "header.h"

const int INF_SOLVES = -1;
const int INCORRECT_INPUT = -1;
const double EPS = 1e-6;
const int MAX_INPUT = 100;

double getFracPart(int* c);
double getIntPart(int* const c, double* const num);
int checkMinus(int* const c);
int goStrEnd(int c);
int readNum(double* const num);
int getCoefs(double* const a, double* const b, double* const c);
int solveLinear(const double a, const double b,
                    double* const root);
int solveSquare(const double a, const double b, const double c,
                    double* const root1, double* const root2);
int printAnswer(const int rootCount,
                    const double root1, const double root2);

int compareDoubles(const double number1, const double number2) {
    const double dif = number1 - number2;
    if (dif > -EPS && dif < EPS) {
        return 1;
    } else {
        return 0;
    }
}

int goStrEnd(int c) {
    while (c != '\n') {
        c = getchar();
    }
    return 0;
}
double getFracPart(int* const c, double* const num) {
    assert(c != NULL);

    if (*c != '.' && *c != ',') {
        return 0;
    }

    *c = getchar();
    double fracPart = 0;
    while (*c >= '0' && *c <= '9') {
        fracPart = fracPart * 10 + ((double)(*c - '0'));
        *c = getchar();
    }

    while (fracPart >= 1) {
        fracPart /= 10;
    }
    *num += fracPart;
    return 0;
}
double getIntPart(int* const c, double* const num) {
    assert(c != NULL);
    assert(num != NULL);

    while (*c >= '0' && *c <= '9') {
        *num = *num * 10 + (*c - '0');
        *c = getchar();
    }
    return 0;
}
int checkMinus(int* const c) {
    assert(c != NULL);

    if (*c == '-') {
        *c = getchar();
        return -1;
    }
    return 1;
}
int readNum(double* const num) {
    assert(num != NULL);

    int c = '\0';
    *num = 0;

    do {
        c = getchar();
    } while (isspace(c));

    if (c != '-' && (c < '0' || c > '9')) {
        goStrEnd(c);
        return INCORRECT_INPUT;
    }

    const int sign = checkMinus(&c);

    if (c < '0' || c > '9') {
        goStrEnd(c);
        return INCORRECT_INPUT;
    }

    getIntPart(&c, num);
    getFracPart(&c, num);

    if (!isspace(c)) {
        goStrEnd(c);
        return INCORRECT_INPUT;
    }

    *num = *num * sign;

    return 0;
}
int getCoefs(double* const a, double* const b, double* const c) {
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
    return -2;
}

int printAnswer(const int RootCount, const double root1, const double root2) {
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

/*
    1. Расставить const
    2. Ещё поразбивать код на функции
    3. Исправить ввод
*/

int main() {
    test();
    printf("Введите коэффициенты уравнения ax^2 + bx + c = 0\na b c:\n");

    double a = 0, b = 0, c = 0;


    int status = getCoefs(&a, &b, &c);
    while (status == INCORRECT_INPUT) {
        printf("Неправильный формат, укажите 3 числа через пробел:\n");
        status = getCoefs(&a, &b, &c);
    }

    double root1 = 0, root2 = 0;
    const int RootCount = solveSquare(a, b, c, &root1, &root2);

    printAnswer(RootCount, root1, root2);


    return 0;
}
//  считывание даблов
