#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
    pid_t child_pid;
    /* Crea un proceso hijo. */

    child_pid = fork();
    if (child_pid > 0)
    {
        /* Este es el proceso principal. Duerme un minuto. */
        printf("\n Proceso padre durmiendo \n");
        sleep(60);
    }
    else
    {
        printf("\n Proceso hijo termina. Proceso zombie creado. Verificar con  $ ps -e -o pid,ppid,stat,cmd \n");
        /* Este es el proceso hijo. Sal de inmediato. */
        exit(0);
    }

    return 0;
}