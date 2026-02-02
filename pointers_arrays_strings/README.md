# C - Pointers, arrays and strings

This directory contains my solutions for Holberton School C projects related to
**pointers, arrays, and strings**.

The main focus is learning how memory is handled in C and how to write common
string/array utilities without using the standard library printing functions.

## Requirements

- OS: Ubuntu 20.04 LTS
- Compiler: `gcc`
- Flags: `-Wall -Werror -Wextra -pedantic -std=gnu89`
- Style: Betty
- No global variables
- No more than 5 functions per file
- Standard library printing functions are forbidden (`printf`, `puts`, etc.)
- `_putchar` is allowed
- Header file: `main.h` (contains all prototypes)

## What’s inside

This folder includes implementations of common utilities typically found in the C
standard library, plus extra practice tasks.

### Pointer / basic function practice

- `0-reset_to_98.c` — updates an integer through a pointer
- `1-swap.c` — swaps two integers
- `2-strlen.c` — returns the length of a string
- `3-puts.c` — prints a string using `_putchar`
- `4-print_rev.c` — prints a string in reverse
- `5-rev_string.c` — reverses a string in place
- `6-puts2.c` — prints every other character of a string
- `7-puts_half.c` — prints the second half of a string
- `8-print_array.c` — prints `n` elements of an integer array
- `9-strcpy.c` — copies a string

### String manipulation

- `0-strcat.c` — concatenates two strings
- `1-strncat.c` — concatenates with a byte limit
- `2-strncpy.c` — copies with a byte limit
- `3-strcmp.c` — compares two strings
- `5-string_toupper.c` — converts lowercase letters to uppercase
- `6-cap_string.c` — capitalizes words in a string
- `7-leet.c` — encodes a string into “1337”
- `100-rot13.c` — encodes a string using ROT13
- `100-atoi.c` — converts a string to an integer

### Memory + “string.h”-style helpers

- `0-memset.c` — fills memory with a constant byte
- `1-memcpy.c` — copies memory from one buffer to another
- `2-strchr.c` — locates a character in a string
- `3-strspn.c` — gets the length of a prefix substring
- `4-strpbrk.c` — searches a string for any of a set of bytes
- `5-strstr.c` — locates a substring

### 2D arrays / advanced pointer tasks

- `7-print_chessboard.c` — prints an 8x8 chessboard
- `8-print_diagsums.c` — prints sums of diagonals of a square matrix
- `100-set_string.c` — sets the value of a pointer to a char

### Advanced / extra tasks

- `101-print_number.c` — prints an integer using `_putchar`
- `102-magic.c` — pointer “magic” task
- `103-infinite_add.c` — adds two numbers stored as strings
- `104-print_buffer.c` — prints a buffer in a readable format

### Keygen / crackme artifacts (advanced)

- `101-keygen`, `101-keygen.c` — key generator program files
- `101-crackme`, `101-crackme_password` — related advanced-task artifacts

## Compilation

Example:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o prog
```

## Author

Aliyyiakbar Shirinli
