#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include <elf.h>
#include "main.h"

void display_error(const char *message);
void display_elf_header_info(Elf64_Ehdr *header);


void display_error(const char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(98);
}

void display_elf_header_info(Elf64_Ehdr *header)
{
printf("  Magic:   ");
for (int i = 0; i < EI_NIDENT; i++)
{
printf("%02x ", header->e_ident[i]);
}
printf("\n");
printf("  Class:				%s\n", header->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
printf("  Data:					%s\n", header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
printf("  Version:				%d (current)\n", header->e_ident[EI_VERSION]);
printf("  OS/ABI:				%d\n", header->e_ident[EI_OSABI]);
printf("  ABI Version:				%d\n", header->e_ident[EI_ABIVERSION]);
printf("  Type:					%s\n", header->e_type == ET_REL ? "REL (Relocatable file)" :
							header->e_type == ET_EXEC ? "EXEC (Executable file)" :
							header->e_type == ET_DYN ? "DYN (Shared object file)" :
							header->e_type == ET_CORE ? "CORE (Core file)" : "Unknown");
printf("  Entry point address:			0x%lx\n", (unsigned long)header->e_entry);
}

int main(int argc, char *argv[])
{
if (argc != 2)
{
display_error("Usage: elf_header elf_filename");
}

const char *filename = argv[1];
int fd = open(filename, O_RDONLY);

if (fd == -1)
{
display_error("Error: Unable to open the file");
}

Elf64_Ehdr header;
if (read(fd, &header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
{
display_error("Error: Unable to read ELF header");
}

if (lseek(fd, 0, SEEK_SET) == -1)
{
display_error("Error: Unable to seek to the beginning of the file");
}

if (header.e_ident[EI_MAG0] != ELFMAG0 || header.e_ident[EI_MAG1] != ELFMAG1 ||
header.e_ident[EI_MAG2] != ELFMAG2 || header.e_ident[EI_MAG3] != ELFMAG3)
{
display_error("Error: Not an ELF file");
}

printf("ELF Header:\n");
display_elf_header_info(&header);

close(fd);
return (0);
}
