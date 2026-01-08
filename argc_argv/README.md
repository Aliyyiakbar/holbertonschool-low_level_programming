# C - argc, argv

This directory contains my solutions for the Holberton School project **"C - argc, argv"**.

The goal of this project is to learn how to handle command-line arguments in C using
`argc` (argument count) and `argv` (argument vector), and how to deal with unused
parameters cleanly when compiling with strict flags.

## Concepts covered

- Passing arguments to a program from the command line
- The two common `main` prototypes:
  - `int main(void)` (no arguments)
  - `int main(int argc, char *argv[])` (with arguments)
- Handling unused variables with `(void)variable;` or `__attribute__((unused))`
- Input validation and basic string-to-integer conversion

## Requirements

- OS: Ubuntu 20.04 LTS
- Compiler: `gcc`
- Flags: `-Wall -Werror -Wextra -pedantic -std=gnu89`
- Style: Betty
- No global variables
- No more than 5 functions per file
- Standard library is allowed
- Each file ends with a new line

## Files

- `0-whatsmyname.c`  
  Prints the program name (`argv[0]`).

- `1-args.c`  
  Prints the number of arguments passed to the program.

- `2-args.c`  
  Prints all arguments received, one per line.

- `3-mul.c`  
  Multiplies two numbers passed as arguments and prints the result.
  Prints `Error` if the number of arguments is wrong.

- `4-add.c`  
  Adds positive numbers passed as arguments and prints the result.
  Prints `Error` if any argument is not a valid positive integer.

- `100-change.c`  
  Prints the minimum number of coins needed to make change for a given amount.
  Prints `Error` if the number of arguments is wrong.

## Compilation

Example:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o prog
./prog
