#include <stdio.h>
#include <stdlib.h>
#include <elf.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void check_elf(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void close_elf(int elf);

/**
 * check_elf - Test whether a file is an ELF file
 * @e_ident: an address to an array having an ELF magic numbers
 */
void check_elf(unsigned char *e_ident)
{
	int pos;

	for (pos = 0; pos < 4; pos++)
	{
		if (e_ident[pos] != 127 && e_ident[pos] != 'E' &&
				e_ident[pos] != 'L' && e_ident[pos] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_magic - prints magic values of ELF Header
 * @e_ident: Pointer to array containing ELF MAGIC VALUES
 */
void print_magic(unsigned char *e_ident)
{
      int posit;

      printf(" Magic: ");
      for (posit = 0; posit < EI_NIDENT; posit++)
      {
        printf("%02x", e_ident[posit]);
        if (posit == EI_NIDENT - 1)
                printf("\n");
        else
                printf(" ");
      }
}

/**
 * print_class - Print a class of ELF Header
 * @e_ident: Pointer to array having ELF CLASS
 */
void print_class(unsigned char *e_ident)
{
        printf(" Class: ");
        switch (e_ident[EI_CLASS])
        {
                case ELFCLASSNONE:
                        printf("None\n");
                        break;
                case ELFCLASS32:
                        printf("ELF32\n");
                        break;
                case ELFCLASS64:
                        printf("ELF64\n");
                        break;
                default:
                        printf("<unknown: %x>\n", e_ident[EI_CLASS]);
        }
}

/**
 * print_data - Displays the content of ELF header
 * @e_ident: Pointer to arrray having ELF type
 */
void print_data(unsigned char *e_ident)
{
        printf(" Data: ");

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
                        printf("<unknown: %x>\n", e_ident[EI_CLASS]);
        }
}

/**
  * print_version - Print version of ELF header
  * @e_ident: An ELF version pointer
  */
void print_version(unsigned char *e_ident)
{  
          printf(" Version: %d", e_ident[EI_VERSION]);
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
 * print_osabi - display OS/ABI of ELF HEADER
 * @e_ident: An address of an array having the ELF version
 */
void print_osabi(unsigned char *e_ident)
{
	printf(" OS/ABI: ");
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
			printf("Standalone App\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * print_abi - print ELF ABI version
 * @e_ident: Pointer to array of ELF ABI VERSIOIN
 */
void print_abi(unsigned char *e_ident)
{
        printf(" ABI VERSION: %d\n", e_ident[EI_ABIVERSION]);
}

/**
 * print_type - Display the ELF HEADER type
 * @e_type: ELF HAEDER TYPE
 * @e_ident: Address of an array having ELF type
 */
void print_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;
	printf(" Type: ");
	switch (e_type)
	{
		case ET_NONE:
			printf("NONE (none)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core File)\n");
			break;
		default:
			printf("<unknown: %x>\n", e_type);
	}
}

/**
 * print_entry - Prints a starting point of ELF header
 * @e_entry: A pointer to the ELF entry point
 * @e_ident: An address of an array having ELF class
 */
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf(" Entry point address: ");
	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0XFF00FF00) | ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}
	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);
	else
		printf("%#lx\n", e_entry);
}

/**
 * close_elf - A function that closes an ELF File
 * @elf: File description of the ELF File
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - Prints information as in the ELF Header
 * at the beginning of an ELF File
 * @argc: Arg counter
 * @argv: Arg vector
 * Return: 0 (Always on Success)
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *head;
	int a, b;

	a = open(argv[1], O_RDONLY);
	if (a == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	head = malloc(sizeof(Elf64_Ehdr));
	if (head == NULL)
	{
		close_elf(a);
		dprintf(STDERR_FILENO, "Error: can't read file %s\n", argv[1]);
		exit(98);
	}
	b = read(a, head, sizeof(Elf64_Ehdr));
	if (b == -1)
	{
		free(head);
		close_elf(a);
		dprintf(STDERR_FILENO, "Error: %s: no such file\n", argv[1]);
		exit(98);
	}
	check_elf(head->e_ident);
	printf("ELF Heaer:\n");
	print_magic(head->e_ident);
	print_class(head->e_ident);
	print_data(head->e_ident);
	print_version(head->e_ident);
	print_osabi(head->e_ident);
	print_abi(head->e_ident);
	print_type(head->e_type, head->e_ident);
	print_entry(head->e_entry, head->e_ident);
	free(head);
	close_elf(a);
	return (0);
}
