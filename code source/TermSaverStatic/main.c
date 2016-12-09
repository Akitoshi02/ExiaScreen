
#include "pbm.h"

int main(int argc, char *argv[])
{
    TABVIRTUEL tabvir; //tableau virtuel
    PBM file; //Fichier .pbm
    int pixelL = 0, pixelH = 0;
    int curseurL = 0, curseurH = 0;
    char pixelnow = 0;

    int choix = 0;
    int i = 0, y = 0, z = 0, g = 0, x = 0, a = 0;

    pthread_t thread;


    Createtabvir(&tabvir, 5, 5);
    lirepbm(&file);

    //module de rendu
    for(i = 0; i < tabvir.H; i++)
    {
        for(y = 0; y < tabvir.L; y++)
        {
            tabvir.data[i][y] = '_';
        }
    }
    //Premièrement il faut connaitre la nouvelle taille que prend un pixel 
    pixelL = tabvir.L / file.L;
    pixelH = tabvir.H / file.H;
    printf("taille pixel %d %d\n", pixelH, pixelL);
    z = 0;
    g = 0;
//On mets le tableau à zéro...
    for(i = 0; i < tabvir.H; i++)
    {
        for(y = 0; y < tabvir.L; y++)
        {   
            tabvir.data[i][y] = 'a';
        }
    }

    for(i = 0; i < file.H; i++)
    {
        for(y = 0; y < file.L; y++)
        {
            pixelnow = file.data[i][y];

            for(z = 0; z < pixelH; z++)
            {
                for(g = 0; g < pixelL; g++)
                { 
                   tabvir.data[z + curseurH][g + curseurL] = pixelnow;                
                }               
            }
           
            curseurL = curseurL + pixelL;
        }
        curseurL = 0;
        curseurH = curseurH + pixelH;
    }
    curseurH = 0;

    //-------------------------------------------------------------------------


    /*if (pthread_create(&thread, NULL, (void *)affthread, &tabvir)) {
	perror("pthread_create");
	return EXIT_FAILURE;
    }*/
    afftabvir(&tabvir);


/*while(1)
{
 scanf("%d", &choix);

    if(choix == 1)
    {
        exit(0);
    }
}*/


    
   

    return 0;
}