#include <stdio.h>
#include "header.h"


int testSolve(const double a, const double b, const double c,
                const int nRootRight, const double x1right, const double x2right) {
    double x1 = 0, x2 = 0;
    const int nRoot = solve(a, b, c, &x1, &x2);
    if (!(nRoot == nRootRight && compareDoubles(x1, x1right) && compareDoubles(x2, x2right))) {
        printf("Fail: Solve(%lf, %lf, %lf, &x1, &x2) -> %d x1 = %lf, x2 = %lf, should be %d, x1 = %lf, x2 = %lf\n", a, b, c, nRoot, x1, x2, nRootRight, x1right, x2right);
        return 0;
    }
    return 1;
}
int test() {
    int countSuccess = 0;
    countSuccess += testSolve(1, -5, 6, 2, 2, 3);
    countSuccess += testSolve(1, -5, 6, 2, 2, 3);
    countSuccess += testSolve(1, 2, 1, 1, -1, 0);
    countSuccess += testSolve(1, 0, 1, 0, 0, 0);
    countSuccess += testSolve(0, 2, 4, 1, -2, 0);
    countSuccess += testSolve(0, 0, 1, 0, 0, 0);
    return countSuccess;
}
int main() {
    printf("Запуск тестирования\n");
    int testSuccess = test();
    printf("Тестирование завершено. Число успешных тестов: %d\n", testSuccess);
    return 0;
}
