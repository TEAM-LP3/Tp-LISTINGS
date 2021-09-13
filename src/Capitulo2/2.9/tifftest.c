#include <stdio.h>
#include <tiffio.h>
#include <assert.h>

int main(int argc, char **argv)
{
    assert(argv[1]!=NULL);
    TIFF *tiff;
    tiff = TIFFOpen(argv[1], "r");
    printf("Img.tiff abierta");
    TIFFClose(tiff);
    return 0;
}

/*
Necesario instalar sudo apt-get install libtiff4-dev
*/