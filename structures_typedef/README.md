# C - Structures, typedef

This directory contains my solutions for the Holberton School project
**"C - Structures, typedef"**.

The goal of this project is to learn how to define and use C structures, and how
to create type aliases using `typedef`. The tasks here use a `struct dog` to
practice initialization, printing, dynamic allocation, and proper cleanup.

## Requirements

- OS: Ubuntu 20.04 LTS
- Compiler: `gcc`
- Flags: `-Wall -Werror -Wextra -pedantic -std=gnu89`
- Style: Betty
- No global variables
- No more than 5 functions per file
- Allowed standard library functions: `printf`, `malloc`, `free`, `exit`
- All header files must be include guarded

## Files

- `dog.h`  
  Defines `struct dog` and the `dog_t` typedef, and declares all function prototypes.

- `1-init_dog.c`  
  Initializes a `struct dog` with given name, age, and owner.

- `2-print_dog.c`  
  Prints a `struct dog` in a readable format (handles `NULL` fields safely).

- `4-new_dog.c`  
  Creates a new dog (`dog_t`) dynamically and returns a pointer to it.

- `5-free_dog.c`  
  Frees memory allocated for a dog created by `new_dog`.

## Compilation

Example:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o prog
./prog
```

## Author

Aliyyiakbar Shirinli
