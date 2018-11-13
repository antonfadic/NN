#include <stdio.h> // in out
#include "stdlib.h" // for dynamic allocation
#include <time.h> // to compute time
#include "math.h" // math functions
#include "nnAuxFun.h" // nn Auxiliary functions
#include <unistd.h>
#include <sys/time.h>
/*
Compute a neural network in C based on a Matlab fully connected fitnet
Anton Fadic
Chemical and Materials Engineering Nov 2018
*/


int main()
{
    double y=0; //for now y is set for only 1 output
    double *x=0;
    int i=0;

    double *ty=0; ty = loadTy();
    double *tx=0;

    struct timeval timecheck;
    srand(time(NULL));
    long start, end;

    x = (double*) malloc(2*sizeof(double));

    int *k; double *w;
    //read weights only once
    k = readTableConfig();
    int L0 = *(k+2);
    tx = loadTx(L0);

    gettimeofday(&timecheck, NULL);

    w = readWeights(*k);

    start = (long)timecheck.tv_sec * 1000 + (long)timecheck.tv_usec / 1000;

    for(i=0;i<400000;i++){
    *x = 0; *(x+1) = 1;
    x = transformX(x,tx, L0);
    y = net(x, w, k);
    y = transformY(y,ty);
    }

    printf("y is %4.4f \n", y);

    gettimeofday(&timecheck, NULL);
    end = (long)timecheck.tv_sec * 1000 + (long)timecheck.tv_usec/1000;

    printf("Average time is %ld ms \n", (end-start));

    getchar();

    free(k);
    free(w);
    free(ty);
    free(tx);
    free(x);

    return 0;
}
