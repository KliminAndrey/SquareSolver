#include <stdio.h>
#include <math.h>

const double EPS = 1e-6;

int isZero(double number);
int isZero(double number) {
    if (number > -EPS && number < EPS) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    printf("Введите коэффициенты уравнения ax^2 + bx + c = 0\na b c:\n");

    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    double firstRoot, secondRoot;

    if (isZero(a)) { // проверяем степень уравнения
        if (isZero(b)) { // решаем уравнение вида bx + c = 0
            firstRoot = -c / b;
            printf("Единственное действительное решение уравнения: %lf\n", firstRoot);
            return 0;
        } else if (isZero(b) && isZero(c)) { // уравнение вида 0 * x = 0
            printf("Решение уравнения - множество действительных чисел\n");
            return 0;
        } else { // уравнение вида c = 0
            printf("Уравнение не имеет действительных решений\n");
            return 0;
        }
    }

    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        printf("Уравнение не имеет действительных решений\n");
        return 0;
    } else if (isZero(discriminant)) {
        firstRoot = -b / (2 * a);
        printf("Единственное действительное решение уравнения: %lf\n", firstRoot);
        return 0;
    } else {
        firstRoot = (-b - sqrt(discriminant)) / (2 * a);
        secondRoot = (-b + sqrt(discriminant)) / (2 * a);
        printf("Действительные решения уравнения: \n%.4lf\n%.4lf\n", firstRoot, secondRoot);
        return 0;
    }
}
