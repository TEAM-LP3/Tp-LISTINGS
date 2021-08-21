#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
/* Genera un proceso hijo que ejecuta un nuevo programa. PROGRAMA es el nombre
del programa a ejecutar; se buscará la ruta para este programa.
ARG_LIST es una lista terminada en NULL de cadenas de caracteres que se
pasado como la lista de argumentos del programa. Devuelve el ID de proceso de
el proceso engendrado. */
int spawn(char *program, char **arg_list)
{
    pid_t child_pid;
    /* Duplica este proceso */
    child_pid = fork();
    if (child_pid != 0)
        /* Este es el proceso principal*/
        return child_pid;
    else
    {
        /* Ahora ejecuta PROGRAM, buscándolo en la ruta. */
        execvp(program, arg_list);
        /* La función execvp regresa solo si ocurre un error. */
        fprintf(stderr, "an error occurred in execvp\n");
        abort();
    }
}
int main()
{
    /* La lista de argumentos para pasar al comando "ls". */
    char *arg_list[] = {"ls", /* argv[0], el nombre del program */ "-l", "/", NULL /* La lista de argumentos debe terminar con NULL. */};
    /* Genera un proceso hijo que ejecute el comando "ls". Ignora el
        ID de proceso hijo devuelto. */
    spawn("ls", arg_list);
    printf("done with main program\n");
    return 0;
}