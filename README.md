# Projet holbertonschool-monty

This repository contains the code for the **Monty project**, which is part of the curriculum at Holberton School.

# Description

**Monty** is a scripting language that is first compiled into Monty byte codes. It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty byte codes files.

# Getting Started

To get started with the Monty project, clone this repository onto your local machine by running the following command:
`git clone https://github.com/<username>/monty.git`


# Features 
### Here is the list of files involved in the operation of the Monty program:

### [monty.c](https://github.com/ananas122/holbertonschool-monty/blob/main/monty.c) 
The main file that contains the main function and opens and reads the Monty file line by line.
<details>
<summary>File</summary>

```c
```
</details>

--------------------

### [monty.h](https://github.com/ananas122/holbertonschool-monty/blob/main/monty.h) 
monty.h: The header file that contains the declarations of functions and structures used in the program.
<details>
<summary>File</summary>

```c
```
</details>

--------------------

### [getfunc.c](https://github.com/ananas122/holbertonschool-monty/blob/main/getfunc.c) 
The file that contains the definitions of the operation functions available in the program (push, pall, pop, add, swap, nop..).
<details>
<summary>File</summary>

```c
```
</details>

--------------------

### [_push.c](https://github.com/ananas122/holbertonschool-monty/blob/main/_push.c) 
 The file that contains the definition of the push function, which adds an element to the stack.
 <details>
<summary>File</summary>

```c
```
</details>

--------------------

### [op_pall.c](https://github.com/ananas122/holbertonschool-monty/blob/main/op_pall.c)
The file that contains the definition of the pall function, which prints all elements of the stack.
 <details>
<summary>File</summary>

```c
```
</details>

--------------------

### [_pop.c](https://github.com/ananas122/holbertonschool-monty/blob/main/_pop.c)
The file that contains the definition of the pop function, which removes the top element of the stack.
 <details>
<summary>File</summary>

```c
```
</details>

--------------------

### [_add.c](https://github.com/ananas122/holbertonschool-monty/blob/main/_add.c)
The file that contains the definition of the add function, which adds the first two elements of the stack.
 <details>
<summary>File</summary>

```c
```
</details>

--------------------

### [_swap.c](https://github.com/ananas122/holbertonschool-monty/blob/main/_swap.c)
The file that contains the definition of the swap function, which swaps the positions of the first two elements of the stack.
<details>
<summary>File</summary>

```c
```
</details>

--------------------

### [_nop.c](https://github.com/ananas122/holbertonschool-monty/blob/main/_nop.c)
The file that contains the definition of the nop function, which does nothing.
<details>
<summary>File</summary>

```c
```
</details>

--------------------


# Usage

Once you have cloned the repository, navigate to the monty directory and run the following command to compile the program:

`gcc -Wall -Werror -Wextra -pedantic *.c -o monty`

To run the program, use the following command:

`./monty <file_name>`



# Exemples Monty Byte Code Files

Files containing Monty byte codes usually have the .m extension. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument.



# Examples


