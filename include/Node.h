/**
 * Node Stores basic information about Music
 * related with a user
 */

struct Node
{
  float rating;
  int index;
  struct Node *next;
};

struct Node* makeNode(float, int);
