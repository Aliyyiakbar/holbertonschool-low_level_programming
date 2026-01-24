#include "main.h"
#include <elf.h>

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
 *
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
 * print_lines - prints ELF header lines (already parsed/normalized)
 * @e: e_ident
 * @type: normalized type (host-endian)
 * @entry: normalized entry (host-endian)
 *
 * Return: void
 */
void print_lines(const unsigned char *e, unsigned int type, unsigned long entry)
{
	int i;
	const char *osabi, *typestr;

	struct map_s
	{
		unsigned int v;
		const char *s;
	};

	const struct map_s os_map[] = {
		{ELFOSABI_SYSV, "UNIX - System V"},
		{ELFOSABI_HPUX, "UNIX - HP-UX"},
		{ELFOSABI_NETBSD, "UNIX - NetBSD"},
		{ELFOSABI_LINUX, "UNIX - Linux"},
		{ELFOSABI_SOLARIS, "UNIX - Solaris"},
		{ELFOSABI_AIX, "UNIX - AIX"},
		{ELFOSABI_IRIX, "UNIX - IRIX"},
		{ELFOSABI_FREEBSD, "UNIX - FreeBSD"},
		{ELFOSABI_TRU64, "UNIX - TRU64"},
		{ELFOSABI_OPENBSD, "UNIX - OpenBSD"},
		{ELFOSABI_ARM_AEABI, "ARM"},
		{ELFOSABI_ARM, "ARM"},
		{ELFOSABI_STANDALONE, "Standalone App"}
	};

	const struct map_s t_map[] = {
		{ET_NONE, "NONE (None)"},
		{ET_REL, "REL (Relocatable file)"},
		{ET_EXEC, "EXEC (Executable file)"},
		{ET_DYN, "DYN (Shared object file)"},
		{ET_CORE, "CORE (Core file)"}
	};

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
	for (i = 0; i < (int)(sizeof(os_map) / sizeof(os_map[0])); i++)
	{
		if (os_map[i].v == (unsigned int)e[EI_OSABI])
		{
			osabi = os_map[i].s;
		}
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
	for (i = 0; i < (int)(sizeof(t_map) / sizeof(t_map[0])); i++)
	{
		if (t_map[i].v == type)
		{
			typestr = t_map[i].s;
		}
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
 * print_elf - parses header fields, normalizes endianness, prints
 * @e: buffer containing ELF header
 *
 * Return: void
 */
void print_elf(const unsigned char *e)
{
	int is_64, is_be;
	unsigned int type;
	unsigned long entry;
	const Elf32_Ehdr *h32;
	const Elf64_Ehdr *h64;

	is_64 = (e[EI_CLASS] == ELFCLASS64);
	is_be = (e[EI_DATA] == ELFDATA2MSB);

	h32 = (const Elf32_Ehdr *)e;
	h64 = (const Elf64_Ehdr *)e;

	type = is_64 ? (unsigned int)h64->e_type : (unsigned int)h32->e_type;
	entry = is_64 ? (unsigned long)h64->e_entry : (unsigned long)h32->e_entry;

	if (is_be)
	{
		type = ((type & 0x00FF) << 8) | ((type & 0xFF00) >> 8);

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

	print_lines(e, type, entry);
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
