#ifndef FCOMMAND
#define FCOMMAND

#include "repertoire.h"

//Affiche les aides
void CMDhelp();
//Affiche l'historique
void CMDstat();

//Date et heure
char *getdate();
void setlog(char *date, char *log);

#endif