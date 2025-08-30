#ifndef SOLVE
#define SOLVE

const int INF_SOLVES = -1;

/**
 * \struct eqCoef
 * \brief Набор коэффициентов полинома a*x^2 + bx + c
 *
 */
struct eqCoef{
    double a, b, c;
};

/**
 * \struct eqRoots
 * \brief Два или менее корня и их количество
 *
 */
struct eqRoots{
    int nRoots; ///< Количество корней
    double root1; ///< Первый корень, когда nRoots > 0
    double root2; ///< Второй корень, когда nRoots = 2
};

/**
 * @brief Получает корни уравнения
 *
 * @details По полученным коэффициентам квадратного уравнения вычисляет количество корней и их значения
 *
 * @param[in] coef указатель на коэффициенты уравнения
 * @param[out] roots указатель, по которому будут записаны корни
 *
 * \example
 * \code{.cpp}
 * eqCoef coefficients = {1.0, -3.0, 2.0}; // x^2 - 3x + 2 = 0
 * eqRoots solutions;
 *
 * solve(&coefficients, &solutions);
 *
 * // solutions.nRoots будет равно 2
 * // solutions.root1 = 1.0, solutions.root2 = 2.0
 * \endcode
 */
void solve(const eqCoef* const coef,
                eqRoots* const roots);
#endif
