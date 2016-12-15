#include "virtuel.h"

void affrefresh(int temps, int largeur)
{
    int i = 0;
    char phrase[] = "L'horloge s'actualisera";
    int mid = (largeur - strlen(phrase)) / 2;
    for(i = 0; i < mid; i++)
    {
        printf(" ");
    }
    printf("%s.", phrase);
    i = 0;
    while(i != temps)
    {
        printf(".");
        i++;

    }
    fflush(stdout);

}
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
    }

    //On nettoie le tableau
    for(i = 0; i < tabvir->H; i++)
    {
        for(y = 0; y < tabvir->L; y++)
        {
            tabvir->data[i][y] = '0';
        }
    }
}



//Fonction d'affichage
void afftabvir(TABVIRTUEL * tabvir)
{
   //system("clear");
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

//Fonction permettant de gérer l'affichage sur un thread différent
void *affthread(TABVIRTUEL * tabvir)
{  
    while(1)
    {
        afftabvir(tabvir);
        sleep(1);
    }
    pthread_exit(0);    
}

void moteurrendu(TABVIRTUEL *tabvir, PBM *file, int tailleimg, HEURE h)
{
    //variable de boucle
    int i = 0, y = 0, z = 0, g = 0, t = 0, x = 0;
    //variable curseur
  
    int curseurH = 0, curseurL = 0, curseur = 0;

    //variable pixel
    int pixelH = 0, pixelL = 0;
    int mapage[10];
    //variable lecture caractère
    char pixelnow = 0;
    //Structure de ficher
    PBM *f;
    PBM fnow;
    f = malloc(tailleimg * sizeof(PBM));
    

    //On tri le tableau avec n passage (tri à bulle....)
    for(y = 0; y < tailleimg; y++)
    {
        for(i = 0; i < tailleimg-1; i++)
        {
            if(file[i].type > file[i+1].type)
            {
                f[i] = file[i];
                file[i] = file[i+1];
                file[i+1] = f[i];
            }  
        }
    }

    free(f);
    f = NULL;

//Remplisage du tableau
  for(t = 0; t < 8; t++)
  {
    
      //On choisi quel fichier lire pour afficher l'heure
      if(t == 2 || t == 5)
      {
          fnow = file[10];
      }
      if(t == 0)
      {
          fnow = file[h.heure[0]];
      }
      if(t == 1)
      {
         fnow = file[h.heure[1]];  
      }
      if(t == 3)
      {
         fnow = file[h.minute[0]];   
      }
      if(t == 4)
      {
         fnow = file[h.minute[1]];   
      }
      if(t == 6)
      {
         fnow = file[h.seconde[0]];   
      }
      if(t == 7)
      {
         fnow = file[h.seconde[1]];   
      }  
            
    //Permet de calculer la taille d'un pixel
    if(fnow.L < tabvir->L)
    {

        pixelL = (tabvir->L / 8) / fnow.L;       
    }
    else
    {
        pixelL = 1;  
    }   
    if (fnow.H < tabvir->H)
    {
         pixelH = tabvir->H / fnow.H;
    }
    else
    {      
        pixelH = 1;
    }

    //On rempli le tableau en redimenssionant les pixel du fichier pour le remplir
    //On centre le .pbm au centre du tableau virtuel

     curseurH = ((tabvir->H - (fnow.H * pixelH))) / 2;
    if(curseurH < 1)
    {
        curseurH = 0;
    }
    curseurL = 1;
    
    //Puis on place dans le tableau le .pbm
    //On prend en compte deux possibilité si la taille de limage est inférieur ou égale à la taille du tableau virtuel
    //Ou si la taille est supérieur

    if(file->H <= tabvir->H && fnow.L <= (tabvir->L / 8) )
    {
        for(i = 0; i < fnow.H; i++)
        {

            for(y = 0; y < fnow.L; y++)
            {  
                pixelnow = fnow.data[i][y];

                for(z = 0; z < pixelH; z++)
                {
                
                    for(g = 0; g < pixelL; g++)
                    { 

                        tabvir->data[z + curseurH][g + curseurL + curseur] = pixelnow;                 
                    }           
                }
           
                curseurL = curseurL + pixelL;
            }
            
             curseurL = 1;
            curseurH = curseurH + pixelH;
        }
        curseurH = 0;
      

    }

      //On déplace la saisie pour écrire chaque chiffre
        curseur += (tabvir->L / 8);
  }
}