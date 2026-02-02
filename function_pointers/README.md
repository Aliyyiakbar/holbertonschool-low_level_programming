# C - Function pointers

This directory contains my solutions for the Holberton School project **"C - Function pointers"**.

The goal of this project is to understand what function pointers are, what they store,
and how they can be used to pass behavior (functions) as arguments to other functions.

## Requirements

- OS: Ubuntu 20.04 LTS
- Compiler: `gcc`
- Flags: `-Wall -Werror -Wextra -pedantic -std=gnu89`
- Style: Betty
- No global variables
- No more than 5 functions per file
- Allowed C standard library functions: `malloc`, `free`, `exit`
  (no `printf`, `puts`, `calloc`, `realloc`, etc.)
- `_putchar` is allowed
- Header file: `function_pointers.h` (include guarded)

## Files

### Core tasks

- `function_pointers.h`  
  Header file containing all function prototypes for this project.

- `0-print_name.c`  
  Defines a function that prints a name using a function pointer callback.

- `1-array_iterator.c`  
  Defines a function that executes a given function on each element of an array.

- `2-int_index.c`  
  Defines a function that searches for an integer in an array using a comparison
  function pointer and returns its index.

### Calculator (task 3)

This part implements a simple command-line calculator using function pointers
to select the correct operation.

- `3-calc.h`  
  Header for the calculator: struct definition and prototypes.

- `3-op_functions.c`  
  Implements the operation functions (`+`, `-`, `*`, `/`, `%`).

- `3-get_op_func.c`  
  Selects the correct operation function based on the operator string.

- `3-main.c`  
  Entry point for the calculator program. Validates arguments and prints the result.

### Advanced task

- `100-main_opcodes.c`  
  Prints the opcodes of its own `main` function (byte values), based on the number
  of bytes requested via command-line argument.

## Compilation

Example:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o prog

## Author

Aliyyiakbar Shirinli