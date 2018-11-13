#include <stdio.h> // in out
#include "stdlib.h" // for dynamic allocation
#include <time.h> // to compute time
#include "math.h" // math functions
#include "nnAuxFun.h" // nn Auxiliary functions
#include <unistd.h>
#include <sys/time.h>


//load neural network config

int *readTableConfig(){
    FILE * fp1;
    FILE * fp;

    int *nLayers=0;
    int nL =0;

    nLayers = (int*) malloc(2*sizeof(int));

    //this reads the number of layers

    fp1 = fopen("config.bin", "rb");
    fread(nLayers, 2, sizeof(int), fp1);
    fclose(fp1);

    nL = *(nLayers+1);

    int *ptr2 = 0; ptr2 = (int*) malloc((nL+5)*sizeof(int));

    if(ptr2==NULL){printf("Memory not allocated. Closing readTableConfig"); exit(0);}
    fp = fopen ("config.bin", "rb");
    //printf("Reading config file... \n");
    fread(ptr2,1,(3*nL+2)*sizeof(*ptr2),fp);
    fclose (fp);
    //ptr is: number of weights, number of layers, neurons layer 1, neurons layer 2, ... neurons layer n, neurons out.

    free(nLayers);
    return ptr2;
}


double *readWeights(int nWeights){
    FILE * fp;
    double *ptr2 = 0; ptr2 = (double*) malloc(nWeights*sizeof(double));
    if(ptr2==NULL){printf("Memory not allocated. Closing readTableConfig"); exit(0);}
    fp = fopen ("weights.bin", "rb");
    //printf("Reading weights file... \n");
    fread(ptr2,1,nWeights*sizeof(*ptr2),fp);
    fclose (fp);
    //ptr is: number of weights, number of layers, neurons layer 1, neurons layer 2, ... neurons layer n, neurons out.

    return ptr2;
}

double *loadTy(){
    FILE * fp;
    double *ptr2 = 0; ptr2 = (double*) malloc(2*sizeof(double));
    if(ptr2==NULL){printf("Memory not allocated. Closing readTableConfig"); exit(0);}
    fp = fopen ("yLimits.bin", "rb");
    //printf("Reading weights file... \n");
    fread(ptr2,1,2*sizeof(*ptr2),fp);
    fclose (fp);
    //ptr is: number of weights, number of layers, neurons layer 1, neurons layer 2, ... neurons layer n, neurons out.

    return ptr2;
}

double *loadTx(int k){
    FILE * fp;
    double *ptr2 = 0; ptr2 = (double*) malloc(2*k*sizeof(double));
    if(ptr2==NULL){printf("Memory not allocated. Closing readTableConfig"); exit(0);}
    fp = fopen ("xLimits.bin", "rb");
    //printf("Reading weights file... \n");
    fread(ptr2,1,2*k*sizeof(*ptr2),fp);
    fclose (fp);
    //ptr is: number of weights, number of layers, neurons layer 1, neurons layer 2, ... neurons layer n, neurons out.

    return ptr2;
}

