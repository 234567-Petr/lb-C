#include <stdio.h>
#include <math.h>



double integral(double a, double b, int n);


int main() {
    double a, b, E;
    int n = 1;

    printf("Введите a: ");
    scanf("%lf", &a);

    printf("Введите b: ");
    scanf("%lf", &b);

    printf("Введите погрешность E: ");
    scanf("%lf", &E);

    double Factor = 0.0;
    double risultat = integral(a, b, n);

   
    while (fabs(risultat - Factor) > E) {
        Factor = risultat;
        n *= 2;
        risultat = integral(a, b, n);
    }

    printf("Значение интеграла: %f\n", risultat);

    return 0;
}

double integral(double a, double b, int n) {
    double sum = 0.0;
    double dx = (b - a) / n; 

    for (int i = 1; i <= n; i++) {
        double x = (a-1) + i * dx; 
        sum += log(x) * dx; 
    }

    return sum;
}