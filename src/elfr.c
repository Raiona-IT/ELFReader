#include <stdio.h>

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

    if(check_format(file) != 0)
    {
        fprintf(stderr, "[!] File not in ELF format.\n");
        return 3;
    }
    else
    {
        fprintf(stdout, "[+] File is in ELF format.\n");
    }

    fclose(file);
    return 0;
}

int check_format(FILE *file)
{
    unsigned char byte[4];
    int i;

    for(i = 0; i < 4; i++)
    {
        byte[i] = (char) fgetc(file);
    }

    if(byte[0] == 0x7f && byte[1] == 0x45 && byte[2] == 0x4c && byte[3] == 0x46)
    {
        return 0;
    }

    return 1;
}
