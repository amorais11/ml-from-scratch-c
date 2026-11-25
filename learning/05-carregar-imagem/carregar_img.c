#include <stdio.h>
#include <stdlib.h>

unsigned int le_int_big_endian(const unsigned char b[4]) {
    unsigned int n = ((unsigned int)b[0] << 24) |
                     ((unsigned int)b[1] << 16) |
                     ((unsigned int)b[2] << 8)  |
                      (unsigned int)b[3];

    return n;
}

unsigned char *carregar_rotulos(const char *caminho, int *n_rotulos){
    
    FILE *f = fopen(caminho, "rb");
    if (f == NULL) {
        perror(caminho);
        return NULL;
    }

    unsigned char cab[8];
    if(fread(cab,1,8,f) != 8){
        printf("cabecalho de rotulos incompleto\n");
        fclose(f);
        return NULL;
    }

    if(le_int_big_endian(cab) != 2049) {
        printf("formato de rotulos invalido\n");
        fclose(f);
        return NULL;
    }

    size_t n = le_int_big_endian(cab + 4);

    unsigned char *rotulos = malloc(n * sizeof(unsigned char));
    if(rotulos == NULL) {
        printf("erro ao alocar memoria para os rotulos\n");
        fclose(f);
        return NULL;
    }

    if (fread(rotulos, 1, n, f) != n) {
        printf("erro ao ler os rotulos\n");
        fclose(f);
        free(rotulos);
        return NULL;
    }

    *n_rotulos = (int)n;

    fclose(f);
    return rotulos;
}

unsigned char *carregar_imagens(const char *caminho, int *n_imagens){
    FILE *f = fopen(caminho, "rb");
    if (f == NULL) {
        perror(caminho);
        return NULL;
    }
    
    unsigned char cab_img[16];
    if (fread(cab_img, 1, 16, f) != 16) {
        printf("cabecalho de imagens incompleto\n");
        fclose(f);
        return NULL;
    }

    if (le_int_big_endian(cab_img ) != 2051 || le_int_big_endian(cab_img + 8) != 28 || le_int_big_endian(cab_img + 12) != 28) {
        printf("formato de imagem invalido\n");
        fclose(f);
       return NULL;
    }
    
        size_t n = le_int_big_endian(cab_img + 4);

        size_t total = (size_t)n * 784;

        unsigned char *dados = malloc(total);
        if (dados == NULL) {
            printf("erro ao alocar memoria para as imagens\n");
            fclose(f);
            return NULL;
        }

    if (fread(dados, 1, total, f) != total) {
        printf("erro ao ler dados das imagens\n");
        free(dados);
        fclose(f);
        return NULL;
    }
    *n_imagens = (int)n;

    fclose(f);
    return dados;
}




int main() {

    int n, n_rotulos;
    int k = 0;
    unsigned char *imagens = carregar_imagens("data/train-images.idx3-ubyte", &n);

    if (imagens == NULL) {
        printf("erro ao carregar imagens\n");
        return 1;
    }

    printf("%d\n", n);

    unsigned char *rotulos = carregar_rotulos("data/train-labels.idx1-ubyte", &n_rotulos);
    printf("Rotulo %d: %d\n", k, rotulos[k]);


    for (int i = 0; i < 28; i++) {
        for (int j = 0; j < 28; j++) {
            if (imagens[0 * 784 + i * 28 + j] > 170) {
                putchar(' ');
            } else if (imagens[0 * 784 + i * 28 + j] > 85) {
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