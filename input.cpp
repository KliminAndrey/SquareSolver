#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <stdlib.h>
#include "input.h"

static int checkChar();
static int goStrEnd(int c);
static double getFracPart(int* const c, double* const num);
static double getIntPart(int* const c, double* const num);
static int checkMinus(int* const c);
static void skipSpaces(int* const c);

static int checkChar() {
    const int c = getchar();
    if (c == EOF) {
        printf("Завершение программы\n");
        exit(0);
    }
    return c;
}
static int goStrEnd(int c) {
    while (c != '\n') {
        c = checkChar();
    }
    return 0;
}
static double getFracPart(int* const c, double* const num) {
    assert(c != NULL);
    assert(num != NULL);

    if (*c != '.' && *c != ',') {
        return 0;
    }

    *c = checkChar();
    double fracPart = 0;
    while (*c >= '0' && *c <= '9') {
        fracPart = fracPart * 10 + ((double)(*c - '0'));
        *c = checkChar();
    }

    while (fracPart >= 1) {
        fracPart /= 10;
    }
    *num += fracPart;
    return 0;
}
static double getIntPart(int* const c, double* const num) {
    assert(c != NULL);
    assert(num != NULL);

    while (*c >= '0' && *c <= '9') {
        *num = *num * 10 + (*c - '0');
        *c = checkChar();
    }
    return 0;
}
static int checkMinus(int* const c) {
    assert(c != NULL);

    if (*c == '-') {
        *c = checkChar();
        return -1;
    }
    return 1;
}
static void skipSpaces(int* const c) {
    assert(c != NULL);

    do {
        *c = checkChar();
    } while (isspace(*c));
}
int readNum(double* const num) {
    assert(num != NULL);

    int c = '\0';
    *num = 0;

    skipSpaces(&c);
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
