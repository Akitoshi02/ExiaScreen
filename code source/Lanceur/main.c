#include "command.h"


int main(int argc, char *argv[])
{
    //On définie la variable d'environnement
    unsetenv("EXIASAVER_HOME");
    setenv("EXIASAVER_HOME", "/home/akitoshi/Documents/Projet/ExiaScreen/veille", 0);

    unsetenv("EXIASAVER1_PMB");
    setenv("EXIASAVER1_PMB", "/home/akitoshi/Images/imgterm1", 0);

    unsetenv("EXIASAVER2_PMB");
    setenv("EXIASAVER2_PMB", "/home/akitoshi/Images/imgterm2", 0);

    unsetenv("EXIASAVER3_PMB");
    setenv("EXIASAVER3_PMB", "/home/akitoshi/Images/imgterm3", 0);

    //On initialise srand afin de générer un nombre aléatoire
     srand(time(NULL));
    int random = 0;
    //Variable qui contiendra la taille de dir + le nom de l'images choisi
    int taille;
    int i = 0, choix;
    //Contiendra la list des fichier
    DIRIMG *imglist = NULL;
    //Variable qui contient le répertoire de lancement des executable
    char *dir = getenv("EXIASAVER_HOME");
    char *str;
    //Variable du répertoire
    char *totaldir = NULL;
    //Variable contenant des arguments à envoyer aux programmes
    char **arg;
    arg = malloc(10 * sizeof(char *));
    //Variable log
    char *logs = NULL;
    logs = malloc(255 * sizeof(char));

    //Structure de la taille du shell
    struct winsize sterm;
    ioctl(0, TIOCGWINSZ, &sterm);
    

    //On récupère la liste des executables
    imglist = listrepertory(dir);
    //On génère aléatoirement un nombre qui permettra de choisir aléatoriement entre un des trois
    random = genrandom(0, imglist->taille);

    //On créer le chemin total afin d'accèder aux executable
    taille = strlen(dir) + strlen(imglist->filelist[random]) +1;
    totaldir = (char *)malloc(taille * sizeof(char));

    //On créer le chemin total
    sprintf(totaldir, "%s/%s", dir, imglist->filelist[random]);
    //on lance le fond d'écran ou on demande -help ou -stat
    if(argc < 2)
    {
        //PARTIE ALEATOIRE
        //Fond d'écran statique
        if(strcmp(imglist->filelist[random], "termstatic") == 0)
        {
            //On génère les argument envoyé aux fonds d'écran'
            dir = getenv("EXIASAVER1_PMB");
            imglist = listrepertory(dir);
            random = genrandom(0, imglist->taille);
            arg[0] = "./lanceur";
            arg[1] = "termstatic";
            sprintf(arg[2], "%d", random);
            arg[9] = NULL;
            //génération du log
            sprintf(logs, "%s %s", "static - :", imglist->filelist[random]);
    
            setlog(getdate(), logs);
            //lancement
            if(execv(totaldir, arg) == -1)
            {
                perror("execv");
            }
        }
        //Fond d'écran dynamique
        else if(strcmp(imglist->filelist[random], "termdyn") == 0)
        {
            //génération du log
            sprintf(logs, "%s %d", "dynamique - nb seconde :", 1);
            setlog(getdate(), logs);
            //lancement
            if(execv(totaldir, NULL) == -1)
            {
                printf("totadir %s\n", totaldir);
                perror("execv");
            }
        }
         //Fond d'écran interactif
        else if(strcmp(imglist->filelist[random], "terminter") == 0)
        {
            //On génère les argument envoyé aux fonds d'écran'
            arg[0] = "./lanceur";
            arg[1] = "terminter";
            random = genrandom(0, sterm.ws_col);
            sprintf(arg[2], "%d", random);
            random = genrandom(0, sterm.ws_row);
            sprintf(arg[3], "%d", random);
            arg[9] = NULL;
            //génération du log
            sprintf(logs, "%s x : %s y : %s", "interactif - :", arg[2], arg[3]);
            setlog(getdate(), logs);
            //lancement
            if(execv(totaldir, arg) == -1)
            {
                puts("erreur lancement");
            }
        }
    }
    else//Partie choix de l'utilisateur
    {
        if(strcmp(argv[1], "-static") == 0)
        {
             str = getenv("EXIASAVER1_PMB");
            imglist = listrepertory(str);
            if(argc > 2)
            {
                choix = atoi(argv[2]);
            }
            else
            {
                choix = 0;
            }

            if(choix < imglist->taille)
            {
                sprintf(logs, "%s %s", "static - :", imglist->filelist[choix]);
                setlog(getdate(), logs);

                //génération du chemin d'accès
                sprintf(totaldir, "%s/%s", dir, "termstatic");
                //lancement
                if(execv(totaldir, argv) == -1)
                {
                perror("execv");
                }
            }
            else
            {
                puts("erreur choix trop grand");
            }


        }
        if(strcmp(argv[1], "-dyn") == 0)
        {
            if(argc > 2)
            {
                choix = atoi(argv[2]);
                if(choix < 10000)
                {
                    //génération du log
                    sprintf(logs, "%s %s", "dynamique - nb seconde :", argv[2]);
                    setlog(getdate(), logs);
                    //génération du chemin d'accès
                    sprintf(totaldir, "%s/%s", dir, "termdyn");
                    if(execv(totaldir, argv) == -1)
                    {
                        perror("execv");
                    }
                }
                else
                {
                    puts("erreur valeur trop grande");
                }
 
           
            }
            else
            {
                puts("erreur argument");
            }

        }
        if(strcmp(argv[1], "-inter") == 0)
        {
            //génération du log
            sprintf(logs, "%s x : %s y : %s", "interactif - :", argv[2], argv[3]);
            setlog(getdate(), logs);
            //génération du chemin d'accès
            sprintf(totaldir, "%s/%s", dir, "terminter");
            if(execv(totaldir, argv) == -1)
            {
                perror("execv");
            }       
        }  
        if(strcmp(argv[1], "-help") == 0)
        {
           CMDhelp();
        } 
        if(strcmp(argv[1], "-stat") == 0)
        {
           CMDstat();
        } 
    }    
    //On désactive le curseur
    system("setterm -cursor off");

    return 0;
}