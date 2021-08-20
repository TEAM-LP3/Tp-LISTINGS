#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
/* We must defin#include <stdlib.h>e union semun ourselves. */
union semun {
    int val;
    struct semid_ds *buf;
    unsigned short int *array;
    struct seminfo *__buf;
};

void error(char *errorInfo)
{
    fprintf(stderr, "%s", errorInfo);
    exit(1);
}
/* Obtain a binary semaphore’s ID, allocating if necessary. */
int binary_semaphore_allocation(key_t key, int sem_flags)
{
    return semget(key, 1, sem_flags);
}
/* Deallocate a binary semaphore. All users must have finished their
use. Returns -1 on failure. */
int binary_semaphore_deallocate(int semid)
{
    union semun ignored_argument;
    return semctl(semid, 1, IPC_RMID, ignored_argument);
}

void doSignal(int semid, int numSem)
{
    struct sembuf sops; //Signal
    sops.sem_num = numSem;
    sops.sem_op = 1;
    sops.sem_flg = 0;

    if (semop(semid, &sops, 1) == -1)
    {
        perror(NULL);
        error("Error al hacer Signal");
    }
}

void doWait(int semid, int numSem)
{
    struct sembuf sops;
    sops.sem_num = numSem; /* Sobre el primero, ... */
    sops.sem_op = -1;      /* ... un wait (resto 1) */
    sops.sem_flg = 0;

    if (semop(semid, &sops, 1) == -1)
    {
        perror(NULL);
        error("Error al hacer el Wait");
    }
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
    if ((semaforo = binary_semaphore_allocation(IPC_PRIVATE, IPC_CREAT | 0700)) < 0)
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
        doWait(semaforo, 0);
        puts("Entro el hijo, el padre espera");
        sleep(5);
        puts("El hijo sale");
        doSignal(semaforo, 0);
        exit(0);

    default: /* Padre */
        doWait(semaforo, 0);
        puts("Entro el padre, el hijo espera");
        sleep(5);
        puts("El padre sale");
        doSignal(semaforo, 0);
    }

    sleep(20);

    //Liberacion del semaforo
    if ((binary_semaphore_deallocate(semaforo)) == -1)
    {
        perror(NULL);
        error("Semaforo borrando");
    }
    return 0;
}