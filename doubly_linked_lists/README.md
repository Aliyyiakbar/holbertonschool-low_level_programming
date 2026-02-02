# Holberton School – Doubly linked lists

This directory contains my C solutions for the Holberton School – Doubly linked lists project.
The goal is to understand how a doubly linked list works, how to move forward/backward through nodes,
and how to implement common list operations (print, insert, delete, free, etc.).

## Requirements

- OS: Ubuntu 20.04 LTS
- Compiler: gcc
- Flags: -Wall -Werror -Wextra -pedantic -std=gnu89
- Style: Betty
- No global variables
- Max 5 functions per file
- Allowed C functions: malloc, free, printf, exit
- All files end with a new line
- Header: lists.h (include-guarded, contains all prototypes)

## Data Structure

```c
/**
 * struct dlistint_s - doubly linked list
 * @n: integer
 * @prev: points to the previous node
 * @next: points to the next node
 */
typedef struct dlistint_s
{
    int n;
    struct dlistint_s *prev;
    struct dlistint_s *next;
} dlistint_t;
```

## Tasks

- 0. Print list — print all elements of a dlistint_t list, return number of nodes
- 1. List length — return the number of nodes in the list
- 2. Add node — add a new node at the beginning of the list
- 3. Add node at the end — add a new node at the end of the list
- 4. Free list — free an entire list
- 5. Get node at index — return the node at a given index
- 6. Sum list — return the sum of all n values in the list
- 7. Insert at index — insert a new node at a given index
- 8. Delete at index — delete the node at a given index
- 9. Crackme4 (Advanced) — reverse engineer and solve the crackme
- 10. Palindromes (Advanced) — find the largest palindrome made from the product of two 3-digit numbers
- 11. crackme5 (Advanced) — reverse engineer and solve the crackme

## Compilation

Example (compile one task with its test main):

```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 0-main.c 0-print_dlistint.c -o 0-print
./0-print
```

Example (compile all source files in the directory):

```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 *.c -o prog
./prog
```

## Author

Aliyyiakbar Shirinli
