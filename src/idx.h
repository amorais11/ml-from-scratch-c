#ifndef IDX_H
#define IDX_H

unsigned int le_int_big_endian(const unsigned char b[4]);

unsigned char *carregar_rotulos(const char *caminho, int *n_rotulos);

unsigned char *carregar_imagens(const char *caminho, int *n_imagens);






#endif // IDX_H