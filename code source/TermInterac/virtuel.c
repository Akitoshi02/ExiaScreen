#include "virtuel.h"


void Createtabvir(TABVIRTUEL *tabvir, int H, int L)
{
    int i = 0, y = 0;

    //Notre tableau aura H * ligne

    tabvir->H = H;
    tabvir->L = L;

    tabvir->data = malloc(H * sizeof(char *));
    for(i = 0; i < H; i++)
    {
        tabvir->data[i] = (char *)malloc(L * sizeof(char *));

        for(y = 0; y < tabvir->L; y++)
        {
            tabvir->data[i][y] = '0';
        }
    }

}


void *placement(TABVIRTUEL *grid, TABVIRTUEL *tabvir, int x, int y)
{
    struct winsize sterm;
    ioctl(0, TIOCGWINSZ, &sterm);
    char pixelnow = 0;
    int i = 0, z = 0;
    int cx = 0, cy = 0;
    //150 -20
        for(i = 0; i < tabvir->H; i++)
        {

            for(z = 0; z < tabvir->L; z++)
            {  
                pixelnow = tabvir->data[i][z];
 
                    cx = z+x;
                    cy = i+y;
                 
                    while(cx >= grid->L)
                    {
                        cx = cx - grid->L;
                    }
                    while(cx < 0)
                    {
                        cx = cx + grid->L;
                    }
                    while(cy >= grid->H)
                    {
                        cy = cy - grid->H;
                    }
                    while(cy < 0)
                    {
                        cy = cy + grid->H;
                    }   
                    grid->data[cy][cx] = pixelnow;    
            }


        }
}
//Fonction d'affichage
void afftabvir(TABVIRTUEL * tabvir)
{

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
            if(tabvir->data[i][y] == '+')
            {
                printf("+");
            }
            
        }
        printf("\n");
    }
     
    for(i = 0; i < ((sterm.ws_row / 2) - (tabvir->H / 2)); i++)
    {
        printf("\n");       
    }
}

void moteurrendu(TABVIRTUEL *tabvir, PBM *file)
{

    //variable de boucle
    int i = 0, y = 0, z = 0, g = 0, h = 0;
    //variable curseur
    int curseurH = 0, curseurL = 0;
    //variable pixel
    int pixelH = 0, pixelL = 0;
    //variable lecture caractère
    char pixelnow = 0;


      //module de rendu    
    //Permet de calculer la taille d'un pixel
    if(file->L < tabvir->L)
    {

        pixelL = tabvir->L / file->L;       
    }
    else
    {
        pixelL = 1;  
    }
    if (file->H < tabvir->H)
    {
         pixelH = tabvir->H / file->H;
    }
    else
    {      
        pixelH = 1;
    }


    //On rempli le tableau en redimenssionant les pixel du fichier pour le remplir
    //On centre le .pbm au centre du tableau virtuel

     curseurH = ((tabvir->H - (file->H * pixelH))) / 2;
    if(curseurH < 1)
    {
        curseurH = 0;
    }
    curseurL = ((tabvir->L - (file->L * pixelL))) / 2;
    if(curseurL < 1)
    {
        curseurL = 0;
    }
  
    //Puis on place dans le tableau le .pbm
    //On prend en compte deux possibilité si la taille de limage est inférieur ou égale à la taille du tableau virtuel
    //Ou si la taille est supérieur
    if(file->H <= tabvir->H &&  file->L <= tabvir->L )
    {
        for(i = 0; i < file->H; i++)
        {

            for(y = 0; y < file->L; y++)
            {  
                pixelnow = file->data[i][y];

                for(z = 0; z < pixelH; z++)
                {
                
                    for(g = 0; g < pixelL; g++)
                    { 
                        tabvir->data[z + curseurH][g + curseurL] = pixelnow;                 
                    }               
                }
           
                curseurL = curseurL + pixelL;
            }
            curseurL = ((tabvir->L - (file->L * pixelL))) / 2;
            curseurH = curseurH + pixelH;
        }
        curseurH = 0;

    }
    else //partie qui réduit l'image (encore un peu)
    {
       for(i = 0; i < tabvir->H; i++)
        {
            if(i < file->H)//On bloque la réduction de l'image pour évité un dépassement de mémoire
            {
                for(y = 0; y < tabvir->L; y++)
                {  
                    if(y < file->L)//On bloque la réduction de l'image pour évité un dépassement de mémoire
                    {
                        pixelnow = file->data[i][y];

                        for(z = 0; z < pixelH; z++)
                        {
                
                            for(g = 0; g < pixelL; g++)
                            { 
                                tabvir->data[z + curseurH][g + curseurL] = pixelnow;     
                              
                            }               
                        }
                        curseurL = curseurL + pixelL;
                    }
                }
                curseurL = ((tabvir->L - (file->L * pixelL))) / 2;
                curseurH = curseurH + pixelH;
            }
        }
        curseurH = 0;
        
    }
}