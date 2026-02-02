# Holberton School – Hash tables

This directory contains my C solutions for the Holberton School – Hash tables project.
The goal is to understand how hash tables work (hash functions, indexing, collisions),
and how to implement common operations like create, set, get, print, and delete.

## Requirements

- OS: Ubuntu 20.04 LTS
- Compiler: gcc
- Flags: -Wall -Werror -Wextra -pedantic -std=gnu89
- Style: Betty
- No global variables
- Max 5 functions per file
- You are allowed to use the C standard library
- All files end with a new line
- Header: hash_tables.h (include-guarded, contains all prototypes)

## Data Structures

```c
/**
 * struct hash_node_s - Node of a hash table
 *
 * @key: The key, string (unique in the hash table)
 * @value: The value corresponding to a key
 * @next: Pointer to the next node (chaining)
 */
typedef struct hash_node_s
{
    char *key;
    char *value;
    struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - Hash table data structure
 *
 * @size: The size of the array
 * @array: Array of pointers to the first node of a linked list (chaining)
 */
typedef struct hash_table_s
{
    unsigned long int size;
    hash_node_t **array;
} hash_table_t;
```

## Tasks

- 0. >>> ht = {} — create a hash table
- 1. djb2 — implement the djb2 hash function
- 2. key -> index — get the index of a key in the hash table array
- 3. >>> ht['betty'] = 'cool' — add/update an element in the hash table
- 4. >>> ht['betty'] — retrieve a value associated with a key
- 5. >>> print(ht) — print the hash table (key/value pairs)
- 6. >>> del ht — delete the hash table and free memory
- 7. $ht['Betty'] = 'Cool' (Advanced) — implement a sorted hash table (keeps keys ordered)

## Compilation

Example (compile one task with its test main):

```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 0-main.c 0-hash_table_create.c -o 0-create
./0-create
```

Example (compile all source files in the directory):

```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 *.c -o hash_tables
./hash_tables
```

## Author

Aliyyiakbar Shirinli
