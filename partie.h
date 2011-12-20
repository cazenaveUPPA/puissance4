
#ifndef partie.h
#define partie.h
int parity (int number);

char* playerName();

void addTokken(int player,int col,int** table);

void display(int** table);

int check(int player,int** table);

void partie(int** table);

#endif
