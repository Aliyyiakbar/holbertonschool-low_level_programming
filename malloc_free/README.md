# C - malloc, free

This directory contains my solutions for the Holberton School project **"C - malloc, free"**.

The purpose of this project is to practice **dynamic memory allocation** in C using
`malloc` and `free`, and to understand when dynamic allocation is needed compared to
automatic (stack) allocation. The project also focuses on writing leak-free code.

## Requirements

- OS: Ubuntu 20.04 LTS
- Compiler: `gcc`
- Flags: `-Wall -Werror -Wextra -pedantic -std=gnu89`
- Style: Betty
- No global variables
- No more than 5 functions per file
- Allowed C standard library functions: `malloc`, `free` only
  (no `printf`, `puts`, `calloc`, `realloc`, etc.)
- `_putchar` is allowed
- Header file: `main.h` (contains all prototypes)

## Files

- `main.h`  
  Header file containing all function prototypes.

- `0-create_array.c`  
  Creates an array of chars, initializes it with a specific character,
  and returns a pointer to the allocated memory.

- `1-strdup.c`  
  Implements `_strdup`: returns a newly allocated copy of a string.

- `2-str_concat.c`  
  Concatenates two strings into a newly allocated buffer and returns it.

- `3-alloc_grid.c`  
  Allocates a 2D grid (array) of integers and initializes it.

- `4-free_grid.c`  
  Frees a 2D integer grid previously created by `alloc_grid`.

- `100-argstostr.c`  
  Concatenates all program arguments into a single newly allocated string,
  with each argument followed by a newline.

- `101-strtow.c`  
  Splits a string into words and returns an array of strings
  (each word is dynamically allocated). Returns `NULL` on failure.

## Notes

- Every successful `malloc` must have a matching `free`.
- On allocation failure, functions return `NULL` and must clean up any memory
  already allocated.

## Valgrind (leak checking)

Example usage (optional, for local testing):

```bash
valgrind --leak-check=full ./prog
```

## Author

Aliyyiakbar Shirinli
