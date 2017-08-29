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

    int check = check_32_or_64(file);
    if(check == 1)
    {
        fprintf(stderr, "[!] File is 32 bits.\n");
    }
    else if(check == 2)
    {
	    fprintf(stderr, "[!] File is 64 bits.\n");
    }
    else
    {
        fprintf(stderr, "[!] File unrecognized. \n");
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


int check_32_or_64(FILE *file)
{
    unsigned char byte;
    int i;

    byte = (char) fgetc(file);

    fprintf(stdout, "The 5th byte is: %d \n",byte);

    if(byte == 0x01)
    {
        return 1;
    }
    else if(byte == 0x02)
    {
        return 2;
    }

    return 3;
}
