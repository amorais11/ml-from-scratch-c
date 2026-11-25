#include <stdio.h>

//leitura do arquivo de imagens

unsigned int le_int_big_endian(const unsigned char b[4]) {
    unsigned int n = ((unsigned int)b[0] << 24) |
                     ((unsigned int)b[1] << 16) |
                     ((unsigned int)b[2] << 8)  |
                      (unsigned int)b[3];

    return n;
}

int main() {
    FILE *f = fopen("/home/amorais/Área de trabalho/ML_FINAL/ml-from-scratch-c/data/train-labels.idx1-ubyte", "rb");
    if (f == NULL) {
        perror("/home/amorais/Área de trabalho/ML_FINAL/ml-from-scratch-c/data/train-labels.idx1-ubyte");
        return 1;
    }

    FILE *x = fopen("/home/amorais/Área de trabalho/ML_FINAL/ml-from-scratch-c/data/train-images.idx3-ubyte", "rb");
    if (x == NULL) {
        perror("/home/amorais/Área de trabalho/ML_FINAL/ml-from-scratch-c/data/train-images.idx3-ubyte");
        fclose(f);
        return 1;
    }

    unsigned char cab_rot[8];
    if (fread(cab_rot, 1, 8, f) != 8) {
        printf("cabecalho de rotulos incompleto\n");
        fclose(f);
        fclose(x);
        return 1;
    }

    printf("%u\n", le_int_big_endian(cab_rot));
    printf("%u\n", le_int_big_endian(cab_rot + 4));
    printf("\n");

    unsigned char rotulo[1];
    if (fread(rotulo, 1, 1, f) != 1) {
        printf("erro ao ler o rotulo\n");
        fclose(f);
        fclose(x);
        return 1;
    }

    printf("%d\n", rotulo[0]);

    unsigned char cab_img[16];
    if (fread(cab_img, 1, 16, x) != 16) {
        printf("cabecalho de imagens incompleto\n");
        fclose(f);
        fclose(x);
        return 1;
    }

    unsigned char img[784];
    if (fread(img, 1, 784, x) != 784) {
        printf("erro ao ler a imagem\n");
        fclose(f);
        fclose(x);
        return 1;
    }

    /*for (int i = 0; i < 28; i++) {
        for (int j = 0; j < 28; j++) {
            if (img[i * 28 + j] > 170) {
                putchar(' ');
            } else if (img[i * 28 + j] > 85) {
                putchar('.');
            } else {
                putchar('#');
            }
        }
        putchar('\n');
    }*/

    fclose(f);
    fclose(x);
    return 0;
}