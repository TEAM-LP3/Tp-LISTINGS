#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#define FILE_LENGTH 0x100
/* Return a uniformly random number in the range [low,high]. */
int random_range(unsigned const low, unsigned const high)
{
    unsigned const range = high - low + 1;
    return low + (int)(((double)range) * rand() / (RAND_MAX + 1.0));
}
int main(int argc, char *const argv[])
{
    int fd;
    void *file_memory;
    /* Seed the random number generator. */
    printf("Creacion de un memory-mapped file\n");
    srand(time(NULL));
    /* Prepare a file large enough to hold an unsigned integer. */
    char *nombre_archivo = NULL;
    
    if (argv[1] == NULL){
        nombre_archivo = malloc(14); /* reservamos memoria */
        nombre_archivo = "archivo_prueba";
        fd = open(nombre_archivo, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    }else{
        fd = open(argv[1], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    }
       
    
    lseek(fd, FILE_LENGTH + 1, SEEK_SET);
    write(fd, "", 1);
    lseek(fd, 0, SEEK_SET);
    /* Create the memory mapping. */
    file_memory = mmap(0, FILE_LENGTH, PROT_WRITE, MAP_SHARED, fd, 0);
    close(fd);
    /* Write a random integer to memory-mapped area. */
    sprintf((char *)file_memory, "%d\n", random_range(-100, 100));
    /* Release the memory (unnecessary because the program exits). */
    munmap(file_memory, FILE_LENGTH);
    printf("Creacion Exitosa. Mirar en directorio actual\n");

    return 0;
}