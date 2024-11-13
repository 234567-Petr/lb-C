#include <stdio.h>

double calculate(double E);
double Proverka();
int main() {
    double E = Proverka();
    double itog = calculate(E);
    printf("Сумма ряда: %lf\n", itog);

    return 0;
}

double calculate(double E) {
    double Number = 1.0; 
    double sum = 0;
    int n = 1;
    
    while (Number >= E) {
        Number /= n;
        sum += Number;
        n++;
    }

    return sum;
}
double Proverka(){
    double ros;
    printf("Введите значение: ");
    if (!(scanf("%lf", &ros))){
        printf("Ввод не коректен");
        return -1;
    }
    else{
        return ros > 0? ros: -1;
    }

}   