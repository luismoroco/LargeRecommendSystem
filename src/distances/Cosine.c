#include "../include/distances/Cosine.h"
#define NULL 0

struct Pair dotProductBetween(struct LinkedList *from, struct LinkedList *to) {
  struct Pair res = {0.0f, 0};
  struct Node *prtFrom = from->root;
  struct Node *ptrTo = to->root;

  while (prtFrom != NULL && ptrTo != NULL) {
    if (prtFrom->index == ptrTo->index) {
      res.dot += prtFrom->rating * ptrTo->rating;
      prtFrom = prtFrom->next;
      ptrTo = ptrTo->next; 
      res.tamFound++;
    } else if (prtFrom->index < ptrTo->index) {
      prtFrom = prtFrom->next;
    } else {
      ptrTo = ptrTo->next;
    }
  } 

  return res;
}

float queryDotProductBetween(struct MatrixSparse *root, int src, int to) {
  //if (dpDot[src][to] != -1.0f && dpDot[to][src] != -1.0f) 
  //  return dpDot[src][to];

  struct Pair res = dotProductBetween(root->matrix[src], root->matrix[to]);
  //dpDot[src][to] = res.dot;
  //dpDot[to][src] = res.dot;
  //dpTamDot[to][src] = res.tamFound;
  //dpTamDot[src][to] = res.tamFound;

  return res.dot;
}
