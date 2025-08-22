#include <stdio.h>
#include <math.h>
#include <assert.h>

const int INF_SOLVES = -1;
const double EPS = 1e-6;
const int MAX_INPUT = 100;

int compareDoubles(const double number1, const double number2);
int ReadInt(const char str[], int* const i, double* const num);
int GetCoef(double* const a, double* const b, double* const c);
int Solve(const double a, const double b, const double c,
                    double* const root1, double* const root2);
int SolveLinear(const double a, const double b,
                    double* const root);
int SolveSquare(const double a, const double b, const double c,
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

int ReadInt(const char input[], int* const i, double* const num) {
    assert(num != NULL);
    *num = 0;
    if (input[*i] < '0' || input[*i] > '9') {
        return -1;
    }
    for (; input[*i] >= '0' && input[*i] <= '9'; *i = *i + 1) {
        *num = *num * 10 + (input[*i] - '0');
    }
    if (input[*i] == ' ') {
        *i = *i + 1;
        return 0;
    }
    if (input[*i] == '\n') {
        return 1;
    }
    return -1;
}

int GetCoef(double* const a, double* const b, double* const c) {
    char input[MAX_INPUT];

    fgets(input, MAX_INPUT, stdin);
    int i = 0;
    int status = ReadInt(input, &i, a);
    if (status != 0) {
        return -1;
    }
    status = ReadInt(input, &i, b);
    if (status != 0) {
        return -1;
    }
    status = ReadInt(input, &i, c);
    if (status != 1) {
        return -1;
    }
    return 0;
}

int Solve(const double a, const double b, const double c,
                    double* const root1, double* const root2) {
    assert(root1 != NULL);
    assert(root2 != NULL);

    if (compareDoubles(a, 0)) { // проверяем степень уравнения // int solveLinear()
        return SolveLinear(b, c, root1);
    } else {
        return SolveSquare(a, b, c, root1, root2);
    }
}

int SolveLinear(const double a, const double b, double* const root) {
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

int SolveSquare(const double a, const double b, const double c,
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
    printf("Введите коэффициенты уравнения ax^2 + bx + c = 0\na b c:\n");

    double a = 0, b = 0, c = 0;


    int status = GetCoef(&a, &b, &c);
    while (status != 0) {
        printf("Неправильный формат, укажите 3 числа через пробел:\n");
        status = GetCoef(&a, &b, &c);
    }

    double root1 = 0, root2 = 0;
    const int RootCount = SolveSquare(a, b, c, &root1, &root2);

    printAnswer(RootCount, root1, root2);


    return 0;
}
