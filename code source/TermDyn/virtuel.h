#ifndef FONCTION
#define FONCTION

#include "include.h"


void Createtabvir(TABVIRTUEL *tabvir, int H, int L);
void afftabvir(TABVIRTUEL *tabvir);

void *affthread(TABVIRTUEL *tabvir);

void moteurrendu(TABVIRTUEL *tabvir, PBM *file);

#endif