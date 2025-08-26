#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <stdlib.h>
#include "input.h"


static int checkChar();
static int goStrEnd(int c);
static int getFracPart(int* const c, double* const num);
static int getIntPart(int* const c, double* const num);
static int checkMinus(int* const c);
static int skipSpaces(int* const c);

static int checkChar() {
    const int c = getchar();
    if (c == EOF) {
        printf("Завершение программы\n");
        return EOF;
    }
    return c;
}

static int goStrEnd(int c) {
    while (c != '\n') {
        if ((c = checkChar()) == EOF) {
            return EOF;
        }
    }
    return 0;
}

static int getFracPart(int* const c, double* const num) {
    assert(c != NULL);
    assert(num != NULL);

    if (*c != '.' && *c != ',') {
        return 0;
    }

    if ((*c = checkChar()) == EOF) {
        return EOF;
    }
    double fracPart = 0;

    int pow = 1;
    while (*c >= '0' && *c <= '9') {
        double newNum = (double)(*c - '0');
        for (int i = 0; i < pow; i++) {
            newNum /= 10;
        }
        pow += 1;

        fracPart += newNum;
        if ((*c = checkChar()) == EOF) {
            return EOF;
        }
    }

    while (fracPart >= 1) {
        fracPart /= 10;
    }
    *num += fracPart;
    return 0;
}

static int getIntPart(int* const c, double* const num) {
    assert(c != NULL);
    assert(num != NULL);

    while (*c >= '0' && *c <= '9') {
        *num = *num * 10 + (*c - '0');
        if ((*c = checkChar()) == EOF) {
            return EOF;
        }
    }
    return 0;
}

static int checkMinus(int* const c) {
    assert(c != NULL);

    if (*c == '-') {
        if ((*c = checkChar()) == EOF) {
            return EOF;
        }
        return -1;
    }
    return 1;
}

static int skipSpaces(int* const c) {
    assert(c != NULL);

    do {
        if ((*c = checkChar()) == EOF) {
            return EOF;
        }
    } while (isspace(*c));
    return 0;
}

int readNum(double* const num) {
    assert(num != NULL);

    int c = '\0';
    *num = 0;

    int status = 0;
    if ((status = skipSpaces(&c)) != 0) {
            return status;
    }

    if (c != '-' && (c < '0' || c > '9')) {
        if (goStrEnd(c) != 0) {
            return EOF;
        }
        return INCORRECT_INPUT;
    }

    const int negative = checkMinus(&c);
    if (negative == EOF) {
        return negative;
    }

    if (c < '0' || c > '9') {
        if (goStrEnd(c) != 0) {
            return EOF;
        }
        return INCORRECT_INPUT;
    }

    if ((status = getIntPart(&c, num)) != 0) {
        return status;
    }
    if ((status = getFracPart(&c, num)) != 0) {
        return status;
    }

    if (!isspace(c)) {
        if (goStrEnd(c) != 0) {
            return EOF;
        }
        return INCORRECT_INPUT;
    }

    if (negative) {
        *num = *num * (-1);
    }

    return 0;
}
