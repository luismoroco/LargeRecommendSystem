#include "../include/distances/Manhattan.h"

#define NULL 0

float manhattanBetween(struct LinkedList *from, struct LinkedList *to) {
  float manh = 0.0f;
  struct Node *prtFrom = from->root;
  struct Node *ptrTo = to->root;

  while (prtFrom != NULL && ptrTo != NULL) {
    if (prtFrom->index == ptrTo->index) {
      manh += fabs(prtFrom->rating - ptrTo->rating);
      prtFrom = prtFrom->next;
      ptrTo = ptrTo->next; 
    } else if (prtFrom->index < ptrTo->index) {
      prtFrom = prtFrom->next;
    } else {
      ptrTo = ptrTo->next;
    }
  } 

  return manh;
}

float queryManhattanBetween(struct MatrixSparse *root, int src, int to) {
  return manhattanBetween(root->matrix[src], root->matrix[to]);
}