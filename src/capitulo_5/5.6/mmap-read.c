#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#define FILE_LENGTH 0x100
int main(int argc, char *const argv[])
{
    int fd;
    void *file_memory;
    int integer;
    /* Open the file. */

    if (argv[1] == NULL)
    {
        char *nombre_archivo = NULL;
        nombre_archivo = malloc(14); /* reservamos memoria */
        nombre_archivo = "archivo_prueba";
        fd = open(nombre_archivo, O_RDWR, S_IRUSR | S_IWUSR);
        // fd = open(nombre_archivo, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    }
    else
    {
        fd = open(argv[1], O_RDWR, S_IRUSR | S_IWUSR);
        //fd = open(argv[1], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    }

    /* Create the memory mapping. */
    file_memory = mmap(0, FILE_LENGTH, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    close(fd);
    /* Read the integer, print it out, and double it. */
    printf("\nLeyendo entero del archivo mmap\n");
    sscanf(file_memory, "%d", &integer);
    printf("Valor leido: %d\n", integer);
    sprintf((char *)file_memory, "%d\n", 2 * integer);
    printf("\nGuardando el doble entero del archivo mmap\n");
    /* Release the memory (unnecessary because the program exits). */
    munmap(file_memory, FILE_LENGTH);
    return 0;
}