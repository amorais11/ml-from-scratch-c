#include <stdio.h>
#include <stdlib.h>
#include "../src/softmax.h"


int main(){
    float z[3] = {2, 1, 0.1};
    float p[3] = {0};

    softmax(z,p,3);

    for(int i = 0; i < 3; i++){
        printf("%.3f ",p[i]);
    }

    printf("\n");

    return 0;
}