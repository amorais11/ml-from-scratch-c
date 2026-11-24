#include <stdio.h>

double g(double x) { return x * x; }

int main(void) {
    double x = 3.0;
    double h = 1e-4; 
    double estimativa = (g(x + h) - g(x - h)) / (2.0 * h);
    printf("estimativa numerica: %f\n", estimativa);
    printf("derivada analitica (2x): %f\n", 2.0 * x);
    return 0;
}