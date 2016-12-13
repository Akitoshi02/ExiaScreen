#include "processus.h"
#include "include.h"


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


HEURE getheure(void)
{
    HEURE h;
    time_t sec;
    struct tm instant;

    time(&sec);
    instant =*localtime(&sec);
    char date[128];
    //%i:%M:%S

    strftime(date, 128, "%H%M%S", &instant);

   h.heure[0] = ((int)date[0] - '0');
    h.heure[1] = ((int)date[1] - '0');

    h.minute[0] = ((int)date[2] - '0');
    h.minute[1] = ((int)date[3] - '0');

    h.seconde[0] = ((int)date[4] - '0');
    h.seconde[1] = ((int)date[5] - '0');

    return h;
}