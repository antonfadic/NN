#include <stdio.h> // in out
#include "stdlib.h" // for dynamic allocation
#include <time.h> // to compute time
#include "math.h" // math functions
#include "nnAuxFun.h" // nn Auxiliary functions
#include <unistd.h>
#include <sys/time.h>

void netFunc(){

    int *k=0;
    double *w=0;
    int i=0;

    k = readTableConfig();

    w = readWeights(*k);

    //for (i=0; i<*k; i++){
      //  printf("%4.4f \n", *(w+i));
    //}

    //don't forget to free the memory
    free(k);
    free(w);

}

    //Do the math

    /*
    //vector of biases
    //b=*(weights+*(nNeurons+1)); // q wea hice aqui

    double L[nNeurons[1]]; // intermediate layer
    double input[nDimIn];
    input[0] = -1; input[1] = -0.3; input[2] = 1; input[3] = 0.5;

    gettimeofday(&timecheck, NULL);
    start = (long)timecheck.tv_sec * 1000 + (long)timecheck.tv_usec / 1000;


    for (w=0;w<1;w++){

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

    }

    gettimeofday(&timecheck, NULL);
    end = (long)timecheck.tv_sec * 1000 + (long)timecheck.tv_usec / 1000;

    printf("%ld milliseconds elapsed\n", (end - start));
    */
