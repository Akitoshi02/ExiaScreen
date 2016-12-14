#ifndef FINCLUDE
#define FINCLUDE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/shm.h>


#include <dirent.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <assert.h>
typedef struct dirimg
{
    char **filelist;
    int taille;
}DIRIMG;

#endif