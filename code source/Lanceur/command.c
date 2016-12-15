#include "command.h"

void CMDhelp()
{
    system("clear");
     FILE *Fhelp = NULL;
    char caractereActuel = 0;
    Fhelp = fopen("/home/akitoshi/Documents/veille/help.txt", "r");
    if(Fhelp != NULL)
    {
        do
        {
            caractereActuel = fgetc(Fhelp); // On lit le caractère
            if(caractereActuel != -1)//On enlève le EOF
            {
                printf("%c", caractereActuel); // On l'affiche
            }
            
        }while (caractereActuel != EOF);
        printf("\n");

        fclose(Fhelp);
    }
    else
    {
        puts("fichier help.txt introuvable !");
    }
}


void CMDstat()
{
    system("clear");
     FILE *Fhelp = NULL;
    char caractereActuel = 0;
    Fhelp = fopen("/home/akitoshi/Documents/veille/stat.txt", "r");
    if(Fhelp != NULL)
    {
        do
        {
            caractereActuel = fgetc(Fhelp); // On lit le caractère
            if(caractereActuel != -1)//On enlève le EOF
            {
                printf("%c", caractereActuel); // On l'affiche
            }
            
        }while (caractereActuel != EOF);
        printf("\n");

        fclose(Fhelp);
    }
    else
    {
        puts("fichier help.txt introuvable !");
    }
}
char *getdate()
{
    char *format = NULL;
    time_t tmp;
    struct tm date;
    format = malloc(255 * sizeof(char));

    //récupération de la date et de l'heure
    time(&tmp);
    date = *localtime(&tmp);

    strftime(format, 255, "[%d/%m/%Y - %H:%M:%S]:", &date);
    
    return format;  
}

void setlog(char *date, char *logs)
{
    FILE *fstat = NULL;
    char *totallog = NULL;
    int taille;

    fstat = fopen("/home/akitoshi/Documents/veille/stat.txt", "a");
    if(fstat != NULL)
    {
    taille = strlen(date) + strlen(logs);
    totallog = (char *)malloc(taille * sizeof(char));
    sprintf(totallog, "%s %s", date, logs);
    fputs(totallog, fstat);
    fputs("\n", fstat);
    fclose(fstat);

    }
    else
    {
        puts("erreur d'ouverture du fichier");
    }
}