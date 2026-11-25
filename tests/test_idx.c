#include <stdio.h>
#include <stdlib.h>
#include "idx.h"

int main() {

    int n, n_rotulos;
    int k = 0  ;
    unsigned char *imagens = carregar_imagens("data/train-images.idx3-ubyte", &n);

    if (imagens == NULL) {
        printf("erro ao carregar imagens\n");
        return 1;
    }

    printf("%d\n", n);

    unsigned char *rotulos = carregar_rotulos("data/train-labels.idx1-ubyte", &n_rotulos);
    if(rotulos == NULL) {
        printf("erro ao carregar rotulos\n");
        free(imagens);
        return 1;
    }
    if(n != n_rotulos) {
        printf("numero de imagens e rotulos nao correspondem\n");
        free(imagens);
        free(rotulos);
        return 1;
    }

    if(k < n && k < n_rotulos) {
        printf("Rotulo %d: %d\n", k, rotulos[k]);
    }

    for (int i = 0; i < 28; i++) {
        for (int j = 0; j < 28; j++) {
            if (imagens[k * 784 + i * 28 + j] > 170) {
                putchar(' ');
            } else if (imagens[k * 784 + i * 28 + j] > 85) {
                putchar('.');
            } else {
                putchar('#');
            }
        }
        putchar('\n');
        }
    free(imagens);
    free(rotulos);
    return 0;
}