#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

sig_atomic_t child_exit_status;
void clean_up_child_process(int signal_number)
{
    /* Limpia el proceso hijo. */
    printf("\n Proceso hijo finalizo. Limpiando proceso zombie.\n");
    int status;
    wait(&status);
    /* Almacene su estado de salida en una variable global. */
    child_exit_status = status;
}
int main()
{
    void catch (int);     /* signal handler */
    void child(void);     /* el hijo llama a esto */
    void parent(int pid); /* El padre llama a esto */
    /* Maneje SIGCHLD llamando a clean_up_child_process. */
    struct sigaction sigchld_action;
    memset(&sigchld_action, 0, sizeof(sigchld_action));
    sigchld_action.sa_handler = &clean_up_child_process;
    sigaction(SIGCHLD, &sigchld_action, NULL);
    /* Ahora hace cosas, incluso bifurca un proceso secundario. */
    /* ... */

    pid_t child_pid;
    /* Crea un proceso hijo. */

    switch (child_pid = fork())
    {
    case 0: /* lo que tiene devuelve al hijo  */
        child();
        break;

    default: /* lo que tiene devuelve un pid al padre */
        parent(child_pid);
        break;

    case -1: /* si algo salio mal */
        perror("fork");
        exit(1);
    }

    return 0;
}

void child(void)
{
    printf("        child: soy el proceso hijo\n");
    sleep(3); /* no hace nada durante 3 segundos */
    printf("        child: Saliendo \n");
    exit(123); /* salio con un código de retorno de 123 */
}

void parent(int pid)
{
    printf("parent: Soy el proceso padre\n");
    sleep(100); /* no hace nada durante cinco segundos */
    printf("parent: proceso hijo salio con valor %d\n", child_exit_status);
    printf("parent: saliendo\n");
}

void catch (int snum)
{
    int pid;
    int status;

    pid = wait(&status);
    printf("parent: proceso hijo salio con valor %d\n", child_exit_status);
}