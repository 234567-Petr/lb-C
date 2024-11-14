#include <stdio.h>
#include <stdlib.h>

void spiralOrder(int** matrix, int matrixSize, int matrixColSize, int* result, int* returnSize) {
    // Если матрица пустая, возвращаем 0
    if (matrixSize == 0 || matrixColSize == 0) {
        *returnSize = 0;
        return;
    }

    // Определяем границы для обхода матрицы
    int start_row = 0; // Начальная строка
    int end_row = matrixSize - 1; // Конечная строка
    int start_col = 0; // Начальный столбец
    int end_col = matrixColSize - 1; // Конечный столбец

    *returnSize = 0; // Количество элементов в результате

    // Пока есть еще строки и столбцы для обхода
    while (start_row <= end_row && start_col <= end_col) {
        // Проход по верхней строке
        for (int col = start_col; col <= end_col; col++) {
            result[(*returnSize)++] = matrix[start_row][col];
        }
        start_row++; // Переходим к следующей строке

        // Проход по правому столбцу
        for (int row = start_row; row <= end_row; row++) {
            result[(*returnSize)++] = matrix[row][end_col];
        }
        end_col--; // Переходим к предыдущему столбцу

        // Проверяем, остались ли строки для обхода
        if (start_row <= end_row) {
            for (int col = end_col; col >= start_col; col--) {
                result[(*returnSize)++] = matrix[end_row][col];
            }
            end_row--; // Переходим к предыдущей строке
        }

        // Проверяем, остались ли столбцы для обхода
        if (start_col <= end_col) {
            for (int row = end_row; row >= start_row; row--) {
                result[(*returnSize)++] = matrix[row][start_col];
            }
            start_col++; // Переходим к следующему столбцу
        }
    }
}

int main() {
    // Создаем матрицу
    int matrixSize;
    int matrixColSize;
    printf("Введите количество строк: ");
    scanf("%d", &matrixSize);
    printf("Введите количество столбцов: ");
    scanf("%d", &matrixColSize);

    // Выделяем память для матрицы
    int** matrix = (int**)malloc(matrixSize * sizeof(int*));
    for (int i = 0; i < matrixSize; i++) {
        matrix[i] = (int*)malloc(matrixColSize * sizeof(int));
    }

    int value = 1;
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize; j++) {
            matrix[i][j] = value++;
        }
    }
    

    // Массив для результата и его размер
    int* result = (int*)malloc(matrixSize * matrixColSize * sizeof(int));
    int returnSize;

    // Получаем элементы в спиральном порядке
    spiralOrder(matrix, matrixSize, matrixColSize, result, &returnSize);

    // Выводим результат
    printf("Элементы матрицы в спиральном порядке: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    return 0;
}