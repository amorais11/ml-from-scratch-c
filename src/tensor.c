#include <stdio.h>

#include "tensor.h"


void matvec(const float A[], const float x[], float y[], int saida, int entrada) {
    for (int i = 0; i < saida; i++) {
        float num = 0.0f;
        for (int j = 0; j < entrada; j++) {
            num += A[i * entrada + j] * x[j];
        }
        y[i] = num;
    }
}

