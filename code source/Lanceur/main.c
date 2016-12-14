#include "repertoire.h"


int main(int argc, char *argv[])
{
    //On définie la variable d'environnement
    unsetenv("EXIASAVER_HOME");
    setenv("EXIASAVER_HOME", "/home/akitoshi/Documents/Projet/ExiaScreen/veille", 0);
    unsetenv("EXIASAVER1_PMB");
    setenv("EXIASAVER1_PMB", "/home/akitoshi/Images/imgterm1", 0);
    unsetenv("EXIASAVER2_PMB");
    setenv("EXIASAVER2_PMB", "/home/akitoshi/Images/imgterm2", 0);


     srand(time(NULL));
    int random = 0;
    int taille;
    int i = 0;
    DIRIMG *imglist = NULL;
    char *dir = getenv("EXIASAVER_HOME");
    char *totaldir = NULL;
    char **arg;

    arg = malloc(4 * sizeof(char *));

    //on lance le fond d'écran

            imglist = listrepertory(dir);
            random = genrandom(0, imglist->taille);

            taille = strlen(dir) + strlen(imglist->filelist[random]);
            totaldir = (char *)malloc(taille * sizeof(char));

            //On créer le chemin total
            sprintf(totaldir, "%s/%s", dir, imglist->filelist[random]);


    if(argc < 2)
    {
        if(strcmp(imglist->filelist[random], "termstatic") == 0)
        {
            dir = getenv("EXIASAVER1_PMB");
            imglist = listrepertory(dir);
            random = genrandom(0, imglist->taille);
            arg[0] = "./lanceur";
            arg[1] = "termstatic";
            sprintf(arg[2], "%d", random);
            arg[3] = NULL;
            printf("totaldir %s\n", totaldir);
            if(execv(totaldir, arg) == -1)
            {
                perror("execv");
            }
        }
        else if(strcmp(imglist->filelist[random], "termdyn") == 0)
        {
            if(execv(totaldir, NULL) == -1)
            {
                puts("erreur lancement");
            }
        }
        else if(strcmp(imglist->filelist[random], "terminteract") == 0)
        {
        
        }
    }
    else//PAAAAAAAAASSS TOUCHER !!!!!!!!!!!!!!!!!!!!!
    {
        if(strcmp(argv[1], "termstatic") == 0)
        {
            sprintf(totaldir, "%s/%s", dir, "termstatic");
            if(execv(totaldir, argv) == -1)
            {
                perror("execv");
            }

        }
        if(strcmp(argv[1], "termdyn") == 0)
        {
            sprintf(totaldir, "%s/%s", dir, "termdyn");
            if(execv(totaldir, argv) == -1)
            {
                perror("execv");
            }
        }
        if(strcmp(argv[1], "terminteract") == 0)
        {
     
            sprintf(totaldir, "%s/%s", dir, "termstatic");
            if(execv(totaldir, argv) == -1)
            {
                perror("execv");
            }       
        }   
    }
    exit(0);
    
    //On désactive le curseur
    system("setterm -cursor on");

    return 0;
}