# C - Functions, nested loops

This directory contains my work for the Holberton School project **"C - Functions, nested loops"**.

The main focus of this project is to practice:
- writing functions and using function prototypes
- working with nested loops
- understanding variable scope
- using header files (`main.h`)
- printing output using `_putchar` (no standard library functions)

## Requirements

- OS: Ubuntu 20.04 LTS
- Compiler: `gcc`
- Flags: `-Wall -Werror -Wextra -pedantic -std=gnu89`
- Style: Betty
- No global variables
- No more than 5 functions per file
- No standard library functions (`printf`, `puts`, etc.) allowed
- Allowed output function: `_putchar`
- Function prototypes (and `_putchar`) are declared in `main.h`

## Files

- `main.h`  
  Header file containing all function prototypes and the `_putchar` prototype.

- `0-putchar.c`  
  Prints `_putchar` followed by a newline.

- `1-alphabet.c`  
  Prints the alphabet in lowercase.

- `2-print_alphabet_x10.c`  
  Prints the alphabet in lowercase 10 times.

- `3-islower.c`  
  Checks for a lowercase character.

- `4-isalpha.c`  
  Checks for an alphabetic character.

- `5-sign.c`  
  Prints the sign of a number and returns it.

- `6-abs.c`  
  Computes the absolute value of an integer.

- `7-print_last_digit.c`  
  Prints the last digit of a number and returns it.

- `8-24_hours.c`  
  Prints every minute of the day from 00:00 to 23:59.

- `9-times_table.c`  
  Prints the 9 times table starting from 0.

- `10-add.c`  
  Adds two integers and returns the result.

- `11-print_to_98.c`  
  Prints all natural numbers from `n` to `98`.

### Advanced tasks

- `100-times_table.c`  
  Prints the `n` times table (usually for values 0 to 15, depending on the task rules).

- `101-natural.c`  
  Computes and prints the sum of multiples of 3 or 5 below 1024.

- `102-fibonacci.c`  
  Prints the first 50 Fibonacci numbers.

- `103-fibonacci.c`  
  Prints the sum of even-valued Fibonacci terms below 4,000,000.

- `104-fibonacci.c`  
  Prints the first 98 Fibonacci numbers.

## Compilation

Example:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o prog
./prog

## Author

Aliyyiakbar Shirinli