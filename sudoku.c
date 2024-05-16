#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n){

   int rowcheck[9][10] = {0}; 
   int colcheck[9][10] = {0};
   int subgridcheck[3][3][10] = {0}; 

   for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
         int num = n->sudo[i][j];
   
         if (rowcheck[i][num] == 1) {
             return 0; 
         }
        
         rowcheck[i][num] = 1;
        
         if (colcheck[j][num] == 1) {
             return 0; 
         }
         colcheck[j][num] = 1;
        
         int subgrid_row = i / 3;
         int subgrid_col = j / 3;
         if (subgridcheck[subgrid_row][subgrid_col][num] == 1) {
             return 0; 
         }
         subgridcheck[subgrid_row][subgrid_col][num] = 1;
      }
    }
    return 1;
}


List* get_adj_nodes(Node* n){
    List* list=createList();

   int row = -1;
   int col = -1;
   for (int i = 0; i < 9 && row == -1; i++) {
      for (int j = 0; j < 9 && col == -1; j++) {
         if (n->sudo[i][j] == 0) {
         row = i;
         col = j;
         }
      }
   }
   if (row == -1) {
      return list;
   }
   for (int k = 1; k <= 9; k++) {
      Node* newnode = copy(n);
      newnode->sudo[row][col] = k;
      pushBack(list, newnode);
   }
   return list;
}


int is_final(Node* n){

   for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (n->sudo[i][j] == 0) {
                return 0;
            }
        }
   }
   return 1;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/