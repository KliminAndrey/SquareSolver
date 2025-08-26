#ifndef SOLVE
#define SOLVE

const int INF_SOLVES = -1;

struct eqCoef{
    double a, b, c;
};
struct eqRoots{
    int nRoots;
    double root1, root2;
};

void solve(const eqCoef* const coef,
                eqRoots* const roots);
#endif
