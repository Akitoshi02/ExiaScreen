#include "processus.h"


pid_t create_process(void)//Permet de créer un processus
{
    pid_t pid;//contiendra le PID du processus fils

    // On fork() tant que l'erreur est EAGAIN 
    do 
    {
        pid = fork();

    }while ((pid == -1) && (errno == EAGAIN));

    // On retourne le PID du processus ainsi créé
    return pid;
}