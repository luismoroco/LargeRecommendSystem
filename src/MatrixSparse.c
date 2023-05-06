#include <malloc.h>
#include <math.h>

#include "../include/MatrixSparse.h"

void makeMatrix(struct MatrixSparse *root, int lenUsers) {
  root->matrix = (struct LinkedList **) malloc( (lenUsers + 1) * sizeof(struct LinkedList));
  for (int i = 1; i <= lenUsers; ++i) {
    root->matrix[i] = (struct LinkedList *) malloc(sizeof(struct LinkedList));
    makeLL(root->matrix[i]);
  }
}

void addItemToMatrix(struct MatrixSparse *root, int index, float rating, int node) {
  insertNewNode(&root->matrix[index], rating, node);
}

void freeMemory(struct MatrixSparse *root, int usersLen) {
  for (int i = 0; i <= usersLen; ++i) {
    freeLL(root->matrix[i]);
  }
}

void printMatrix(struct MatrixSparse *root, int usersLen) {
  for (int i = 1; i <= usersLen; i++) {
    float t = sqrtf(root->matrix[i]->module);
    printf("module = %f\t", t);
  }
  
  printf("\n");
  for (int i = 1; i <= usersLen; ++i) {
    printLL(&root->matrix[i]);
  }
}
