#ifndef ELF_HEAD_H
#define ELF_HEAD_H

#include <stdio.h>

int check_header(FILE *file);
int check_elfformat(FILE *file);
int check_32or64(FILE *file);
int check_endianness(FILE *file);
int check_originality(FILE *file);
int check_os(FILE *file);
int check_unusedbytes(FILE *file);

#endif
