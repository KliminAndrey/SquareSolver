#ifndef TOOLS
#define TOOLS

const double EPS = 1e-4;

/**
 * @brief Сравнивает неточные числа
 *
 * @details Проверяет, равны ли с точностью до EPS числа типа double
 *
 * @param[in] number1 одно из чисел
 * @param[in] number2 второе число
 *
 * @return Равны ли числа, true или false
 */
bool compareDoubles(const double number1, const double number2);

#endif
