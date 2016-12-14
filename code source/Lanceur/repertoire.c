#include "repertoire.h"


int genrandom(int min, int max)
{
   
    return rand()%((max - 1) - min + 1) + min;
}
//Permet d'avoir la liste des images
DIRIMG *listrepertory(char *dir)
{
    //Variable/structure de répertoire
    DIR *directory = NULL;
    struct dirent *fichiernow = NULL;
    //Variable de boucle
    int i = 0;
    //Structure contenant les nom et le nombre de fichier .pbm dans le répertoire
    DIRIMG *imglist = NULL;
    int taille = 0;

    imglist = malloc(sizeof(DIRIMG));//Structure contenant les nom des images
    imglist->taille = 0;

     //On va lire le répertoire
    directory = opendir(dir);//On ouvre le répertoire
    if(directory != NULL)//On véfirie son ouverture
    {

        while ((fichiernow = readdir(directory)) != NULL) 
        {
            if (!strcmp(fichiernow->d_name, ".") || !strcmp(fichiernow->d_name, "..") || !strcmp(fichiernow->d_name, "imagesstat") || !strcmp(fichiernow->d_name, "imagesdyn") || !strcmp(fichiernow->d_name, "imagesinter"))
            {
            } 
            else 
            {
                imglist->taille++;
            }
        }

      //On créer notre tableau qui contiendra l'ensemble des fichier.pbm
      imglist->filelist = malloc(imglist->taille * sizeof(char *));

      //On se repositionnne au début du répertoire
      rewinddir(directory);


    //On remplie notre tableau
     while ((fichiernow = readdir(directory)) != NULL) 
      {
        if (!strcmp(fichiernow->d_name, ".") || !strcmp(fichiernow->d_name, "..") || !strcmp(fichiernow->d_name, "imagesstat") || !strcmp(fichiernow->d_name, "imagesdyn") || !strcmp(fichiernow->d_name, "imagesinter"))
        {
        } 
        else 
        {
            taille = strlen(fichiernow->d_name); 
            imglist->filelist[i] = (char *)malloc(taille * sizeof(char));   
            //La copy de la chaine est nécessaire 
            strcpy(imglist->filelist[i], fichiernow->d_name);
            i++;
        }
      }
      
    }
    else
    {
       // exit(1);
    }
     closedir(directory);//On ferme le répertoire

    return imglist;//On retourne la liste des images

}