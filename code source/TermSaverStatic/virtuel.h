#ifndef FONCTION
#define FONCTION

#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <pthread.h>
#include <dirent.h>
#include <string.h>
#include <time.h>


typedef struct TABVIRTUEL
{

    int H;
    int L;
    char **data;
}TABVIRTUEL;



void Createtabvir(TABVIRTUEL *tabvir, int H, int L);
void afftabvir(TABVIRTUEL * tabvir);

void *affthread(TABVIRTUEL * tabvir);

#endif