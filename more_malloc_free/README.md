# C - More malloc, free

This directory contains my solutions for the Holberton School project
**"C - More malloc, free"**.

This project focuses on deeper dynamic memory management in C:
- allocating memory safely and handling failures
- building helper allocation functions
- implementing behaviors similar to `calloc` and `realloc` (without using them)
- practicing clean memory handling and error exits

## Requirements

- OS: Ubuntu 20.04 LTS
- Compiler: `gcc`
- Flags: `-Wall -Werror -Wextra -pedantic -std=gnu89`
- Style: Betty
- No global variables
- No more than 5 functions per file
- Allowed C standard library functions: `malloc`, `free`, `exit` only  
  (no `printf`, `puts`, `calloc`, `realloc`, etc.)
- `_putchar` is allowed
- Header file: `main.h` (contains all prototypes)

## Files

- `main.h`  
  Header file containing all function prototypes for this project.

- `0-malloc_checked.c`  
  Implements `malloc_checked`: allocates memory and exits with status `98` if `malloc` fails.

- `1-string_nconcat.c`  
  Implements `string_nconcat`: concatenates two strings into newly allocated memory,
  using at most `n` bytes from the second string.

- `2-calloc.c`  
  Implements `_calloc`: allocates memory for an array and initializes it to zero.

- `3-array_range.c`  
  Implements `array_range`: creates an array of integers containing all values from
  `min` to `max` (inclusive).

### Advanced tasks

- `100-realloc.c`  
  Implements `_realloc`: resizes a memory block while preserving existing content when possible.

- `101-mul.c`  
  Multiplies two positive numbers provided as command-line arguments (big integer style).

  **Note:** This file is currently **not the final solution**. The implementation is **broken**
  (does not fully meet the task requirements / does not pass all expected checks).
  It is kept in the repository as a work-in-progress.

## Compilation

Example:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o prog
```

## Author

Aliyyiakbar Shirinli
