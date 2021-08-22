#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
/* Wait on a binary semaphore. Block until the semaphore value is positive, then 
decrement it by 1. */

void error(char *errorInfo)
{
    fprintf(stderr, "%s", errorInfo);
    exit(1);
}

int binary_semaphore_wait(int semid)
{
    struct sembuf operations[1];
    /* Use the first (and only) semaphore. */
    operations[0].sem_num = 0;
    /* Decrement by 1. */
    operations[0].sem_op = -1;
    /* Permit undo’ing. */
    operations[0].sem_flg = SEM_UNDO;
    return semop(semid, operations, 1);
}
/* Post to a binary semaphore: increment its value by 1. 
This returns immediately. */
int binary_semaphore_post(int semid)
{
    struct sembuf operations[1];
    /* Use the first (and only) semaphore. */
    operations[0].sem_num = 0;
    /* Increment by 1. */
    operations[0].sem_op = 1;
    /* Permit undo’ing. */
    operations[0].sem_flg = SEM_UNDO;
    return semop(semid, operations, 1);
}

void initSem(int semid, int numSem, int valor)
{ //iniciar un semaforo

    if (semctl(semid, numSem, SETVAL, valor) < 0)
    {
        perror(NULL);
        error("Error iniciando semaforo");
    }
}

int main()
{
    puts("Sincronizacion con Semaforos ");
    int semaforo;

    //Manera de usar semget http://pubs.opengroup.org/onlinepubs/7908799/xsh/semget.html
    //Creamos un semaforo y damos permisos para compartirlo
    if ((semaforo = semget(IPC_PRIVATE, 1, IPC_CREAT | 0700)) < 0)
    {
        perror(NULL);
        error("Semaforo: semget");
    }

    initSem(semaforo, 0, 1);
    puts("Hay una plaza libre");

    switch (fork())
    {
    case -1:
        error("Error en el fork");

    case 0: /* Hijo */
        binary_semaphore_wait(semaforo);
        puts("Entro el hijo, el padre espera");
        sleep(5);
        puts("El hijo sale");
        binary_semaphore_post(semaforo);
        exit(0);

    default: /* Padre */
        binary_semaphore_wait(semaforo);
        puts("Entro el padre, el hijo espera");
        sleep(5);
        puts("El padre sale");
        binary_semaphore_post(semaforo);
    }

    sleep(20);

    //Liberacion del semaforo
    if ((semctl(semaforo, 0, IPC_RMID)) == -1)
    {
        perror(NULL);
        error("Semaforo borrando");
    }
    return 0;
}