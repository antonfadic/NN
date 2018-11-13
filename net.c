#include <stdio.h> // in out
#include "stdlib.h" // for dynamic allocation
#include <time.h> // to compute time
#include "math.h" // math functions
#include "nnAuxFun.h" // nn Auxiliary functions
#include <unistd.h>
#include <sys/time.h>


double net(double *x, double *w, int *k){

    int i=0; int j;
    int nLayers = *(k+1); //number of hidden layers

    int Ln_1, Ln_0;
    double *L1; double *L0;
    double *b; double *wij;

    //structure of wij
    //b1...bn_HiddenLayer1 - wij (w11 w12... wlk) - b1...bn_hiddenLayer2
    //so the dimensions is L1 - L0*L1 - L2 - L1*L2 ... etc
    //                     3    2*3      3    3*3   1   3*1

    int temp=0;
    Ln_0  = *(k+2); //number of neurons in this layer
    Ln_1  = *(k+3); //number of neurons in the next layer

    L0 = malloc(sizeof(double)*Ln_0);
    L1 = malloc(sizeof(double)*Ln_1*Ln_0); memcpy(L1,x,sizeof(double)*Ln_0);

    for(i=0;i<nLayers;i++) {
        Ln_0  = *(k+2 + i); //number of neurons in this layer
        Ln_1  = *(k+3 + i); //number of neurons in the next layer
        L0 = realloc(L0,sizeof(double)*Ln_0); memcpy(L0,L1,sizeof(double)*Ln_0);
        L1 = realloc(L1,sizeof(double)*Ln_1);

        //relevant bias and weights
        b = w + temp;
        wij = b  + Ln_1;

        wij = transpose(wij,Ln_1, Ln_0); //necessary to transpose this matrix for matrix operation (matlab gives wrong order)

        for(j=0;j<Ln_1;j++){
            *(L1+j) = acFun(dotProd(Ln_0, wij, L0 ) + *(b+j));
            //printf("%4.4f \n", *(L1+i));
            wij = wij + Ln_0;
        }
        temp  += Ln_1 + Ln_0*Ln_1;
    }

    b   = w + temp;
    wij = w + temp + 1;

    //output layer. For this problem is a scalar and has the activation function purelin.
    double O;
    O = dotProd(Ln_1, wij, L1);
    O += *b;

    free(L1); free(L0);

    return O;
}
