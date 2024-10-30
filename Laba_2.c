#include <stdio.h>
#include <math.h>



double countIntegral(double a, double b, int n);


int main() {
    double a, b, E;
    int n = 1;

    printf("Введите a: ");
    scanf("%lf", &a);

    printf("Введите b: ");
    scanf("%lf", &b);

    printf("Введите погрешность E: ");
    scanf("%lf", &E);

    double previousResult = 0.0;
    double result = countIntegral(a, b, n);

   
    while (fabs(result - previousResult) > E) {
        previousResult = result;
        n *= 2;
        result = countIntegral(a, b, n);
    }

    printf("Значение интеграла: %f\n", result);

    return 0;
}

double countIntegral(double a, double b, int n) {
    double sum = 0.0;
    double dx = (b - a) / n; 

    for (int i = 1; i <= n; i++) {
        double x = (a-1) + i * dx; 
        sum += log(x) * dx; 
    }

    return sum;
}