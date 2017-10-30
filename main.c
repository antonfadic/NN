#include <stdio.h> // in out
#include "stdlib.h" // for dynamic allocation
#include <time.h> // to compute time
#include "math.h" // math functions
#include "nnAuxFun.h" // nn Auxiliary functions
#include <unistd.h>
#include <sys/time.h>

int main()
{
    //main variables
    int nDimIn= 4;
    int nDimOut=1;
    int nLayers = 6;
    long start, end;
    struct timeval timecheck;

    int i=0;
    int j=0;
    int nNeurons[nLayers]; //vector of number of neurons per layer.
    int nWeights = 0; //number of weights of the net

    //Set the architecture of the net
    for(i=0; i<nLayers;i++){nNeurons[i]=12; } //set the number of neurons per layer

    nWeights = calcNumWeights(nNeurons,nDimIn,nDimOut,nLayers);

    printf("nWeights is %i \n",nWeights);
    printf("Map size is %f kB \n",(double) nWeights*8/1000);

    double weights[nWeights];


    //weights should be considered a tensor of rank 3. w_ijk.
    //The index i represents the origin neuron, j the arriving neuron and k the layer.
    //So that the calculation of an intermediate layer is: Ljk = f(w_ijk*Ii+bjk)

    for(i=0;i<nWeights;i++){*(weights+i)= (double) i/nWeights ; }

    //vector of biases
    //b=*(weights+*(nNeurons+1)); // q wea hice aqui

    double L[nNeurons[1]]; // intermediate layer
    double input[nDimIn];
    input[0] = -1; input[1] = -0.3; input[2] = 1; input[3] = 0.5;

    gettimeofday(&timecheck, NULL);
    start = (long)timecheck.tv_sec * 1000 + (long)timecheck.tv_usec / 1000;


    for(i=0;i<nNeurons[1];i++) {
        L[i] = acFun( dotProd(nDimIn, weights+nNeurons[1]*i,input)); // bias is missing
    }
    double L2[nNeurons[1]]; for(i=0;i<nNeurons[1];i++){L2[i]=L[i];}

    for(i=0;i<nNeurons[2];i++) {
        L[i] = acFun( dotProd(nNeurons[1], weights+nNeurons[1]*i,L2)); // bias is missing
    }

    for(i=0;i<nNeurons[2];i++){L2[i]=L[i];}

    for(i=0;i<nNeurons[3];i++) {
        L[i] = acFun( dotProd(nNeurons[2], weights+nNeurons[1]*i,L2)); // bias is missing
    }

    gettimeofday(&timecheck, NULL);
    end = (long)timecheck.tv_sec * 1000 + (long)timecheck.tv_usec / 1000;

    printf("%ld milliseconds elapsed\n", (end - start));
    return 0;
}
