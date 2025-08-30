#include <stdio.h>
#include <assert.h>
#include "tools.h"
#include "solve.h"


#define  RED  "\033[1;31m"
#define  GREEN "\033[1;32m"
#define  RESET "\033[0m"

struct eqData {
    eqCoef coef;
    eqRoots roots;
};

int testSolve(const eqData* const data);
int test();

int testSolve(const eqData* const data) {
    assert(data != NULL);

    eqRoots rootsCalc = {};
    solve(&(data->coef), &rootsCalc);
    if (!(rootsCalc.nRoots == data->roots.nRoots && compareDoubles(rootsCalc.root1, data->roots.root1) && compareDoubles(rootsCalc.root2, data->roots.root2))) {
        printf("%s", RED);
        printf("Fail: Solve(%lf, %lf, %lf, &x1, &x2) -> %d x1 = %lf, x2 = %lf, should be %d, x1 = %lf, x2 = %lf\n", data->coef.a, data->coef.b, data->coef.c, rootsCalc.nRoots, rootsCalc.root1, rootsCalc.root2, data->roots.nRoots, data->roots.root1, data->roots.root1);
        printf("%s", RESET);
        return 0;
    }
    return 1;
}

int test() {
    eqData testList[] = {{.coef = {.a = 1, .b = -5, .c = 6},
                        .roots = {.nRoots = 2, .root1 = 2, .root2 = 3}},
                        {.coef = {.a = 1, .b = 2, .c = 1},
                        .roots = {.nRoots = 1, .root1 = -1, .root2 = 0}}
                        };
    const int nTest = sizeof(testList) / sizeof(eqData);

    int countSuccess = 0;
    for (int i = 0; i < nTest; i++) {
        countSuccess += testSolve(&testList[i]);
    }
    return countSuccess;
}

int main() {
    printf("Запуск тестирования\n");
    int testSuccess = test();
    printf("Тестирование завершено. Число успешных тестов: %d\n", testSuccess);
    return 0;
}
