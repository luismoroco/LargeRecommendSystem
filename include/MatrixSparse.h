/**
 * MatrixSparse is based on LL, each index LL repond to an unique user 
 * index in order
*/

#include "LinkedList.h"

struct MatrixSparse
{
  struct LinkedList **matrix;
};

void makeMatrix(struct MatrixSparse*, int);
void addItemToMatrix(struct MatrixSparse*, int, float, int);
void freeMemory(struct MatrixSparse*, int);
void printMatrix(struct MatrixSparse*, int);
