#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void input_array(double *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("Введіть елемент %d: ", i + 1);
        scanf("%lf", &arr[i]);
    }
}

void process_arrays(double *a, int n, double *b, int m) {
    double s_a = 0, s_b = 0;
    double A = 0, B = 1, C = 0;
    double D = 0, E = 1, F = 0;

    for (int i = 0; i < n; i++) {
        s_a += a[i];
    }

    for (int i = 0; i < m; i++) {
        s_b += b[i];
    }

    for (int i = 0; i < n; i++) {
        A += a[i] * sin(a[i]);
        B *= a[i] * sin(a[i]);
        C += a[i] * cos(a[i]);
    }
    A *= s_a;
    C *= s_a;

    for (int i = 0; i < m; i++) {
        D += b[i] * tan(b[i]);
        E *= b[i] * cos(b[i]);
        F += b[i] * sin(b[i]);
    }
    D *= s_b;
    F *= s_b;
    double delta = (A * sin(B) + C) / (D * cos(E) + F);
    printf("Результат = %lf\n", delta);
}

int main() {
    system("chcp 65001");
    int n, m;
    printf("Введіть кількість елементів масиву a: ");
    scanf("%d", &n);
    printf("Введіть кількість елементів масиву b: ");
    scanf("%d", &m);

    double *a = (double *)malloc(n * sizeof(double));
    double *b = (double *)malloc(m * sizeof(double));

    if (a == NULL || b == NULL) {
        printf("Помилка виділення памʼяті\n");
        return 1;
    }

    printf("Введення елементів масиву a:\n");
    input_array(a, n);
    printf("Введення елементів масиву b:\n");
    input_array(b, m);
    process_arrays(a, n, b, m);
    return 0;
}