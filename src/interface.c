#include <stdio.h>
#include <stdlib.h>

enum bool{false, true};
typedef enum bool bool;

int main (int argc,char* argv[]){
  bool exit=false;
  int choix;
  int **table = NULL;
  
  table = createTable();
  printf("\n\n*******************************\n Bienvenue dans le puissance 4\n *******************************\n");
  while (exit == false){
    printf("Pour commencer une partie tapez [1]\nquittez[2]\n");
    scanf("%d",&choix);
    switch (choix){
    case 1 :
      partie(table);
      break;
    case 2 :
      exit = true;
      break;
    default :
      printf("veuillez inscrire un chiffre entre 1 et 3\n\n\n");
      break;
    }
  }
}

   
