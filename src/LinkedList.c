#include <malloc.h>

#include "../include/LinkedList.h" 

void makeLL(struct LinkedList *head) {
  head->root = NULL;
  head->tail = NULL;
  head->size = 0;
  head->module = 0.0f;
  head->sum = 0.0f;
}

void insertNewNode(struct LinkedList **head, float rating, int index) {
  struct Node *node = makeNode(rating, index);

  if (*head == NULL) {
    *head = (struct LinkedList *) malloc(sizeof(struct LinkedList));
    makeLL(*head);
  }

  if ((*head)->root == NULL) {
    (*head)->root = node;
    (*head)->tail = node;
    (*head)->size += 1;
    (*head)->module += node->rating * node->rating;
    (*head)->sum += node->rating;
  } else {
    (*head)->tail->next = node;
    (*head)->tail = node;
    (*head)->size += 1;
    (*head)->module += node->rating * node->rating;
    (*head)->sum += node->rating;
  }
}

void freeLL(struct LinkedList *head) {
  struct Node* current = head->root;
  struct Node* next;
  while (current != NULL) {
    next = current->next;
    free(current);
    current = next;
  }
  free(head);
}

void printLL(struct LinkedList **head) {
  struct Node *tmp = (*head)->root;
  while (tmp != NULL) {
    printf(" -> %f", tmp->rating);
    tmp = tmp->next;
  }
  printf("\n");
}
