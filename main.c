#include <stdio.h>
#include <math.h>


int main() {
    printf("Введите коэффициенты уравнения ax^2 + bx + c = 0\na b c:\n");

    float a, b, c;
    scanf("%f %f %f", &a, &b, &c);
    double firstRoot, secondRoot;

    if (a == 0) { // проверяем степень уравнения
        if (b != 0) { // решаем уравнение вида bx + c = 0
            firstRoot = -c / b;
            printf("Единственное действительное решение уравнения: %f\n", firstRoot);
            return 0;
        } else if (b == 0 && c == 0) { // уравнение вида 0 * x = 0
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
    } else if (discriminant == 0) {
        firstRoot = -b / (2 * a);
        printf("Единственное действительное решение уравнения: %f\n", firstRoot);
        return 0;
    } else {
        firstRoot = (-b - sqrt(discriminant)) / (2 * a);
        secondRoot = (-b + sqrt(discriminant)) / (2 * a);
        printf("Действительные решения уравнения:\n%f\n%f", firstRoot, secondRoot);
        return 0;
    }
}
