#include <stdlib.h>
#include <stdio.h>

#include "../include/Node.h"

struct Node* makeNode(float rating, int index) {
  struct Node* node = (struct Node*) malloc(sizeof(struct Node));
  if (node == NULL) {
    perror("Error while trying to init node!\n");
    exit(EXIT_FAILURE);
  }

  node->rating = rating;
  node->next = NULL;
  node->index = index;
  return node;
}