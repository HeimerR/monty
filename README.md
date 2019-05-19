##MONTY

## Description

It is a interpreter for Monty ByteCodes files.

***

## Usage

1. Clone the repository:
```console
https://github.com/HeimerR/monty.git
```

2. Enter at directory
```console
cd monty
```

3. Compile:
```console
gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```

4. Execute:
```console
./monty file.m
//The file contains the bytcode instructions for example
cat -e 000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
```

## Functions

The functions used are:

|Name | Description | Return|
|:--: | :-- | :--|
|_strcpy | Copy a string| Destination Pointer|
|_strlen | Calculate size of a string | Size a string|
|str_concat | Concat two string | Pointer to a array|
|build_argv | Build argv to send myexec | Array to pointer with arguments|
|build_path | Find path to execute | Pointer with the value of full path|
|_getline | Delimited a string input | The length of input|
|_strtok | Extract tokens from a string | A pointer to the next token|
|_strspn | Find some char into a string | The number of characters in the initial segment|
|get_value_env | Find the value of enviroment variable | Pointer start on value of variable|
|myexec | Execute a command | It was succesful or not|
|sighandler | Handle the signals | No Return|
|_realloc | Reallocates a memory block | Pointer a new allocation|
|_realloc_pointer | Reallocates memory of a pointer | Pointer a new allocation|
|main | Entry point of shell |  0 if succes|

### Examples

```console
$jessiFer> ls
basics.c    general.c  holberton.h  memory.c   shell.c
builders.c  helper.c   hsh          README.md  test
```

### Autors

Heimer Rojas & Alexandra Fonseca
