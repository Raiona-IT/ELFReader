#ifndef ELF_HEAD_H
#define ELF_HEAD_H

#include <stdio.h>

struct elf_header
{
    // Fill the elf header struct in order to save the information
};

int check_header(FILE *file);
int check_format(FILE *file);
int check_32_or_64(FILE *file);

#endif