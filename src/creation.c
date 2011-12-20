#include <stdio.h>
#include <stdlib.h>
#define ROW 6
#define COL 7

/// Create a new player
char* playerName(){
  char* name=malloc(80*sizeof(char)); 
  printf("entrer votre nom\n");
  scanf("%s",name);
  return name;
}

/// create a new table and initialize it
int** createTable(){
  int i,j;
  
  /* Create table */
  
  int **table=malloc(ROW*sizeof(int*));
  for(i=0;i<COL;i++){
    table[i]=malloc (COL*sizeof(int));
  }
  
  /*Initialize table*/
  
  for(i=0;i<COL;i++){
    for(j=0;j<ROW;j++){
      table[i][j]=0;
    }
  }
  
  return table;
  
}

///clear a table already used before
/// @param1: int **, table you want to clear
void clear_table(int **table){
  int i,j;
  
  for(i=0;i<COL;i++){
    for(j=0;j<ROW;j++){
      table[i][j]=0;
    }	
  }
}
void affiche_log(){
  
}
