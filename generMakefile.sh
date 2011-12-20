#!/bin/bash

#générateur de Makefile

echo Pour mettre les valeur par default lesser vide
read -p "Choisissez le compilateur (CC pour le c ou CPP pour le c++ / CPP par default) : " compilateur
if [  -z $compilateur ]
then
    compilateur=CPP
fi

read -p "Option de compilation (default : -I): " optionCompil
if [ -z $optionCompil ]
then
    optionCompil='-I'
fi

read -p "Option d'edition de lien (default : -g): " optionDeLien
if [ -z $optionDeLien ]
then
    optionDeLien='-g'
fi

read -p "Nom de l'executable a generer (default : monExecutable): " executable
if [ -z $executable ]
then
    executable=monExecutable
fi

echo Par defaut les prochaines valeurs sont le répertoire courant
read -p "Repertoire ou se trouvent les sources (.c ou .cpp) : " SRC
if [ -z $SRC ]
then
    SRC='.'    
fi
mSRC=$SRC

read -p "Repertoire ou se trouvent les objets (.o) : " OBJ
if [ -z $OBJ ]
then
    OBJ='.'
fi

read -p "Repertoire ou se trouvent les executable : " BIN
if [ -z $BIN ]
then
    BIN='.'
fi

read -p "Repertoire ou se trouvent les librairies (.h) : " INCLUDE
if [ -z $INCLUDE ]
then
    INCLUDE='.'
fi




if [ $compilateur = CC -o $compilateur = cc ]
then
    ext=.c
    compilateur='CC=gcc'
    copl=CFLAGS
    optionCompil='CFLAGS='$optionCompil
    optionDeLien='LDFLAGS='$optionDeLien
    executable='EXEC=$(BIN)'$executable
    SRC='SRC='$SRC/
    OBJ='OBJ='$OBJ/
    BIN='BIN='$BIN/
    INCLUDE='INCLUDE='$INCLUDE/
else
    if [ $compilateur = CPP -o $compilateur = cpp ]
    then
	ext=.cpp
	compilateur='CPP=g++'
	copl=CXXLAGS
	optionCompil='CXXLAGS='$optionCompil
	optionDeLien='LDFLAGS='$optionDeLien
	executable='EXEC=$(BIN)'$executable
	SRC='SRC='$SRC/
	OBJ='OBJ='$OBJ/
	BIN='BIN='$BIN/
	INCLUDE='INCLUDE='$INCLUDE'/'
    else
	echo "Le compilateur choisi n'existe pas."
    fi
fi

read -p "Nom du fichier contenant le main (ex : monMain.c ou mon main.cpp): " monMain
if [ -z $monMain ]
then
    echo Erreur il faut un main
    exit
fi
mMa=$monMain
monMain='$(SRC)'$monMain
# Ecriture du Makefile
echo " "> Makefile
echo '######################################################'>> Makefile
echo '#   Makefile generer automatiquement par un script   #'>> Makefile
echo '#           ecrit par Laurent Hartanerot             #'>> Makefile
echo '######################################################'>> Makefile
echo " ">> Makefile
echo "# Compilateur utilise CC en c CPP en c++" >> Makefile
echo $compilateur >> Makefile
echo "# Option de compilation CFLAGS en c, CXXFLAGS en c++" >> Makefile
echo $optionCompil >> Makefile
echo "# Option de l'edition de lien" >> Makefile
echo $optionDeLien >> Makefile
echo "# Repertoire de mes sources .cpp ou .c" >> Makefile
echo $SRC >> Makefile
echo "# Repertoire de mes objets .o" >> Makefile
echo $OBJ >> Makefile
echo "# Repertoire de mon executable" >> Makefile
echo $BIN >> Makefile
echo "# Repertoire de mes lib .h" >> Makefile
echo $INCLUDE >> Makefile
echo "# Nom de l'executable a generer" >> Makefile
echo $executable >> Makefile


echo " ">> Makefile

echo "# Premier etiquette qui sera celle lancé par default">> Makefile
echo 'all : $(EXEC)' >> Makefile
echo " ">> Makefile



for i in $mSRC/*$ext
do

    if [ $i != $mSRC/$mMa ]
    then
	echo -n '$(OBJ)'`basename $i $ext`".o : " >> Makefile
	mesPointsO=$mesPointsO' $(OBJ)'`basename $i $ext`".o" 
	for j in `cat $i | fgrep \#include\ \" | cut -d"\"" -f2 | tr "\\n" " "`
	do
	    echo -n '$(INCLUDE)'$j" ">> Makefile
	done
	echo " ">> Makefile
	echo " ">> Makefile
    fi
done

echo '$(EXEC) : '$monMain $mesPointsO>> Makefile
echo -ne '\t'>> Makefile
echo '$(CPP) $(LDFLAGS) -o $@ $<' $mesPointsO '$('$copl') $(INCLUDE)'>> Makefile
echo " ">> Makefile
echo '$(OBJ)%.o : $(SRC)'%$ext '$(INCLUDE)%.h'>> Makefile
echo -ne '\t'>> Makefile
echo '$(CPP) $(LDFLAGS) -o $@ -c $< $('$copl') $(INCLUDE)'>> Makefile
echo " ">> Makefile
echo 'clean :' >> Makefile
echo -ne '\t'>> Makefile
echo 'rm $(OBJ)*.o' >> Makefile
echo " ">> Makefile
echo 'mrproper : clean' >> Makefile
echo -ne '\t'>> Makefile
echo 'rm $(EXEC)' >> Makefile
echo " ">> Makefile



echo " Votre Makefile a ete genere tapez make dans votre terminal pour le lancer "



