#include "processus.h"

static struct termios ancien, nouveau;


//Ces fonction vont permettre de configurer le terminal afin d'enlever l'affichage des saisies
void initTerm(void);
void resetTerm(void);
char getch_(void);
void *stopevent(int *flagquit);



int main(int argc, char *argv[])
{
    TABVIRTUEL tabvir; //tableau virtuel
    PBM file; //Fichier .pbm
    file.data = NULL;
    int choix = 0;
    int flagquit = 0;
    pthread_t thlecture, thstop;
     struct winsize sterm;


    //On enlève le curseur
    system("setterm -cursor off");

    //On définie la variable d'environnement
    unsetenv("EXIASAVER1_PMB");
    setenv("EXIASAVER1_PMB", "/home/akitoshi/Images/imgterm1", 0);
    
    //Lecture du fichier .pbm pour charger l'image
    //On lit le fichier dans un thread
    if (pthread_create(&thlecture, NULL, (void *)lirepbm, &file)) 
    {
	    puts("pthread_create");
	    
    } 
    //thread qui va detecter l'appui d'une touche 
    if (pthread_create(&thstop, NULL, (void *)stopevent, &flagquit)) 
    {
	    puts("pthread_create");
	    
    } 

do
{
    
    ioctl(0, TIOCGWINSZ, &sterm);
    //Création du tableau virtuel
    Createtabvir(&tabvir, (sterm.ws_row / 2), (sterm.ws_col / 2));


    //Le main attend la fin de la lecture du fichier !
    pthread_join(thlecture, NULL);

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
