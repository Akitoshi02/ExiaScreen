#ifndef FONCTION
#define FONCTION

#include "include.h"


void Createtabvir(TABVIRTUEL *tabvir, int H, int L);
void afftabvir(TABVIRTUEL * tabvir);
void *placement(TABVIRTUEL *grid, TABVIRTUEL *tabvir, int x, int y);
void moteurrendu(TABVIRTUEL *tabvir, PBM *file);

#endif