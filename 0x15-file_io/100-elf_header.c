#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <elf.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

/**
 * check_elf - Checks for ELF file
 * @e_ident: Ptr to array having the ELF num
 */
void check_elf(unsigned char *e_ident)
{
	int idx;

	for (idx = 0; idx < 4; idx++)
	{
		if (e_ident[idx] != 127 &&
			e_ident[idx] != 'E' &&
			e_ident[idx] != 'L' &&
			e_ident[idx] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: NOT an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_magic - Prints the ELF's MAGIC num
 * @e_ident: Ptr to Array of ELF num
 */
void print_magic(unsigned char *e_ident)
{
	int i;

	printf(" Magic: ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", e_ident[i]);
		if (i == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_class - Prints ELF HEADER CLASS
 * @e_ident: Ptr to Arr of Elf header
 */
void print_class(unsigned char *e_ident)
{
	printf(" Class:          ");
	switch (e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unkwown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_data - Prints ELF Header Data
 * @e_ident: Ptr to Arr of ELF data
 */
void print_data(unsigned char *e_ident)
{
	printf(" Data:           ");
	switch (e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_DATA]);
	}
}

/**
 * print_version: Prints ELF Header Version
 * @e_ident: Ptr to Arr of ELF Version
 */
void print_version(unsigned char *e_ident)
{
	printf(" Version:                 %d",
			e_ident[EI_VERSION]);
	switch (e_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * print_osabi - Prints ELF Header OS/ABI
 * @e_ident: Ptr to arr of ELF VERSION
 */
void print_osabi(unsigned char *e_ident)
{
	printf(" OS/ABI:              ");
	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * print_abi - Prints ELF Header ABI
 * @e_ident: Ptr to array having ELF class
 */
void print_abi(unsigned char *e_ident)
{
	printf("  ABI Version:            %d\n",
			e_ident[EI_ABIVERSION]);
}

/**
 * print_type - Prints the ELF Header Type
 * @e_ident: Ptr to Arr of ELF Header TYPE
 */
void print_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;
	printf("  Type:                        ");
	switch(e_type)
	{
	case ET_NONE:
		printf("NONE (none)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared Object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * print_entry - Prints the addr of Elf Entry Point
 * @e_ident: Ptr to arr containing ELF class
 */
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("Entry Point Address:");
	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}
	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);
	else
		printf("%#lx\n", e_entry);
}

/**
 * close_elf - Close a file
 * @elf: Elf File to be close
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close file %d", elf);
		exit(98);
	}
}

/**
 * main - displays info in the ELF Header File
 * @argc: Arg Counter
 * @argv: Arg Vector
 * Return: 0 (Always)
 */
int main(int __attribute__((__unused__))argc, char *argv[])
{
	Elf64_Ehdr *hdr;
	int op, r;

	op = open(argv[1], O_RDONLY);
	if (op == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	hdr = malloc(sizeof(Elf64_Ehdr));
	if (hdr == NULL)
	{
		close_elf(op);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(op, hdr, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(hdr);
		close_elf(op);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}
	check_elf(hdr->e_ident);
	printf("Elf Header\n");
	print_magic(hdr->e_ident);
	print_class(hdr->e_ident);
	print_data(hdr->e_ident);
	print_version(hdr->e_ident);
	print_osabi(hdr->e_ident);
	print_abi(hdr->e_ident);
	print_type(hdr->e_type, hdr->e_ident);
	print_entry(hdr->e_type, hdr->e_ident);
	free(hdr);
	close_elf(op);
	return (0);
}
