#include "pbm.h"

void lirepbm(PBM *f)
{
    FILE *fpbm = NULL;

    DIR *directory = NULL;
    struct dirent *fichiernow = NULL;
    int i = 0, y = 0, z = 0, g = 0;
    int number = 0, count = 0, nbchar = 0;
    int random = 0;

    dirimg *imglist = NULL;
    char charnow = 0;
    
    char nbtest[] = "0123456789";//vas permettre de trouver la taille 
    char *dir = "images";
    char *totaldir = NULL;

    char *filelist = NULL;

    imglist = listrepertory(dir);
    //On génère un nombre aléatoire qui permettra de choisir un fichier de façon aléatoire
    srand(time(NULL));
    random =  rand()%((imglist->taille - 1) - 0 + 1) + 0;

    //totaldir contiendra le chemin d'accès au fichier .pbm
    totaldir = malloc((sizeof(dir) + sizeof(imglist->filelist[random])) * sizeof(char));

    //On fusion "images" avec l'images choisi du tableau de la liste d'image
    sprintf(totaldir, "%s/%s", dir, imglist->filelist[random]);

    //On ouvre l'image choisi aléatoirement
    fpbm = fopen(totaldir, "r");

    if(fpbm != NULL)
    {

        //On cherche la taille du fichier

        fseek(fpbm, 4, SEEK_SET);
        fscanf(fpbm, "%d %d", &f->H, &f->L);
        //-----------------------------------------------------------

        f->data = malloc(f->H * sizeof(char *));
        for(i = 0; i < f->H; i++)
        {
            f->data[i] = (char *)malloc(f->L * sizeof(char *));
        }

        /*do 
        {
            charnow = fgetc(fpbm);
            printf("%c", charnow);

        }while(charnow != EOF);*/

        //Maintenant on remplie le tableau 
        for(z = 0; z < f->H; z++)
        { 
            for(g = 0; g < f->L; g++)
            {
                fscanf(fpbm, "%c", &charnow);
                if(charnow == '1' || charnow == '0')
                {
                    f->data[z][g] = charnow;
                }
                else
                {
                    g--;
                }
                
            }   
            
        }
        //-------------------------------
        fclose(fpbm);
    }
    else
    {
        puts("erreur ! lecture fichier .pbm");
    }

}

dirimg *listrepertory(char *dir)
{
    DIR *directory = NULL;
    struct dirent *fichiernow = NULL;
    int i = 0;
    int nbfile = 0;
    dirimg *imglist = NULL;

    imglist = malloc(sizeof(dirimg));//Structure contenant les nom des images

     //On va lire le répertoire
    directory = opendir(dir);
    if(directory != NULL)
    {

      while ((fichiernow = readdir(directory)) != NULL) 
      {
        if (!strcmp(fichiernow->d_name, ".") || !strcmp(fichiernow->d_name, "..") )
        {
        } 
        else 
        {
            nbfile++;
        }
      }

      imglist->taille = nbfile;


      //On créer notre tableau qui contiendra l'ensemble des fichier.pbm
      imglist->filelist = malloc(nbfile * sizeof(char *));
      //On se repositionnne au début du répertoire
    /*closedir(directory);
    directory = opendir(dir);*/
    rewinddir(directory);


    //On remplie notre tableau
     while ((fichiernow = readdir(directory)) != NULL) 
      {
        if ( !strcmp(fichiernow->d_name, ".") || !strcmp(fichiernow->d_name, "..") )
        {
        } 
        else 
        {
            imglist->filelist[i] = fichiernow->d_name; 
            //printf("file_name: \"%s\"\n",filelist[i]);
            i++;
        }
      }
    }
    else
    {
        exit(1);
    }
     closedir(directory);

    /* for(i = 0; i < 4; i++)
     {
         printf("file_name: \"%s\"\n",filelist[i]);
     }*/

    return imglist;

}