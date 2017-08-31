#ifndef ELF_HEAD_H
#define ELF_HEAD_H

#include <stdio.h>

//===16 bytes - e_ident===
int check_header(FILE *file);
int check_elfformat(FILE *file);
int check_32or64(FILE *file);
int check_endianness(FILE *file);
int check_originality(FILE *file);
int check_os(FILE *file);
int check_unusedbytes(FILE *file);
//===end of e_ident===

int check_type(FILE *file);

#endif
