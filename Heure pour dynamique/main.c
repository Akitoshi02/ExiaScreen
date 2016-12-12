#include <stdio.h>
#include <time.h>
#include <windows.h>

typedef struct HORAIRE
{
    int nombres[3];
    char format[10];
}H;

int main(void)
{
    H horaire;
    time_t temps;
    struct tm date;
    int n;
    int i;
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
        printf("Heure = %02d\n", horaire.nombres[0]);
        printf("Minutes = %02d\n", horaire.nombres[1]);
        printf("Secondes = %02d\n", horaire.nombres[2]);
        Sleep(1000 * n);
        system("cls");
    }
    return 0;
}
