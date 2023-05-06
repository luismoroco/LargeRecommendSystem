#include "../include/distances/Eucledian.h"
#define NULL 0

float eucledianBetween(struct LinkedList *from, struct LinkedList *to) {
  float dist = 0.0f;
  struct Node *prtFrom = from->root;
  struct Node *ptrTo = to->root;

  while (prtFrom != NULL && ptrTo != NULL) {
    if (prtFrom->index == ptrTo->index) {
      dist += pow(prtFrom->rating - ptrTo->rating, 2);
      prtFrom = prtFrom->next;
      ptrTo = ptrTo->next; 
    } else if (prtFrom->index < ptrTo->index) {
      prtFrom = prtFrom->next;
    } else {
      ptrTo = ptrTo->next;
    }
  } 

  return dist;
}

float queryEucledianBetween(struct MatrixSparse*root, int src, int to) {
  return eucledianBetween(root->matrix[src], root->matrix[to]);
}