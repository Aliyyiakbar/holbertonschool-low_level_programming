# C - Recursion

This directory contains my solutions for the Holberton School project **"C - Recursion"**.

The purpose of this project is to learn how recursion works in C, how to write
recursive functions correctly, and when recursion is (and is not) a good idea.

## Requirements

- OS: Ubuntu 20.04 LTS
- Compiler: `gcc`
- Flags: `-Wall -Werror -Wextra -pedantic -std=gnu89`
- Style: Betty
- No global variables
- No more than 5 functions per file
- No standard library printing functions (`printf`, `puts`, etc.)
- `_putchar` is allowed
- Header file: `main.h` (contains all prototypes)
- No loops of any kind
- No static variables

## Files

- `main.h`  
  Header file containing all function prototypes for this project.

- `0-puts_recursion.c`  
  Prints a string followed by a newline using recursion.

- `1-print_rev_recursion.c`  
  Prints a string in reverse using recursion.

- `2-strlen_recursion.c`  
  Returns the length of a string using recursion.

- `3-factorial.c`  
  Returns the factorial of a number using recursion.

- `4-pow_recursion.c`  
  Returns the value of `x` raised to the power of `y` using recursion.

- `5-sqrt_recursion.c`  
  Returns the natural square root of a number using recursion
  (or `-1` if the number has no natural square root).

- `6-is_prime_number.c`  
  Checks if an integer is a prime number using recursion.

### Advanced tasks

- `100-is_palindrome.c`  
  Checks if a string is a palindrome using recursion.

- `101-wildcmp.c`  
  Compares two strings where the second string can contain the wildcard `*`.

## Compilation

Example:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o prog
