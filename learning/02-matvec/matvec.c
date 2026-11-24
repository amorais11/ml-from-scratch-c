#include <stdio.h>

void matvec(const float A[], const float x[], float y[], int saida, int entrada) {
    for (int i = 0; i < saida; i++) {
        float num = 0.0f;
        for (int j = 0; j < entrada; j++) {
            num += A[i * entrada + j] * x[j];
        }
        y[i] = num;
    }
}

int main(void) {
    float A[6] = {1, 2, 3, 4, 5, 6};
    float x[3] = {2, 5, 1};
    int entrada = 3;
    int saida = 2;
    float y[2] = {0};

    matvec(A, x, y, saida, entrada);

    for (int i = 0; i < saida; i++) {
        printf("%.0f\n", y[i]);
    }

    for (int i = 0; i < 6; i++) {
        printf("%.0f\n", A[i]);
    }

    return 0;
}