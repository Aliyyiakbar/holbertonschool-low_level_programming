#include "elf.h"
#include "main.h"

/**
 * close_fd - closes a file descriptor and exits on failure
 * @fd: file descriptor to close
 *
 * Return: void
 */
void close_fd(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(98);
	}
}

/**
 * error - prints an error message and exits with status 98
 * @fd: file descriptor to close or -1
 * @file: filename to print (or NULL)
 * @msg: message format (use %s if file is not NULL)
 *~~
 * Return: void
 */
void error(int fd, const char *file, const char *msg)
{
	if (file != NULL)
	{
		dprintf(STDERR_FILENO, msg, file);
	}
	else
	{
		dprintf(STDERR_FILENO, "%s", msg);
	}

	if (fd != -1)
	{
		close_fd(fd);
	}

	exit(98);
}

/**
 * print_elf - prints required ELF header info (readelf -h style)
 * @e: buffer containing ELF header
 *
 * Return: void
 */
void print_elf(const unsigned char *e)
{
	int i, is_64, is_be;
	unsigned int type;
	unsigned long entry;
	const Elf32_Ehdr *h32;
	const Elf64_Ehdr *h64;
	const char *osabi;
	const char *typestr;

	is_64 = (e[EI_CLASS] == ELFCLASS64);
	is_be = (e[EI_DATA] == ELFDATA2MSB);

	h32 = (const Elf32_Ehdr *)e;
	h64 = (const Elf64_Ehdr *)e;

	type = is_64 ? h64->e_type : h32->e_type;
	entry = is_64 ? (unsigned long)h64->e_entry : (unsigned long)h32->e_entry;

	if (is_be)
	{
		type = ((type >> 8) | (type << 8)) & 0xFFFF;

		if (is_64)
		{
			entry = ((entry & 0x00000000000000FFUL) << 56) |
				((entry & 0x000000000000FF00UL) << 40) |
				((entry & 0x0000000000FF0000UL) << 24) |
				((entry & 0x00000000FF000000UL) << 8) |
				((entry & 0x000000FF00000000UL) >> 8) |
				((entry & 0x0000FF0000000000UL) >> 24) |
				((entry & 0x00FF000000000000UL) >> 40) |
				((entry & 0xFF00000000000000UL) >> 56);
		}
		else
		{
			entry = ((entry & 0x000000FFUL) << 24) |
				((entry & 0x0000FF00UL) << 8) |
				((entry & 0x00FF0000UL) >> 8) |
				((entry & 0xFF000000UL) >> 24);
		}
	}

	printf("ELF Header:\n");

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		if (i == EI_NIDENT - 1)
		{
			printf("%02x\n", e[i]);
		}
		else
		{
			printf("%02x ", e[i]);
		}
	}

	printf("  Class:                             ");
	if (e[EI_CLASS] == ELFCLASS32)
	{
		printf("ELF32\n");
	}
	else if (e[EI_CLASS] == ELFCLASS64)
	{
		printf("ELF64\n");
	}
	else
	{
		printf("none\n");
	}

	printf("  Data:                              ");
	if (e[EI_DATA] == ELFDATA2LSB)
	{
		printf("2's complement, little endian\n");
	}
	else if (e[EI_DATA] == ELFDATA2MSB)
	{
		printf("2's complement, big endian\n");
	}
	else
	{
		printf("none\n");
	}

	printf("  Version:                           ");
	if (e[EI_VERSION] == EV_CURRENT)
	{
		printf("%d (current)\n", e[EI_VERSION]);
	}
	else
	{
		printf("%d\n", e[EI_VERSION]);
	}

	osabi = NULL;
	if (e[EI_OSABI] == ELFOSABI_SYSV)
	{
		osabi = "UNIX - System V";
	}
	else if (e[EI_OSABI] == ELFOSABI_HPUX)
	{
		osabi = "UNIX - HP-UX";
	}
	else if (e[EI_OSABI] == ELFOSABI_NETBSD)
	{
		osabi = "UNIX - NetBSD";
	}
	else if (e[EI_OSABI] == ELFOSABI_LINUX)
	{
		osabi = "UNIX - Linux";
	}
	else if (e[EI_OSABI] == ELFOSABI_SOLARIS)
	{
		osabi = "UNIX - Solaris";
	}
	else if (e[EI_OSABI] == ELFOSABI_AIX)
	{
		osabi = "UNIX - AIX";
	}
	else if (e[EI_OSABI] == ELFOSABI_IRIX)
	{
		osabi = "UNIX - IRIX";
	}
	else if (e[EI_OSABI] == ELFOSABI_FREEBSD)
	{
		osabi = "UNIX - FreeBSD";
	}
	else if (e[EI_OSABI] == ELFOSABI_TRU64)
	{
		osabi = "UNIX - TRU64";
	}
	else if (e[EI_OSABI] == ELFOSABI_OPENBSD)
	{
		osabi = "UNIX - OpenBSD";
	}
	else if (e[EI_OSABI] == ELFOSABI_ARM_AEABI || e[EI_OSABI] == ELFOSABI_ARM)
	{
		osabi = "ARM";
	}
	else if (e[EI_OSABI] == ELFOSABI_STANDALONE)
	{
		osabi = "Standalone App";
	}

	printf("  OS/ABI:                            ");
	if (osabi != NULL)
	{
		printf("%s\n", osabi);
	}
	else
	{
		printf("<unknown: %x>\n", e[EI_OSABI]);
	}

	printf("  ABI Version:                       %d\n", e[EI_ABIVERSION]);

	typestr = NULL;
	if (type == ET_NONE)
	{
		typestr = "NONE (None)";
	}
	else if (type == ET_REL)
	{
		typestr = "REL (Relocatable file)";
	}
	else if (type == ET_EXEC)
	{
		typestr = "EXEC (Executable file)";
	}
	else if (type == ET_DYN)
	{
		typestr = "DYN (Shared object file)";
	}
	else if (type == ET_CORE)
	{
		typestr = "CORE (Core file)";
	}

	printf("  Type:                              ");
	if (typestr != NULL)
	{
		printf("%s\n", typestr);
	}
	else
	{
		printf("<unknown: %x>\n", type);
	}

	printf("  Entry point address:               0x%lx\n", entry);
}

/**
 * main - displays the information contained in the ELF header
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 (Success)
 */
int main(int argc, char *argv[])
{
	int fd;
	ssize_t r;
	unsigned char e[sizeof(Elf64_Ehdr)];

	if (argc != 2)
	{
		error(-1, NULL, "Usage: elf_header elf_filename\n");
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		error(-1, argv[1], "Error: Can't open file %s\n");
	}

	r = read(fd, e, sizeof(e));
	if (r == -1)
	{
		error(fd, argv[1], "Error: Can't read from file %s\n");
	}

	if (r < (ssize_t)EI_NIDENT ||
		e[EI_MAG0] != ELFMAG0 || e[EI_MAG1] != ELFMAG1 ||
		e[EI_MAG2] != ELFMAG2 || e[EI_MAG3] != ELFMAG3)
	{
		error(fd, argv[1], "Error: %s is not an ELF file\n");
	}

	if (e[EI_CLASS] == ELFCLASS32 && r < (ssize_t)sizeof(Elf32_Ehdr))
	{
		error(fd, argv[1], "Error: File %s is too short\n");
	}
	if (e[EI_CLASS] == ELFCLASS64 && r < (ssize_t)sizeof(Elf64_Ehdr))
	{
		error(fd, argv[1], "Error: File %s is too short\n");
	}

	print_elf(e);
	close_fd(fd);

	return (0);
}
