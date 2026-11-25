
#include <stdio.h>
#include "tensor.h"

int main() {
    float A[6] = {1, 2, 3, 4, 5, 6};
    float x[3] = {2, 5, 1};
    int entrada = 3;
    int saida = 2;
    float y[2] = {0};

    matvec(A, x, y, saida, entrada);

    for (int i = 0; i < saida; i++) {
        printf("%.0f ", y[i]);
    }
    printf("\n");

    return 0;
}