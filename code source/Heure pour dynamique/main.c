#include <stdio.h>
#include <time.h>
#include <windows.h>

typedef struct HORAIRE
{
    int nombres[3];
    char format[10];
    char heure[2];
    char minute[2];
    char seconde[2];
}H;

int main(void)
{
    H horaire;
    time_t temps;
    struct tm date;
    int n;
    int i;
    int j,k;
    int dizaine;
    int unite;
    printf("Temps d'attente ?\n");
    scanf("%d", &n);

    while(1)
    {
        // On récupère la date et l'heure actuelles.
        time(&temps);
        date=*localtime(&temps);

        // On remplit la chaîne avec le format choisi, puis on l'affiche.
        strftime(horaire.format, 128, "%X\n", &date);
        printf("%s",horaire.format);
        // On attend le nombre de temps defini par l'utilisateur
        temps = strtok(horaire.format, ":");
        i = 0;
        while (temps != NULL)
        {
            horaire.nombres[i] = atoi(temps);
            temps = strtok (NULL, ":");
            i++;
        }
        //printf("Heure = %02d\n", horaire.nombres[0]);
        //printf("Minutes = %02d\n", horaire.nombres[1]);
        //printf("Secondes = %02d\n", horaire.nombres[2]);
        system("cls");

        i = 0;
        for(j = 0; j < 3; j++)
        {
            if(j == 0)
            {
                printf("Heure = %02d\n", horaire.nombres[0]);
            }
            else if(j == 1)
            {
                printf("Minutes = %02d\n", horaire.nombres[1]);
            }
            else
            {
                printf("Secondes = %02d\n", horaire.nombres[2]);
            }
            dizaine = horaire.nombres[j]/10;
            unite = horaire.nombres[j]%10;

            for(k = 0; k < 10; k++)
            {
                if(k == dizaine)
                {
                    printf("Lecture du fichier %d\n", dizaine);
                    switch(j)
                    {
                    case 0:
                    {
                        horaire.heure[0] = dizaine;
                        break;
                    }
                    case 1:
                    {
                        horaire.minute[0] = dizaine;
                        break;
                    }
                    case 2:
                    {
                        horaire.seconde[0] = dizaine;
                    }
                    }
                }
            }
            for(k = 0; k < 10; k++)
            {
                if(k == unite)
                {
                    printf("Lecture du fichier %d\n", unite);
                    switch(j)
                    {
                    case 0:
                    {
                        horaire.heure[1] = unite;
                        break;
                    }
                    case 1:
                    {
                        horaire.minute[1] = unite;
                        break;
                    }
                    case 2:
                    {
                        horaire.seconde[1] = unite;
                    }
                    }
                    printf("\n");
                }

            }
        }
        Sleep(1000 * n);
    }
    return 0;
}
