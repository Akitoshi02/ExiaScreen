#ifndef PBMFILE
#define PBMFILE

#include "virtuel.h"


typedef struct PBM
{

    int H;
    int L;
    char **data;
}PBM;


typedef struct dirimg
{
    char **filelist;
    int taille;
}dirimg;

void lirepbm(PBM *f);
dirimg *listrepertory(char *dir);


#endif