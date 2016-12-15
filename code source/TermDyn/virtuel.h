#ifndef FONCTION
#define FONCTION

#include "include.h"

//Permet de créer un tableau contenant un .pbm ou un autre tableau virtuel
void Createtabvir(TABVIRTUEL *tabvir, int H, int L);
//Permet d'afficher le tableau virtuel
void afftabvir(TABVIRTUEL *tabvir);
//Permet d'afficher la phrase d'actualisation du tableau dynamique
void affrefresh(int temps, int largeur);
//Affichaque en thread "OBSELETE"
void *affthread(TABVIRTUEL *tabvir);
//Moteur de rendu permet de rendre responsive le .pbm il redimensionne sellons la taille du contenant
void moteurrendu(TABVIRTUEL *tabvir, PBM *file, int tailleimg, HEURE h);

#endif