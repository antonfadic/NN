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

double transformY(double y, double *ty) {

double ymin = *ty;
double ymax = *(ty+1);

return (ymax-ymin)*(y+1)/2 + ymin;

}

double *transformX(double *y, double *ty, int L0) {

double ymin;
double ymax;
double *x=0; x = (double*) malloc(sizeof(double)*L0);
int i =0;

for(i=0;i<L0;i++){
    ymin = *(ty+2*i);
    ymax = *(ty+2*i+1);
    *(x+i) = 2/(ymax-ymin) * (*(y+i) - ymin ) - 1;
}
free(y);
return x;

}

double *transpose(double *x, int Ln_1, int Ln_0){
    int i,j;
    double *temp=0; temp = malloc(sizeof(double)*Ln_1*Ln_0);
    for(i=0; i<Ln_1; i++){
        for(j=0; j<Ln_0; j++){
            *(temp + i*Ln_0 + j) = *(x+ i + j*Ln_1);
        }
    }
    x = temp;
   free(temp);
return x;
}
