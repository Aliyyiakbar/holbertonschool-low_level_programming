# C - Variadic functions

This directory contains my solutions for the Holberton School project
**"C - Variadic functions"**.

The goal of this project is to understand variadic functions in C and how to use
the macros from `<stdarg.h>` (`va_start`, `va_arg`, `va_end`) to handle a variable
number of arguments safely.

## Requirements

- OS: Ubuntu 20.04 LTS
- Compiler: `gcc`
- Flags: `-Wall -Werror -Wextra -pedantic -std=gnu89`
- Style: Betty
- No global variables
- No more than 5 functions per file
- Allowed C standard library functions: `malloc`, `free`, `exit` only
  (no `printf`, `puts`, `calloc`, `realloc`, etc.)
- Allowed macros: `va_start`, `va_arg`, `va_end`
- `_putchar` is allowed
- Header file: `variadic_functions.h` (include guarded)

## Files

- `variadic_functions.h`  
  Header file containing all prototypes and required type definitions.

- `0-sum_them_all.c`  
  Returns the sum of all its parameters.

- `1-print_numbers.c`  
  Prints numbers followed by a new line, with a separator between values.

- `2-print_strings.c`  
  Prints strings followed by a new line, with a separator between values.
  Handles `NULL` strings safely.

- `3-print_all.c`  
  Prints anything based on a format string (commonly supports `c`, `i`, `f`, `s`),
  using variadic arguments.

### Advanced task

- `100-hello_world.asm`  
  Assembly program that prints "Hello, World" and exits successfully.

## Compilation

Example:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o prog
```

## Author

Aliyyiakbar Shirinli
