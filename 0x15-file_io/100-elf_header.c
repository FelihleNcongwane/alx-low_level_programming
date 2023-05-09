#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

void check_elf(unsigned char *elf_magic);
void print_magic(unsigned char *elf_magic);
void print_class(unsigned char *elf_magic);
void print_data(unsigned char *elf_magic);
void print_version(unsigned char *elf_magic);
void print_osabi(unsigned char *elf_magic);
void print_abi(unsigned char *elf_magic);
void print_type(unsigned int elf_type, unsigned char *elf_magic);
void print_entry(unsigned long int elf_entry, unsigned char *elf_magic);
void close_elf(int file_descriptor);

/**
 * check_elf - Checks if a file is an ELF file.
 * @elf_magic: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file - exit code 98.
 */
void check_elf(unsigned char *elf_magic)
{
	if (!(elf_magic[0] == 0x7f && elf_magic[1] == 'E' && elf_magic[2] == 'L' && elf_magic[3] == 'F'))
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
		exit(98);
	}
}

/**
 * print_magic - Prints the magic numbers of an ELF header.
 * @elf_magic: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Magic numbers are separated by spaces.
 */
void print_magic(unsigned char *elf_magic)
{
	printf(" Magic: ");
	for (int i = 0; i < EI_NIDENT; i++)
		printf("%02x%s", elf_magic[i], i == EI_NIDENT - 1 ? "\n" : " ");
}

/**
 * print_class - Prints the class of an ELF header.
 * @elf_magic: A pointer to an array containing the ELF class.
 */
void print_class(unsigned char *elf_magic)
{
	printf(" Class: ");
	if (elf_magic[EI_CLASS] == ELFCLASSNONE)
		printf("none\n");
	else if (elf_magic[EI_CLASS] == ELFCLASS32)
		printf("ELF32\n");
	else if (elf_magic[EI_CLASS] == ELFCLASS64)
		printf("ELF64\n");
	else
		printf("<unknown: %x>\n", elf_magic[EI_CLASS]);
}

/**
 * print_data - Prints the data of an ELF header.
 * @elf_magic: A pointer to an array containing the ELF class.
 */
void print_data(unsigned char *elf_magic)
{
	printf(" Data: ");
	if (elf_magic[EI_DATA] == ELFDATANONE)
		printf("none\n");
	else if (elf_magic[EI_DATA] == ELFDATA2LSB)
		printf("2's complement, little endian\n");
	else if (elf_magic[EI_DATA] == ELFDATA2MSB)
		printf("2's complement, big endian\n");
	else
		printf("<unknown: %x>\n", elf_magic[EI_DATA]);
}

/**
 * print_version - Prints the version of an ELF header.
 * @elf_magic: A pointer to an array containing the ELF version.
 */
void print_version(unsigned char *elf_magic)
{
	printf(" Version: %d", elf_magic[EI_VERSION]);
	switch (elf_magic[EI_VERSION])
	{
	case EV_NONE:
		printf(" (invalid)\n");
		break;
	case EV_CURRENT:
		printf("\n");
		break;
	default:
		printf(" <unknown: %x>\n", elf_magic[EI_VERSION]);
		break;
	}
}

/**
 * print_osabi - Prints the OS/ABI of an ELF header.
 * @elf_magic: A pointer to an array containing the ELF OS/ABI.
 */
void print_osabi(unsigned char *elf_magic)
{
	printf(" OS/ABI: ");
	switch (elf_magic[EI_OSABI])
	{
	case ELFOSABI_SYSV:
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
		printf("<unknown: %x>\n", elf_magic[EI_OSABI]);
		break;
	}
}

/**
 * print_abi - Prints the ABI version of an ELF header.
 * @elf_magic: A pointer to an array containing the ELF ABI version.
 */
void print_abi(unsigned char *elf_magic)
{
	printf(" ABI Version: %d\n", elf_magic[EI_ABIVERSION]);
}

/**
 * print_type - Prints the type of an ELF header.
 * @elf_type: The ELF type.
 * @elf_magic: A pointer to an array containing the ELF magic numbers.
 */
void print_type(unsigned int elf_type, unsigned char *elf_magic)
{
	if (elf_magic[EI_DATA] == ELFDATA2LSB)
		elf_type = ((elf_type & 0xff) << 8) | ((elf_type >> 8) & 0xff);
	printf(" Type: ");
	switch (elf_type)
	{
	case ET_NONE:
		printf("NONE (Unknown type)\n");
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
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", elf_type);
		break;
	}
}

/**
 * print_entry - Prints the entry point of an ELF header.
 * @elf_entry: The ELF entry point.
 * @elf_magic: A pointer to an array containing the ELF magic numbers.
 */
void print_entry(unsigned long int elf_entry, unsigned char *elf_magic)
{
	if (elf_magic[EI_CLASS] == ELFCLASS32)
		printf(" Entry point address: 0x%x\n", (unsigned int)elf_entry);
	else if (elf_magic[EI_CLASS] == ELFCLASS64)
		printf(" Entry point address: 0x%lx\n", elf_entry);
}

/**
 * close_elf - Closes the file descriptor of an ELF file.
 * @file_descriptor: The file descriptor to close.
 */
void close_elf(int file_descriptor)
{
	if (close(file_descriptor) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close file\n");
		exit(98);
	}
}

/**
 * main - Displays the information contained in the
 * ELF header at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the file is not an ELF File or
 * the function fails - exit code 98.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int o, r;

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_elf(header->e_ident);
	printf("ELF Header:\n");
	print_magic(header->e_ident);
	print_class(header->e_ident);
	print_data(header->e_ident);
	print_version(header->e_ident);
	print_osabi(header->e_ident);
	print_abi(header->e_ident);
	print_type(header->e_type, header->e_ident);
	print_entry(header->e_entry, header->e_ident);

	free(header);
	close_elf(o);
	return (0);
}/* elf */
