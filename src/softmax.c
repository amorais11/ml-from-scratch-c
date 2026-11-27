#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../src/softmax.h"



void softmax(const float z[], float p[], int n){
    float maior = z[0];
    float soma = 0;
    for(int i = 1; i < n; i++){
        if(z[i] > maior) maior = z[i];
    }
    for(int i = 0; i < n; i++){
        p[i] = expf(z[i] - maior); 
        soma += p[i];
       }
    for(int i = 0; i < n; i++){
        p[i] = (p[i]/ soma);
    }
}