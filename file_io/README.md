# Holberton School – File I/O

This directory contains my C solutions for the **Holberton School – File I/O** project.
The goal is to learn how to work with files using **file descriptors** and the POSIX system calls:
`open`, `read`, `write`, and `close`.

## Requirements

- OS: Ubuntu 20.04 LTS
- Compiler: gcc
- Flags: -Wall -Werror -Wextra -pedantic -std=gnu89
- Style: Betty
- No global variables
- Max 5 functions per file
- Allowed C standard library functions: malloc, free, exit
- Allowed syscalls: read, write, open, close
- You may use _putchar (do not push _putchar.c — the checker provides it)
- All files end with a new line
- Header: main.h (include-guarded, contains all prototypes + _putchar)

## Tasks

- 0. Tread lightly, she is near — read a text file and print it to STDOUT
- 1. Under the snow — create a file (with permissions) and write text into it
- 2. Speak gently, she can hear — append text at the end of an existing file
- 3. cp — copy the contents of one file into another (like the cp command)
- 4. elf (Advanced) — read and display information from an ELF header

## Compilation

Example (compile a function task with its test main):

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 0-main.c 0-read_textfile.c -o 0-read
./0-read filename
```

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 1-main.c 1-create_file.c -o 1-create
./1-create filename "text to write"
```

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 2-main.c 2-append_text_to_file.c -o 2-append
./2-append filename "text to append"
```

Example (program tasks):

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 3-cp.c -o cp
./cp file_from file_to
```

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 100-elf_header.c -o elf_header
./elf_header elf_filename
```

## Author

Aliyyiakbar Shirinli
