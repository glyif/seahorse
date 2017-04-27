<img src="https://www.holbertonschool.com/assets/holberton-logo-1cc451260ca3cd297def53f2250a9794810667c7ca7b5fa5879a569a457bf16f.png" alt="Holberton logo">

# .

## Author: Bobby Yang


## Synopsis

## Using

## TODO

## File Breakdown

### header.h
This is a header file containing all of the prototypes 				necessary for testing with a main function.

### argv.c
```c
int word_count(char *s);
This function parces string for space
```

- `@s`  string
- `Return`  number of words
```c
void copy_array(char *from, char **to, int start, int index);
This function copies array
```

- `@from`  from
- `@to`  to
- `@start`  index of start of copy
- `@index`  index of array of pointers
- `Return`  nothing;
```c
char **my_argv(char *s);
This function my argv implementation
```

- `@s`  string
- `Return`  array of pointers


### _isupper.c
```c
int _isupper(int i);
This function checks for uppper case number
```

- `@i`  integer
- `Return`  1 if c is upper, 0 otherwise


### _memcpy.c
```c
char *_memcpy(char *dest, char *src, unsigned int n);
This function n types from src to dest
```

- `@dest`  destination of copy
- `@src`  source of copy
- `@n`  number of times
- `Return`  pointer set to dest


### _strlen.c
```c
int _strlen(char *s);
This function finds length of a string
```

- `@s`  string
- `Return`  length of the string s


