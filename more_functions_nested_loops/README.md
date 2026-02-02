# C - More functions, more nested loops

This directory contains my solutions for the Holberton School project
**"C - More functions, more nested loops"**.

The goal of this project is to practice writing small C functions, using nested loops,
and printing output using `_putchar` while following the Betty style.

## Requirements

- OS: Ubuntu 20.04 LTS
- Compiler: `gcc`
- Flags: `-Wall -Werror -Wextra -pedantic -std=gnu89`
- Style: Betty
- No global variables
- No more than 5 functions per file
- No standard library functions allowed (`printf`, `puts`, etc.)
- `_putchar` is allowed
- Header file: `main.h` (contains all function prototypes)

## Files

- `main.h`  
  Header file containing all prototypes used in this project.

- `0-isupper.c`  
  Checks for an uppercase character.

- `1-isdigit.c`  
  Checks for a digit (0 through 9).

- `2-mul.c`  
  Multiplies two integers.

- `3-print_numbers.c`  
  Prints the numbers from 0 to 9.

- `4-print_most_numbers.c`  
  Prints the numbers from 0 to 9 except 2 and 4.

- `5-more_numbers.c`  
  Prints the numbers 0 to 14 ten times.

- `6-print_line.c`  
  Draws a straight line using `_`.

- `7-print_diagonal.c`  
  Draws a diagonal line using `\`.

- `8-print_square.c`  
  Prints a square using `#`.

- `9-fizz_buzz.c`  
  Prints numbers from 1 to 100, replacing multiples of 3 with `Fizz`,
  multiples of 5 with `Buzz`, and multiples of both with `FizzBuzz`.

- `10-print_triangle.c`  
  Prints a triangle using `#`.

### Advanced tasks

- `100-prime_factor.c`  
  Prints the largest prime factor of a given number.

- `101-print_number.c`  
  Prints an integer using `_putchar` (handles negative numbers).

## Compilation

Example:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o prog
./prog
```

## Author

Aliyyiakbar Shirinli
