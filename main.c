#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/MatrixSparse.h"

#define MAX_USERS 610
#define LINE 1024
#define BOOKS_INPUT 9742
#define BUFFER 200

char *iFiLeName = "/home/lmr/Documentos/5to/TDS/code/LargeRecommendSystem/data/small/out.txt";
char *iMovName = "/home/lmr/Documentos/5to/TDS/code/LargeRecommendSystem/data/small/outmov.txt";

char *sparTitle[BOOKS_INPUT + 1];
int sparIndex[BOOKS_INPUT + 1];

float dpDot[MAX_USERS + 1][MAX_USERS + 1];
int dpTamDot[MAX_USERS + 1][MAX_USERS + 1];

int main() {
  FILE *iMov;
  iMov = fopen(iMovName, "r");
  if (iMov == NULL) {
    perror("Error while opening iMov the File!\n");
    exit(EXIT_FAILURE);
  }
 
  int id;
  int i = 1;
  char line[LINE];
  char buffer[BUFFER];
  while (fgets(line, sizeof(line), iMov) != NULL && i <= BOOKS_INPUT) {
    if (sscanf(line, "%d\t %[^\n]", &id, buffer) == 2) {
      sparTitle[i] = malloc(strlen(buffer) + 1);
      sparIndex[i] = id;
      strcpy(sparTitle[i], buffer);
      ++i;
    }
  }

  fclose(iMov);
  
  FILE *iFile;
  iFile = fopen(iFiLeName, "r");
  if (!iFile) {
    perror("Error while opening iFile the File!\n");
    exit(EXIT_FAILURE);
  }

  struct MatrixSparse matrix;
  makeMatrix(&matrix, MAX_USERS);

  int head, node;
  float rating;
  while (fscanf(iFile, "%d\t%d\t%f", &head, &node, &rating) != EOF) {
    if (rating != 0) {
      addItemToMatrix(&matrix, head, rating, node);
    }
  }

  fclose(iFile);

  

  



  return 0;
}
