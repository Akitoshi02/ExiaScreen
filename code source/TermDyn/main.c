#include "processus.h"

static struct termios ancien, nouveau;


//Ces fonction vont permettre de configurer le terminal afin d'enlever l'affichage des saisies
void initTerm(void);
void resetTerm(void);
char getch_(void);
void *stopevent(int *flagquit);


//Début main
int main(int argc, char *argv[])
{
    //Structure tableau virtuel
    TABVIRTUEL tabvir;
    //Structure fichier
    //Variable boucle
    int i = 0;
    PBM *file = NULL; //Fichier .pbm
    //Variable pour quitter le programme
    int flagquit = 0;
    //Variable taille du tableau virtuel
    int tailleL = 0, tailleH = 0;
    //Variable thread
    pthread_t thlecture, thstop;
    //Variable HEURE
    HEURE h;
    //Structure de la taille du shell
    struct winsize sterm;
    //Structure qui récupère la list des images
    DIRIMG *imglist;
    int tailleimg = 0;
    //Variable temps d'actualisation
    int temps = 1;

    //On récupère les paramètres envoyé au programmes
     if(argc == 3)
     {
         temps = atoi(argv[2]);
         if(temps == 0)
         {
             temps = 1;
         }
     }
     else
     {
         temps = 1;
     }

    //On enlève le curseur
    system("setterm -cursor off");
    //Vas permettre de récuperer les fichiers dans un tableau
    imglist = listrepertory(getenv("EXIASAVER2_PMB"));
    file = malloc(imglist->taille * sizeof(PBM));
    tailleimg = imglist->taille;
    free(imglist);

    
    //Lecture du fichier .pbm pour charger l'image
    //On lit le fichier dans un thread
   if (pthread_create(&thlecture, NULL, (void *)lirepbm, file)) 
    {
	    perror("pthread_create");    
    } 
    //thread qui va detecter l'appui d'une touche 
    if (pthread_create(&thstop, NULL, (void *)stopevent, &flagquit)) 
    {
	    perror("pthread_create");    
    } 

    //début de la boucle du programme pour actualiser l'heures et l'afficher
    h = getheure();
    do
    {
        //Le main attend la fin de la lecture du fichier !
        pthread_join(thlecture, NULL);
        //récupération de la taille du shell
        ioctl(0, TIOCGWINSZ, &sterm);
        tailleH = sterm.ws_row / 3;
        tailleL = sterm.ws_col;
        
        //Création du tableau virtuel
        Createtabvir(&tabvir, tailleH, tailleL);
   
        //Tout les temps on actualise l'horloge
        if(i == temps)
        {
            h = getheure();
            i = 0;
        }
        //Rendu du .pbm dans le tableau virtuel
        moteurrendu(&tabvir, file, tailleimg, h);
        //Affichage
        afftabvir(&tabvir);
        
        affrefresh(i, sterm.ws_col); //Affichaque de la phrase
        i++;
        sleep(1);

    }while(flagquit == 0);

    system("clear");

    return 0;
}
//Fin Main



//Définition des fonctions pour le main
void initTerm(void)
{
    tcgetattr(0, &ancien);
    nouveau = ancien;//Permettra de retourner au ancien paramètre
    nouveau.c_lflag &= ~ICANON;//On enlève l'obligation d'appuyer sur entrer
    nouveau.c_lflag &= ~ECHO;//On enlève l'affichage de la saisie'
    tcsetattr(0, TCSANOW, &nouveau);//On définie les nouveau paramètre du terminal
}
void resetTerm(void)
{
    tcsetattr(0, TCSANOW, &ancien);//On remet les anciens paramètre du terminal
}
char getch_(void)
{
    return getchar();
}
void *stopevent(int *flagquit)
{
    char ch = 0;
    initTerm();//On enlève l'affichage de la saisie'

    while(*flagquit != 1)
    {
        ch = getch_();//On récupère si l'user appuis sur une touche'
        if(ch != 0)
        {
            resetTerm();
            system("setterm -cursor on");
            *flagquit = 1;
        }
    }

   pthread_exit(0);  

}
