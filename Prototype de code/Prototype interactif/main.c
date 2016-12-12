#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
    int frappe;
    int x = 5, y = 5;

    while(1)
    {
        printf("\n");
        frappe = getch();

        switch(frappe)
        {
        case 'z':
            {
                printf("On monte l'avion d'un pixel\n");
                //lecture fichier avion vers le haut
                y += 1;
                printf("Coordonnee = %d:%d", x , y);
                //Emplacement de l'avion
            break;
            }
        case 's':
            {
                printf("on descend l'avion d'un pixel\n");
                //lecture fichier bas de l'avion
                y -= 1;
                printf("Coordonnee = %d:%d", x , y);
                //Emplacement de l'avion
            break;
            }
        case 'd':
            {
                printf("on avance vers la droite l'avion d'un pixel\n");
                //Lecture fichier droite de l'avion
                x += 1;
                printf("Coordonnee = %d:%d", x , y);
                //Emplacement de l'avion
            break;
            }
        case 'q':
            {
                printf("on avance vers la gauche l'avion d'un pixel\n");
                //Lecture fichier gauche de l'avion
                x -= 1;
                printf("Coordonnee = %d:%d", x , y);
                //Emplacement de l'avion
            break;
            }
        }
    }
}
