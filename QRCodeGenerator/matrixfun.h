#ifndef MATRIXFUN
#define MATRIXFUN

int **makeMatrix(int *data, int version);
void addFinder(int **matrix, int **patterns, int cornerx, int cornery);
void setInfoAreas(int **matrix, int **patterns, int dimval);
void layoutData(int **matrix, int **patterns, int *data, int dim, int ver);

#endif