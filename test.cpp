#include <stdio.h>

#include "tools.h"
#include "solve.h"

enum colors {
    RED   = "\033[1;31m",
    GREEN = "\033[1;32m",
    RESET = "\033[0m"
};

int testSolve(const double a, const double b, const double c,
                const int nRootRight, const double x1right, const double x2right);
int test();

static struct eqData{
    eqCoef coef;
    eqRoots roots;
}

int testSolve(const eqData* const data) {
    asserts(data != NULL);

    eqRoots rootsCalc = {};
    solve(&(eqData->coef), &rootsCalc);
    if (!(rootsCalc->nRoots == eqData->eqRoots->nRoots && compareDoubles(rootsCalc->root1, eqData->eqRoots->root1) && compareDoubles(rootsCalc->root2, eqData->eqRoots->root2))) {
        printf("%s", RED);
        printf("Fail: Solve(%lf, %lf, %lf, &x1, &x2) -> %d x1 = %lf, x2 = %lf, should be %d, x1 = %lf, x2 = %lf\n", eqData->eqCoef->a, eqData->eqCoef->b, eqData->eqCoef->c, rootsCalc.nRoots, rootsCalc.x1, rootsCalc.x2, eqData->eqRoot->c, eqData->eqCoef->root1, eqData->eqCoef->root1);
        printf("%s", RESET);
        return 0;
    }
    return 1;
}
int test() {
    eqData testList[] = {{coef = {a = 1, b = -5, c = 6},
                        roots = {nRoots = 2, root1 = 2, root = 3}}
                        {coef = {a = 1, b = 2, c = 1},
                        roots = {nRoots = 1, root1 = -1, root = 0}}
                        {coef = {a = 1, b = 0, c = 1},
                        roots = {nRoots = 0, root1 = 0, root = 0}}
                        };
    int nTest = sizeof(testList) / sizeof(eqData);

    int countSuccess = 0;
    for (int i = 0; i < nTest; i++) {
        countSuccess += testSolve(testList[i]);
    }
    return countSuccess;
}
int main() {
    printf("Запуск тестирования\n");
    int testSuccess = test();
    printf("Тестирование завершено. Число успешных тестов: %d\n", testSuccess);
    return 0;
}
