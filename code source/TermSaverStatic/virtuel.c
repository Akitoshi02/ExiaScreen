#include "virtuel.h"


void Createtabvir(TABVIRTUEL *tabvir, int H, int L)
{
    int i = 0;

    //Notre tableau aura H * ligne

    tabvir->H = H;
    tabvir->L = L;

    tabvir->data = malloc(H * sizeof(char *));
    for(i = 0; i < H; i++)
    {
        tabvir->data[i] = (char *)malloc(L * sizeof(char *));
    }
}



//Fonction d'affichage
void afftabvir(TABVIRTUEL * tabvir)
{
   system("clear");
    struct winsize sterm;
    ioctl(0, TIOCGWINSZ, &sterm);
    int i = 0, y = 0, z = 0;

    //On mets au milieu de la hauteur
    for(i = 0; i < ((sterm.ws_row / 2) - (tabvir->H / 2)); i++)
    {
        printf("\n");       
    }

    //On écrit le tableau 
    for(i = 0; i < tabvir->H; i++)
    {
        //On mets au millieu de la colonne
        for(z = 0; z < ((sterm.ws_col / 2) - (tabvir->L / 2)); z++)
        {
            printf(" ");
        }
        for(y = 0; y < tabvir->L; y++)
        {
            if(tabvir->data[i][y] == '1')
            {
                printf("█");
                //█
            }
            if(tabvir->data[i][y] == '0')
            {
                printf(" ");
            }
            
        }
        printf("\n");
    }
    for(i = 0; i < ((sterm.ws_row / 2) - (tabvir->H / 2)); i++)
    {
        printf("\n");       
    }
}

void *affthread(TABVIRTUEL * tabvir)
{
   
    while(1)
    {
        afftabvir(tabvir);
        sleep(1);
    }
    pthread_exit(0);
    
}