#include <stdio.h>
#include <stdlib.h>

/// check if a number is "pair" or "impair"
/// @param1: int, number to test
int parity (number){
  if(number & 1){
    return 1;
  }
  else{
    return 0;
  }
}


/// add a token on the table
/// @param1: int, player 1 or player 0
/// @param2: int, in which col we have to put the token on
/// @param3: char**, game table 
void addTokken(int player,int col,int **table){
  int i=5;
  //verification 0<col<6
  if(col<0 || col>6){
    printf("dommage ! ton choix de colonne est incorrect. Tu passes donc ton tour! (ton adversaire a le droit de te remercier)\n");
  }
  else{
    // verification of the col (if it's full)
    if(table[col][i]==0){
      // search of the downer case which isn't allready used
      while(table[col][i]==0 && i>=0){
	i--;
      }
      // put the right tokken (player 1 or 2) on the table (hum...grid seem a better word than table...whatever, table is nice)
      if(player==0){
	table[col][i+1]=2;
      }
      else{
	table[col][i+1]=1;
      }
    }
    else{
      printf("bravo tu as choisi une colonne deja pleine ! Pour la peine tu ne joues pas ce tour ci !\n");
    }
  }
}
/// display the game table
/// @param1: char**, game table  
void display(int **table){
  int i,j;
  
  printf("| 0 | 1 | 2 | 3 | 4 | 5 | 6 |\n");
  printf("|---|---|---|---|---|---|---|\n");
  for (j=5;j>=0;j--){
    for (i=0;i<=6;i++){
      switch (table[i][j]){
      case 1:
	printf("| X ");
	break;
      case 2:
	printf("| O ");
	break;
      default :
	printf("|   ");
	break;
      }
      
    }
    printf("|\n");
  }
  printf("-----------------------------\n");
}

/// check if one player win
/// @param1: char*, who player we have to check
/// @param2: char**, game table
int check(int player,int **table){
  int col,row;
  /// horizontal check
  for(row=0;row<6;row++){
    
    for (col=0;col<4;col++){
      
      if(player==0){
	if(table[col][row]==2 && table[col+1][row]==2 && table[col+2][row]==2 && table[col+3][row]==2){
	  
	  return 1;
	}
      }
      else{
	if(table[col][row]==1 && table[col+1][row]==1 && table[col+2][row]==1 && table[col+3][row]==1){
	  
	  return 1;
	}
	
      }
    }	
  }
  
  /// vertical check
  for(col=0;col<7;col++){
    for(row=0;row<4;row++){
      if(player==0){
	if(table[col][row]==2 && table[col][row+1]==2 && table[col][row+2]==2 && table[col][row+3]==2){
	  return 1;
	}
      }
      else{
	if(table[col][row]==1 && table[col][row+1]==1 && table[col][row+2]==1 && table[col][row+3]==1){
	  return 1;
	}
      }
    }
    
  }
  /// diagonal left to right check 
  for(row=0;row<3;row++){
    for(col=0;col<4;col++){
      if(row+3<6 && col+3<7){
	if(player==0){
	  if(table[col][row]==2 && table[col+1][row+1]==2 && table[col+2][row+2]==2 && table[col+3][row+3]==2){
	    return 1;
	  }
	}
	else{
	  if(table[col][row]==1 && table[col+1][row+1]==1 && table[col+2][row+2]==1 && table[col+3][row+3]==1){
	    return 1;
	  }
	}
      }
    }
  }
  /// diagonal right to left
  for(row=5;row>=3;row--){
    for(col=0;col<4;col++){
      if(row-3>=0 && col+3<=7){
	if(player==0){
	  if(table[col][row]==2 && table[col+1][row-1]==2 && table[col+2][row-2]==2 && table[col+3][row-3]==2){
	    return 1;
	  }
	}
	else{
	  if(table[col+1][row-1]==1 && table[col+1][row-1]==1 && table[col+1][row-1]==1 && table[col][row]==1){
	    return 1;
	  }
	}
      }
    }
  }
  return 0;	
}

/// main procedure who lead the game
/// @param1: int**, table you want to play on
void partie(int **table){
  char* name1=malloc(20*(sizeof(char)));
  char* name2=malloc(20*sizeof(char));
  int round=1,win=0,col,gamer;
  clear_table(table);
  name1=playerName();
  name2=playerName();
  while (win == 0 && round<=42){
    display(table);
    gamer=parity(round);
    if(gamer==1) printf("%s, indiquez dans quelle colonne placer le jeton : \n",name1);
    else printf("%s, indiquez dans quelle colonne placer le jeton : \n",name2);
    scanf("%d",&col);
    addTokken(gamer,col,table);
    win=check(gamer,table);
    round++;
  }

  if(round<=42){
    if(gamer==1){
      printf("Bravo %s a gagné !!!\n", name1);
    }
    else{
      printf("Bravo %s a gagné !!!\n", name2);
    }
  }
  else{
    printf("personne n'a gagné ...\n");
  }
}
    
   
  
