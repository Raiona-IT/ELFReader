#include <stdio.h>
#include "elfhead.h"

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        fprintf(stdout, "[i] Usage: readelf 'filename'\n");
        return 1;
    }

    FILE *file;

    file = fopen(argv[1], "rb");
    if(file == NULL)
    {
        fprintf(stderr, "[!] Could not open file.\n");
        return 2;
    }

    if(check_header(file) != 0)
    {
        fprintf(stderr, "[!] Unsucessful header parsing.\n");
    }

    fclose(file);
    return 0;
}
