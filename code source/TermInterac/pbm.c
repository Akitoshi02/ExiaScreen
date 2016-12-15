#include "pbm.h"
//FOnction lecture de fichier
void *lirepbm(PBM *f)
{
    //Variable de fichier
    FILE *fpbm = NULL;
    //PBM *f = NULL;
    //Variable/structure des répertoires
    DIR *directory = NULL;
    struct dirent *fichiernow = NULL;
    char *dir = NULL;
    dir = getenv("EXIASAVER3_PMB");//On lit la variable d'environnement
    char *totaldir = NULL;
    //Variable de boucle
    int i = 0, y = 0, z = 0, g = 0, t = 0;
    //Variable nombre aléatoire
    int random = 0;
    //Variable tableau contenant le chemin d'accès au .pbm
    int taille = 0;
    //Structure listant les noms d'images
    DIRIMG *imglist = NULL;
    //Variable 'curseur' permettant de récupèrer le caractère lu
    char charnow = 0;
    char temp[2];
    char nbmagique[3];
    
    if(dir == NULL) //Si la variable d'environnement n'existe pas 
    {
        dir = "imgterm3";//On cherche dans le répertoire du dossier de l'executable
    }

    imglist = listrepertory(dir);//On récupère les images du répertoire


    //le fichier contiendra les images des chiffres de l'heure
    //f = malloc(imglist->taille * sizeof(PBM));

    //On lit chaque fichier....
    for(t = 0; t < imglist->taille; t++)
    {
        //On calcule la taille total directory + nom de l'images
        taille = strlen(dir) + strlen(imglist->filelist[t]);

        //On créer le tableau contenant le chemin du .pbm
        totaldir = (char *)malloc(taille * sizeof(char));
        if(totaldir == NULL)//On test si le tableau c'est bien créé 
        {
            puts("ERREUR : création du directory");
            //exit(1);
            //pthread_exit(0);   
         }

        //On fusion "dir" avec l'images choisi du tableau de la liste d'image
        
        sprintf(totaldir, "%s/%s", dir, imglist->filelist[t]);

        //On ouvre l'image choisi aléatoirement
        fpbm = NULL;
        fpbm = fopen((char*)totaldir, "r");
        free(totaldir);


        //lecture fichier
        if(fpbm != NULL)
        {
            //nombre magique
            fscanf(fpbm, "%s", nbmagique);
            //Type si 1 2 3 ... ou :
            fscanf(fpbm, "%s", temp);
            if(temp[1] != ':')
            {
                f[t].type = temp[1] - 48;
            }
            else
            {
                f[t].type = 10;
            }
            

            //On cherche la taille du fichier
            fscanf(fpbm, "%d %d", &f[t].H, &f[t].L);
     
            //On créer notre tableau qui contiendra les données "01 01 01 11 00 etc..."
            f[t].data = malloc(f[t].H * sizeof(char *));//Lignes
     
            for(i = 0; i < f[t].H; i++)
            {
                f[t].data[i] = (char *)malloc(f[t].L * sizeof(char *));//colonnes
            }
            
            //Maintenant on remplie ce tableau 
            for(z = 0; z < f[t].H; z++)
            { 
                for(g = 0; g < f[t].L; g++)
                {
                    fscanf(fpbm, "%c", &charnow);//On lit le caractère (déplace automatiquement le curseur)
                    //On prend en compte que les 1 et les 0 pas d'espace ou caractère retour chariot ou de fin de ligne (10 et 13)
                    if(charnow == '1' || charnow == '0')
                    {
                        f[t].data[z][g] = charnow;//Le caractère une fois vérifier par le if peut être inséré dans le tableau
                    }
                    else
                    {
                        /*Décrémentation car cela permet si par exemple il y a un espace entre 1 et 0 de ne pas le prendre en compte 
                        ainsi on peut lire aussi bien "01" que "0 1"
                        */
                        g--;
                    }        
                }         
            }
            //-------------------------------
            fclose(fpbm);//On a fini avec le fichier donc on le ferme
        }
        else//Si le fichier na pas pu s'ouvrir 
        {
            puts("erreur ! lecture fichier .pbm");
            //exit(2);
            pthread_exit(NULL);  
        }             
    
    }
    pthread_exit(NULL);  
}
//--------------------------------------------

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

     //On va lire le répertoire
    directory = opendir(dir);//On ouvre le répertoire
    if(directory != NULL)//On véfirie son ouverture
    {

        while ((fichiernow = readdir(directory)) != NULL) 
        {
            if (!strcmp(fichiernow->d_name, ".") || !strcmp(fichiernow->d_name, "..") )
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
        if ( !strcmp(fichiernow->d_name, ".") || !strcmp(fichiernow->d_name, "..") )
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
        exit(1);
        puts("erreur lecture directory");
    }
     closedir(directory);//On ferme le répertoire

    return imglist;//On retourne la liste des images

}