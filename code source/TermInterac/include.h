#ifndef FINCLUDE
#define FINCLUDE

//Include des library
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/shm.h>

#include <math.h>

#include <pthread.h>
#include <dirent.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <assert.h>



//définition des structure !

//Structure du tableau virtuel
typedef struct TABVIRTUEL
{

    int H;
    int L;
    char **data;
    int type;
}TABVIRTUEL;

//Structure d'un fichier pbm
typedef struct PBM
{

    int H;
    int L;
    int random;
    char **data;
    int type;
}PBM;

//structure du répertoire d'images

typedef struct dirimg
{
    char **filelist;
    int taille;
}DIRIMG;

typedef struct COORD 
{
    int X;
    int Y;
}COORD;
//Enumeration pour le placement sur son axe de l'avions
typedef enum POSITION 
{
    HAUT, BAS, GAUCHE, DROITE
}POS;


#endif