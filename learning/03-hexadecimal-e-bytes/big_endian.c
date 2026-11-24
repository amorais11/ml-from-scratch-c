#include <stdio.h>

unsigned int le_int_big_endian(const unsigned char b[4]) {
    unsigned int n = ((unsigned int)b[0] << 24) |
                     ((unsigned int)b[1] << 16) |
                     ((unsigned int)b[2] << 8)  |
                      (unsigned int)b[3];

    return n;
}

int main(void) {
    const unsigned char b[4] = {0x00, 0x00, 0x01, 0x2c};
    unsigned int n = le_int_big_endian(b);

    printf("%u\n", n);

    return 0;
}