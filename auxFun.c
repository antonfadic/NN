#include "math.h"

int calcNumWeights(int *nNeurons, int nDimIn, int nDimOut, int nLayers){
    int nWeights=0; int i=0;
    nWeights = (nDimIn+1)*(*nNeurons);
    for(i=1;i<nLayers;i++){ nWeights += (*(nNeurons+i-1)+1)*(*(nNeurons+i)); } nWeights += (*(nNeurons+i-1)+1)*nDimOut;
return nWeights;
}

double acFun(double n){
    return 2/(1+exp(-2*n))-1;
}

double dotProd(int n, double *x, double *y){
int i=0;
double sum=0;
for(i=0;i<n;i++){sum+= *(x+i)*(*(y+i)); }
return sum;
}

