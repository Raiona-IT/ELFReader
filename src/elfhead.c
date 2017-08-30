#include "elfhead.h"

int check_header(FILE *file)
{
    int check; //tmp var for appropriate function call manipulation

    if(check_elfformat(file) != 0)
    {
        fprintf(stderr, "[!] File not in ELF format.\n");
        return 1;
    }
    else
    {
        fprintf(stdout, "[+] File is in ELF format.\n");
    }

    check = check_32or64(file);
    if(check == 1)
    {
        fprintf(stdout, "[+] x86 executable.\n");
    }
    else if(check == 2)
    {
	    fprintf(stdout, "[+] x86_64 executable.\n");
    }
    else
    {
        fprintf(stderr, "[!] Invalid header section. \n");
        return 2;
    }

    check = check_endianness(file);
    if(check == 1)
    {
        fprintf(stdout, "[+] little endian.\n");
    }
    else if(check == 2)
    {
	    fprintf(stdout, "[+] big endian.\n");
    }
    else
    {
        fprintf(stderr, "[!] Invalid header section. \n");
        return 2;
    }

    check = check_originality(file);
    if(check == 1)
    {
        fprintf(stdout, "[+] original ELF. \n");
    }
    else
    {
        fprintf(stdout, "[+] Not original ELF file version. \n");
    }

    return 0;
}

int check_elfformat(FILE *file)
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

int check_32or64(FILE *file)
{
    unsigned char byte;
    int i;

    byte = (char) fgetc(file);

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

int check_endianness(FILE *file)
{
    unsigned char byte;
    int i;

    byte = (char) fgetc(file);

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

int check_originality(FILE *file)
{
        unsigned char byte;
        int i;

        byte = (char) fgetc(file);

        if(byte == 0x01)
        {
            return 1;
        }

        return 2;
}
