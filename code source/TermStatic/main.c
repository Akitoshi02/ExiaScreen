#include "processus.h"

static struct termios ancien, nouveau;


//Ces fonction vont permettre de configurer le terminal afin d'enlever l'affichage des saisies
void initTerm(void);
void resetTerm(void);
char getch_(void);
void *stopevent(int *flagquit);



int main(int argc, char *argv[])
{
    //Structure tableau virtuel
    TABVIRTUEL tabvir; //tableau virtuel
    //Structure fichier
    PBM file; //Fichier .pbm
    file.data = NULL;
    //Variable pour quitter le programme
    int flagquit = 0;
    int tailleL = 0, tailleH = 0;
    pthread_t thlecture, thstop;
    struct winsize sterm;
    char * dir = NULL;
    //Structure qui récupère la list des images
    DIRIMG *imglist;
    int tailleimg = 0;
     float ratio = 0.0;
     float ratioimg = 0.0;

    dir = getenv("EXIASAVER1_PMB");
    srand(time(NULL));
    imglist = listrepertory(dir);
    //On sécurise le choix de l'image
     if(argc == 3)
     {
         if(atoi(argv[2]) < imglist->taille)
         {
            file.random = atoi(argv[2]);
         }
         else
         {
             file.random = genrandom(0, imglist->taille);  
         }

     }
     else
     {

        file.random = genrandom(0, imglist->taille);
     }
    
    //Lecture du fichier .pbm pour charger l'image
    //On lit le fichier dans un thread
    if (pthread_create(&thlecture, NULL, (void *)lirepbm, &file)) 
    {
	    perror("pthread_create");
	    
    } 
    //thread qui va detecter l'appui d'une touche 
    if (pthread_create(&thstop, NULL, (void *)stopevent, &flagquit)) 
    {
	    perror("pthread_create");
	    
    } 

do
{
    //Le main attend la fin de la lecture du fichier !
    pthread_join(thlecture, NULL);
    ioctl(0, TIOCGWINSZ, &sterm);

    //Vérification si l'image est carrée ou non
    ratioimg = (float)file.H / file.L;

    if(ratioimg == 1.0)
    {
        //On reproportionne l'image en gardant sa forme carré
        tailleH = 0;
        tailleL = 0;
        tailleH = (sterm.ws_row - (file.H));
        tailleL = (tailleH + file.L);
        
    }
    else
    {
        //On regarde si le rectangle est levé ou couché et on le proportionne comme on veut
        if(file.H > file.L)
        {
            tailleH = sterm.ws_row / 3;
            tailleL = sterm.ws_col / 2;
        }
        else
        {
            tailleH = sterm.ws_row / 2;
            tailleL = sterm.ws_col / 3;
        }

    }


    //Création du tableau virtuel
    Createtabvir(&tabvir, tailleH, tailleL);
    //Rendu du .pbm dans le tableau virtuel
    moteurrendu(&tabvir, &file);

    //Affichage
     afftabvir(&tabvir);
     sleep(1);
}while(flagquit == 0);

    system("clear");
    return 0;
}

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
