#ifndef TYPES_H
#define TYPES_H

#define     unsigned char       ubyte_t
#define     unsigned int        uint_t
#define     unsigned short int  uword_t

#define     ELF_FORM    1
#define     ELF_32      0
#define     ELF_64      1
#define     ELF_ORG     1
#define     END_BIG     0
#define     END_LTL     1


struct elf_header
{
    ubyte_t elf_format       : 1;
    ubyte_t elf_format_bit   : 1;
    ubyte_t elf_endianess    : 1;
    ubyte_t elf_version      : 1;
    ubyte_t elf_os           : 5;
    ubyte_t elf_abi             ;
    ubyte_t elf_pad             ;
    ubyte_t elf_type         : 2;
    ubyte_t elf_arch            ;
    ubyte_t elf_ver          : 1;
    uint_t *elf_entry           ;
    uint_t *elf_hdr_off         ;
    uint_t *elf_sct_off         ;
    uint_t elf_flags            ;
    uword_t elf_hdr_size        ;
    uword_t elf_hdrt_entry_size ;
    uword_t elf_hdrt_entries    ;
    uword_t elf_sct_entry_size  ;
    uword_t elf_sct_entries     ;
    uword_t elf_sct_index       ;
};

typedef struct elf_header elf_hdr;

#endif
