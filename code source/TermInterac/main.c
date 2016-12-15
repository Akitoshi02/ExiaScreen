#include "processus.h"

static struct termios ancien, nouveau;


//Ces fonction vont permettre de configurer le terminal afin d'enlever l'affichage des saisies
void initTerm(void);
void resetTerm(void);
char getch_(void);
void *event(char *touche);



int main(int argc, char *argv[])
{
    TABVIRTUEL tabvir, grid; //tableau virtuel
    PBM *file = NULL; //Fichier .pbm
    int choix = 0;
    int flagquit = 0;
    int tailleL = 0, tailleH = 0;
    pthread_t thlecture, thstop;
    struct winsize sterm;
    COORD place;
    //Structure qui récupère la list des images
    DIRIMG *imglist;
    int tailleimg = 0;
    char touch = 0;
    place.X = 0, place.Y = 0;

    POS position;
     float ratio = 0.0;
     float ratioimg = 0.0;
    if(argc >= 2)
    {
        place.X = atoi(argv[2]);
        place.Y = atoi(argv[3]);
    }
      system("setterm -cursor off");
    //Vas permettre de récuperer les fichiers dans un tableau

    imglist = listrepertory(getenv("EXIASAVER3_PMB"));
    file = malloc(imglist->taille * sizeof(PBM));
    tailleimg = imglist->taille;
    free(imglist);

    file->random = 0;
    
    //Lecture du fichier .pbm pour charger l'image
    //On lit le fichier dans un thread
   if (pthread_create(&thlecture, NULL, (void *)lirepbm, file)) 
    {
	    perror("pthread_create");    
    } 
    //thread qui va detecter l'appui d'une touche 
    if (pthread_create(&thstop, NULL, (void *)event, &touch)) 
    {
	    perror("pthread_create");
	    
    } 

    //Création de la grille qui contiendra l'avions
  
    do
    {
        //system("clear");
        //Le main attend la fin de la lecture du fichier !
        pthread_join(thlecture, NULL);
        ioctl(0, TIOCGWINSZ, &sterm);

        //Création du tableau virtuel
        Createtabvir(&tabvir, 6, 6);
         Createtabvir(&grid, sterm.ws_row, sterm.ws_col);
        //Rendu du .pbm dans le tableau virtuel
        position = DROITE;
        switch(touch)
        {
            case 'z':
                place.Y -= 4;
                position = HAUT;
                break;
            case 'q':
                place.X -= 4;
                position = GAUCHE;
                break;
            case 's':
                place.Y += 4;
                position = BAS;
                break;
            case 'd':
                place.X += 4;
                position = DROITE;
                break;
        }
        moteurrendu(&tabvir, file, tailleimg, position);

        placement(&grid, &tabvir, place.X, place.Y);

        //Affichage
        afftabvir(&grid);
        sleep(1);
    }while(touch != 'x');

    system("setterm -cursor on");
    system("reset");
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
void *event(char *touche)
{
    char ch = 0;
    initTerm();//On enlève l'affichage de la saisie'
    while(*touche != 'x')
    {
        ch = getch_();//On récupère si l'user appuis sur une touche'
        if(ch == 'z' || ch == 'q' || ch == 's' || ch == 'd' || ch == 'x')
        {
            *touche = ch;
        }
    }
   pthread_exit(0);  

}
