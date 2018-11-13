int calcNumWeights(int *nNeurons,int nDimIn, int nDimOut, int nLayers);

double acFun(double n);

double dotProd(int n, double *x, double *y);

int *readTableConfig();

double *readWeights(int nWeights);

void netFunc();

double net(double *x, double *w, int *k);

double *loadTy();

double *loadTx(int k);

double transformY(double y, double* ty);

double *transformX(double *x, double *ty, int L0);

double *transpose(double *x, int Ln_1, int Ln_0);
