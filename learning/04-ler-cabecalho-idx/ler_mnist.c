#include <stdio.h>

unsigned int le_int_big_endian(const unsigned char b[4]){
    unsigned int n = ((unsigned int) b[0] << 24)|
                    ((unsigned int)b[1] << 16)|
                    ((unsigned int)b[2] << 8)|
                    ((unsigned int)b[3]);

    return n;
}

int main(){
    unsigned int n;
    const unsigned char b[4] = {0xFF, 0xFF, 0x02, 0x00};
    n = le_int_big_endian(b);
    printf("%u\n",n);

    return 0;
}
