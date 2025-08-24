#ifndef EQUATION_H
#define EQUATION_H
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>

const int INF_SOLVES = -1;
const int INCORRECT_INPUT = -1;
const double EPS = 1e-6;
const int MAX_INPUT = 100;

int solve(const double a, const double b, const double c,
                    double* const root1, double* const root2);
int solveLinear(const double a, const double b,
                    double* const root);
int solveSquare(const double a, const double b, const double c,
                    double* const root1, double* const root2);

int testSolve(double a, double b, double c,
                        int nRootRight, double x1right, double x2right);
int test();

int compareDoubles(const double number1, const double number2);

int checkChar();
int goStrEnd(int c);
double getFracPart(int* const c, double* const num);
double getIntPart(int* const c, double* const num);
int checkMinus(int* const c);
int readNum(double* const num);

#endif
