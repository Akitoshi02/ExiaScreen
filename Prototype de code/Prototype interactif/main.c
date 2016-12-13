#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
    int frappe;
    int x = 5, y = 5;
    char direction = '0';
    Sleep(5000);

    while(1)
    {
        printf("\n");
        if(kbhit())
        {
            frappe = getch();
            system("cls");

            switch(frappe)
            {
            case 'z':
                {
                    //lecture fichier avion vers le haut
                    y += 1;
                    if(y >= 30)
                    {
                        printf("L'avion a traverser l'ecran\n");
                        y = 0;
                    }
                    else
                        printf("On monte l'avion d'un pixel\n");
                    printf("Coordonnee = %d:%d", x , y);
                    direction = 'h';
                    //Emplacement de l'avion
                break;
                }
            case 's':
                {
                    //lecture fichier bas de l'avion
                    y -= 1;
                    if(y <= 0)
                    {
                        printf("L'avion a traverser l'ecran\n");
                        y = 30;
                    }
                    else
                        printf("on descend l'avion d'un pixel\n");
                    printf("Coordonnee = %d:%d", x , y);
                    direction = 'b';
                    //Emplacement de l'avion
                break;
                }
            case 'd':
                {
                    //Lecture fichier droite de l'avion
                    x += 1;
                    if(x >= 30)
                    {
                        printf("L'avion a traverser l'ecran\n");
                        x = 0;
                    }
                    else
                        printf("on avance vers la droite l'avion d'un pixel\n");
                    printf("Coordonnee = %d:%d", x , y);
                    direction = 'd';
                    //Emplacement de l'avion
                break;
                }
            case 'q':
                {
                    //Lecture fichier gauche de l'avion
                    x -= 1;
                    if(x <= 0)
                    {
                        printf("L'avion a traverser l'ecran\n");
                        x = 30;
                    }
                    else
                        printf("on avance vers la gauche l'avion d'un pixel\n");
                    printf("Coordonnee = %d:%d", x , y);
                    direction = 'g';
                    //Emplacement de l'avion
                break;
                }
            }
        }
        else
        {
        system("cls");
        printf("L'avion est en : %d:%d \n", x,y);
        printf("Mais il avance toujours, donc il change de coordonnees\n");
        switch(direction)
        {
        case 'h':
            {
                y += 1;
                printf("Il va vers le haut\n");
                if(y >= 30)
                    {
                        printf("L'avion a traverser l'ecran\n");
                        y = 0;
                    }
                    else
                        printf("On monte l'avion d'un pixel\n");
                break;
            }
        case 'b':
            {
                y -= 1;
                printf("Il va vers le bas\n");
                    if(y <= 0)
                    {
                        printf("L'avion a traverser l'ecran\n");
                        y = 30;
                    }
                    else
                        printf("on descend l'avion d'un pixel\n");
                break;
            }
        case 'd':
            {
                x += 1;
                printf("Il va vers la droite\n");
                    if(x >= 30)
                    {
                        printf("L'avion a traverser l'ecran\n");
                        x = 0;
                    }
                    else
                        printf("on avance vers la droite l'avion d'un pixel\n");
                break;
            }
        case 'g':
            {
                x -= 1;
                printf("Il va vers la gauche\n");
                    if(x <= 0)
                    {
                        printf("L'avion a traverser l'ecran\n");
                        x = 30;
                    }
                    else
                        printf("on avance vers la gauche l'avion d'un pixel\n");
                break;
            }
        }
        printf("Coordonnee = %d:%d", x , y);
        }
        Sleep(2000);
    }
}
