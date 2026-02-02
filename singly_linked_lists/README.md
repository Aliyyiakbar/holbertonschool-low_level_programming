# Holberton School – Singly linked lists

This directory contains my C solutions for the Holberton School – Singly linked lists project.
The goal is to learn when to use linked lists instead of arrays, and how to build and manipulate
a singly linked list (print, add nodes, free memory, etc.).

## Requirements

- OS: Ubuntu 20.04 LTS
- Compiler: gcc
- Flags: -Wall -Werror -Wextra -pedantic -std=gnu89
- Style: Betty
- No global variables
- Max 5 functions per file
- Allowed C standard library functions: malloc, free, exit
- You are allowed to use _putchar
- All files end with a new line
- Header: lists.h (include-guarded, contains all prototypes + _putchar)

## Data Structure

```c
/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
    char *str;
    unsigned int len;
    struct list_s *next;
} list_t;
```

## Tasks

- 0. Print list — print all elements of a list_t list (print [0] (nil) if str is NULL)
- 1. List length — return the number of elements in the list
- 2. Add node — add a new node at the beginning of the list
- 3. Add node at the end — add a new node at the end of the list
- 4. Free list — free an entire list
- 5. The Hare and the Tortoise (Advanced) — print a sentence before main() runs

## Compilation

Example (compile one task with its test main):

```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 0-main.c 0-print_list.c -o 0-print
./0-print
```

Example (compile all source files in the directory):

```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 *.c -o singly_linked_lists
./singly_linked_lists
```

## Author

Aliyyiakbar Shirinli
