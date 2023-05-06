/**
 * LL stored the data, in nodes, of all music
 * calificated from user indexed in order
*/

#include "Node.h"

struct LinkedList
{
  struct Node *root;
  struct Node *tail;
  int size;
  float module;
  float sum;
};

void makeLL(struct LinkedList*);
void insertNewNode(struct LinkedList**, float, int);
void freeLL(struct LinkedList*);
void printLL(struct LinkedList**);
