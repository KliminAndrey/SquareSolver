#ifndef INPUT
#define INPUT

enum status {
    INCORRECT_INPUT = -1,
    CONTINUE
};

/**
 * @brief Считывает число
 *
 * @details Принимает из потока ввода целое число
 *
 * @param[out] num указатель, по которому будет записано число
 *
 * @return 0, если ввод успешен, или INCORRECT_INPUT, если число считать не удалось
 */
int readNum(double* const num);

#endif
