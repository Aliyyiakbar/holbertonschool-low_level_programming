# C - Hello, World

This directory contains my first C project at Holberton School.
The goal is to learn the basic C workflow: preprocessing, compiling, assembling, linking,
and writing simple programs that print text and display type sizes.

## Requirements

- OS: Ubuntu 20.04 LTS
- Compiler: gcc
- Flags: `-Wall -Werror -Wextra -pedantic -std=gnu89`
- Style: Betty
- No warnings or errors during compilation
- Shell scripts must be exactly 2 lines and start with `#!/bin/bash`

## Files

### Shell scripts

- `0-preprocessor`  
  Runs a C file through the preprocessor only and saves the result.

- `1-compiler`  
  Compiles a C file but does not link (generates an assembly file).

- `2-assembler`  
  Generates an object file from a C file (compile + assemble, no link).

- `3-name`  
  Compiles a C file and creates an executable named `cisfun`.

- `100-intel`  
  Generates assembly code using Intel syntax.

### C programs

- `4-puts.c`  
  Prints a line of text using `puts`.

- `5-printf.c`  
  Prints a line of text using `printf`.

- `6-size.c`  
  Prints the size (in bytes) of different data types using `sizeof`.

- `101-quote.c`  
  Prints a quote to standard error and exits with status `1`.

## Usage notes

Most of the scripts expect the input C filename to be provided through an environment
variable (usually `CFILE`), for example:

```bash
export CFILE=main.c
./0-preprocessor
./1-compiler
./2-assembler
./3-name
