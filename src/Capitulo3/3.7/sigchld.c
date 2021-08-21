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
    /* Clean up the child process. */
    printf("\n Proceso hijo finalizo. Limpiando proceso zombie.\n");
    int status;
    wait(&status);
    /* Store its exit status in a global variable. */
    child_exit_status = status;
}
int main()
{
    void catch (int);     /* signal handler */
    void child(void);     /* the child calls this */
    void parent(int pid); /* the parent calls this */
    /* Handle SIGCHLD by calling clean_up_child_process. */
    struct sigaction sigchld_action;
    memset(&sigchld_action, 0, sizeof(sigchld_action));
    sigchld_action.sa_handler = &clean_up_child_process;
    sigaction(SIGCHLD, &sigchld_action, NULL);
    /* Now do things, including forking a child process. */
    /* ... */

    pid_t child_pid;
    /* Create a child process. */

    switch (child_pid = fork())
    {
    case 0: /* a fork returns 0 to the child */
        child();
        break;

    default: /* a fork returns a pid to the parent */
        parent(child_pid);
        break;

    case -1: /* something went wrong */
        perror("fork");
        exit(1);
    }

    return 0;
}

void child(void)
{
    printf("        child: soy el proceso hijo\n");
    sleep(3); /* do nothing for 3 seconds */
    printf("        child: Saliendo \n");
    exit(123); /* exit with a return code of 123 */
}

void parent(int pid)
{
    printf("parent: Soy el proceso padre\n");
    sleep(100); /* do nothing for five seconds */
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