/*
 * Print the symbol table
 *
 */

#include <err.h>
#include <fcntl.h>
#include <gelf.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <bsd/vis.h>  // canhaz libbsd-dev

typedef void (*elf_object_user) (Elf*);

Elf_Scn* find_symtab_section(Elf *e);

void with_elf_object(char *filename, elf_object_user eu) {
    int fd;
    Elf *e;

    if ((fd = open(filename, O_RDONLY, 0)) < 0)
        err(EXIT_FAILURE, "open \%s\" failed", filename);

    if ((e = elf_begin(fd, ELF_C_READ, NULL)) == NULL)
        errx(EXIT_FAILURE, "elf_begin() failed: %s.", elf_errmsg(-1));

    if (elf_kind(e) != ELF_K_ELF)
        // This part check that ti's an ELF object
        errx(EXIT_FAILURE, "%s is not an ELF object.", filename);

    eu(e);

    (void) elf_end(e);
    (void) close(fd);
}

void use_elf_object(Elf *e) {
    Elf_Scn *scn = find_symtab_section(e);
    GElf_Shdr shdr;
    gelf_getshdr(scn, &shdr);

    GElf_Sym sym;
}

Elf_Scn* find_symtab_section(Elf *e) {
    Elf_Scn *scn;
    GElf_Shdr shdr;

    scn = NULL;
    while ((scn = elf_nextscn(e, scn)) != NULL) {
        if (gelf_getshdr(scn, &shdr) != &shdr)
            errx(EXIT_FAILURE, "getshdr() failed: %s.", elf_errmsg(-1));

        if (shdr.sh_type == SHT_SYMTAB || shdr.sh_type == SHT_DYNSYM)
            return scn;
    }
    return NULL;
}

int
main(int argc, char **argv)
{
    if (argc != 2)
        errx(EXIT_FAILURE, "usage: %s file-name", argv[0]);

    if (elf_version(EV_CURRENT) == EV_NONE)
        errx(EXIT_FAILURE, "ELF library initialization failed: %s", elf_errmsg(-1));

    with_elf_object(argv[1], &use_elf_object);

    exit(EXIT_SUCCESS);
}
