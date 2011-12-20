 
# Compilateur utilise CC en c CPP en c++
CC=gcc
# Option de compilation CFLAGS en c, CXXFLAGS en c++
CFLAGS=-I
# Option de l'edition de lien
LDFLAGS=
# Repertoire de mes sources .cpp ou .c
SRC=src/
# Repertoire de mes objets .o
OBJ=obj/
# Repertoire de mon executable
BIN=bin/
# Repertoire de mes lib .h
INCLUDE=include/
# Nom de l'executable a generer
EXEC=$(BIN)Puissance_4
 
# Premier etiquette qui sera celle lancé par default
all : $(EXEC)
 
$(EXEC) : $(SRC)interface.c $(SRC)interface.c $(INCLUDE)interface.h $(SRC)partie.c $(INCLUDE)partie.h $(SRC)creation.c $(INCLUDE)creation.h
	$(CC) $(LDFLAGS) -o $(BIN)Puissance_4 $(SRC)interface.c $(SRC)creation.c $(SRC)partie.c -I $(INCLUDE)
 
clean :
	rm $(EXEC)
 
mrproper : clean
	rm $(BIN)*~ $(SRC)*~ $(INCLUDE)*~ $(OBJ)*~
 

