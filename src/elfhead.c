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
        fprintf(stdout, "[+] Bit format:\t\tx86 executable.\n");
    }
    else if(check == 2)
    {
	    fprintf(stdout, "[+] Bit format:\t\tx86_64 executable.\n");
    }
    else
    {
        fprintf(stderr, "[!] Error:\t\tInvalid header section. \n");
        return 2;
    }

    check = check_endianness(file);
    if(check == 1)
    {
        fprintf(stdout, "[+] Endianess:\t\tLittle endian.\n");
    }
    else if(check == 2)
    {
	    fprintf(stdout, "[+] Endianess:\t\tBig endian.\n");
    }
    else
    {
        fprintf(stderr, "[!] Error:\t\tInvalid header section.\n");
        return 2;
    }

    check = check_originality(file);
    if(check == 1)
    {
        fprintf(stdout, "[+] ELF Version:\tOriginal ELF. \n");
    }
    else
    {
        fprintf(stdout, "[+] ELF Version:\tNot original ELF file version. \n");
    }

    check = check_os(file);
    if(check == 0)
    {
        fprintf(stdout, "[+] Operating System:\tSystem V.\n");
    }
    else if(check == 1)
    {
        fprintf(stdout, "[+] Operating System:\tHP-UX.\n");
    }
    else if(check == 2)
    {
        fprintf(stdout, "[+] Operating System:\tNetBSD.\n");
    }
    else if(check == 3)
    {
        fprintf(stdout, "[+] Operating System:\tLinux.\n");
    }
    else if(check == 4)
    {
        fprintf(stdout, "[+] Operating System:\tGNU Hurd.\n");
    }
    else if(check == 6)
    {
        fprintf(stdout, "[+] Operating System:\tSolaris.\n");
    }
    else if(check == 7)
    {
        fprintf(stdout, "[+] Operating System:\tAIX.\n");
    }
    else if(check == 8)
    {
        fprintf(stdout, "[+] Operating System:\tIRIX.\n");
    }
    else if(check == 9)
    {
        fprintf(stdout, "[+] Operating System:\tFreeBSD.\n");
    }
    else if(check == 10)
    {
        fprintf(stdout, "[+] Operating System:\tTru64.\n");
    }
    else if(check == 11)
    {
        fprintf(stdout, "[+] Operating System:\tNovell Modesto.\n");
    }
    else if(check == 12)
    {
        fprintf(stdout, "[+] Operating System:\tOpenBSD.\n");
    }
    else if(check == 13)
    {
        fprintf(stdout, "[+] Operating System:\tOpenVMS.\n");
    }
    else if(check == 14)
    {
        fprintf(stdout, "[+] Operating System:\tNonStop Kernel.\n");
    }
    else if(check == 15)
    {
        fprintf(stdout, "[+] Operating System:\tAROS.\n");
    }
    else if(check == 16)
    {
        fprintf(stdout, "[+] Operating System:\tFenix OS.\n");
    }
    else if(check == 17)
    {
        fprintf(stdout, "[+] Operating System:\tCloudABI.\n");
    }
    else if(check == 83)
    {
        fprintf(stdout, "[+] Operating System:\tSortix.\n");
    }
    else if(check == 84)
    {
        fprintf(stderr, "[!]Error:\t\tUnrecognised Operating System.\n");
        return 2;
    }

    //this section does not need to be printed actually
    check = check_unusedbytes(file);
    if(check == 0)
    {
        fprintf(stdout, "[+] Unused bytes:\tBytes 0x09 to 0x0F are unused (0x00).\n");
    }
    else
    {
        fprintf(stderr, "[!] Error:\t\tSome bytes that are meant to be unused, are actually used.\n");
    }

    check = check_type(file);
    if(check == 0)
    {
        fprintf(stdout, "[+] ELF Type:\t\tNo file type.\n");
    }
    else if(check == 1)
    {
        fprintf(stdout, "[+] ELF Type:\t\tRelocatable file.\n");
    }
    else if(check == 2)
    {
        fprintf(stdout, "[+] ELF Type:\t\tExecutable file.\n");
    }
    else if(check == 3)
    {
        fprintf(stdout, "[+] ELF Type:\t\tShared object file.\n");
    }
    else if(check == 4)
    {
        fprintf(stdout, "[+] ELF Type:\t\tCore file.\n");
    }
    else
    {
        fprintf(stderr, "[!] Error:\t\tUnrecognised file type.\n");
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

    byte = (char) fgetc(file);

    if(byte == 0x01)
    {
        return 1;
    }

    return 2;
}

int check_os(FILE *file)
{
    unsigned char byte;

    byte = (char) fgetc(file);

    if(byte == 0x00)
    {
        return 0;
    }
    else if(byte == 0x01)
    {
        return 1;
    }
    else if(byte == 0x02)
    {
        return 2;
    }
    else if(byte == 0x03)
    {
        return 3;
    }
    else if(byte == 0x04)
    {
        return 4;
    }
    else if(byte == 0x06)
    {
        return 6;
    }
    else if(byte == 0x07)
    {
        return 7;
    }
    else if(byte == 0x08)
    {
        return 8;
    }
    else if(byte == 0x09)
    {
        return 9;
    }
    else if(byte == 0x0A)
    {
        return 10;
    }
    else if(byte == 0x0B)
    {
        return 11;
    }
    else if(byte == 0x0C)
    {
        return 12;
    }
    else if(byte == 0x0D)
    {
        return 13;
    }
    else if(byte == 0x0E)
    {
        return 14;
    }
    else if(byte == 0x0F)
    {
        return 15;
    }
    else if(byte == 0x10)
    {
        return 16;
    }
    else if(byte == 0x11)
    {
        return 17;
    }
    else if(byte == 0x53)
    {
        return 83;
    }

    return 84;
}

int check_unusedbytes(FILE *file)
{
    unsigned char byte;
    int i;
    int breakpoint = 0; //var used for continous bytes check breakpoint

    for(i = 0; i < 8; i++)
    {
        byte = (char) fgetc(file);
        if(byte != 0x00)
        {
            breakpoint = 1;
        }
    }

    return breakpoint;
}

int check_type(FILE *file)
{
    unsigned char byte[2];//big endian reading. 2nd byte is unused
    int i;

    for(i = 0; i < 2; i++)
    {
        byte[i] = (char) fgetc(file);
    }

    if(byte[0] == 0x00)
    {
        return 0;
    }
    else if(byte[0] == 0x01)
    {
        return 1;
    }
    else if(byte[0] == 0x02)
    {
        return 2;
    }
    else if(byte[0] == 0x03)
    {
        return 3;
    }
    else if(byte[0] == 0x04)
    {
        return 4;
    }

    return 5;
 }
