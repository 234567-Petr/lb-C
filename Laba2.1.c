#include <stdio.h>

double calculateSum(double E);

int main() {
    double E;
    printf("\nВведите точность E: ");
    scanf("%lf", &E); 

    double result = calculateSum(E);
    printf("Сумма ряда: %lf\n", result);

    return 0;
}

double calculateSum(double E) {
    double firstNum = 1.0; 
    double sum = 0;
    int n = 1;

    while (firstNum > E) {
        firstNum /= n;
        sum += firstNum;
        n++;
    }

    return sum;
}