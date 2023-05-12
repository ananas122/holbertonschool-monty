
![Holberton School logo](https://user-images.githubusercontent.com/120781178/229278297-98c6e4b7-f15f-4788-a893-15cb97f10351.png)

#  <p align="Center">Projet holbertonschool-monty</p>


# Table of Contents 📋

1. Description
2. Getting starting
3. Features
4. Usage and Compilation
5. Exemples
6. Environnement
7. Authors



# 1. Description

**The Holberton School Monty project** is a programming project in the C language that involves creating an interpreter for the Monty language. The Monty language is a very simple programming language, designed to be easy to learn and use, and which allows working with stacks.

The objective of the project is to create a program that takes a Monty file as input, parses it, and executes the instructions contained in it using a stack to store data. Monty instructions are limited to a restricted set of stack operations, such as adding an element to the stack (push), removing the top element of the stack (pop), displaying all elements in the stack (pall), etc.
**Monty** is a scripting language that is first compiled into Monty byte codes. It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty byte codes files.

# 2. Getting Started

To get started with the Monty project, clone this repository onto your local machine by running the following command:
`git clone https://github.com/<username>/monty.git`


# 3. Features
### Here is the list of files involved in the operation of the Monty program:

### [monty.c](https://github.com/ananas122/holbertonschool-monty/blob/main/monty.c)
The main file that contains the main function and opens and reads the Monty file line by line.
<details>
<summary>File</summary>

```c
#include "monty.h"

/**
 * main - Open, read, and close file.m.
 * @ac: nombre d'argument
 * @av: pointer de pointers
 * Return: Always 0.
 */

int main(int ac, char **av)
{
	int line = 1;
	ssize_t openFile, readFile;
	char *buffer, *token;
	int isPush = 0;
	stack_t *h = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	openFile = open(av[1], O_RDONLY);
	if (openFile == -1)
	{
		fprintf(stderr,"Error: can't open file %s", av[1]);
		exit(EXIT_FAILURE);
	}

	buffer = malloc(sizeof(char) * 10000);
	if (!buffer)
		return (0);

	readFile = read(openFile, buffer, 10000);
	if (readFile == -1)
	{
		free(buffer);
		close(openFile);
		exit(EXIT_FAILURE);
	}

	token = strtok(buffer, DELIMS);

	while (token != NULL)
	{
		if (isPush == 1)
		{
			_push(&h, line, token);
			isPush = 0;
			token = strtok(NULL, DELIMS);
			line++;
			continue;
		}
		else if (strcmp(token, "push") == 0)
		{
			isPush = 1;
			token = strtok(NULL, DELIMS);
			continue;
		}
		else
		{
			if (getfunc(token) != 0)
				getfunc(token)(&h, line);
			else
			{
				_freeList(&h);
				fprintf(stderr, "L%d: unknown instruction %s\n", line, token);
				exit(EXIT_FAILURE);
			}
		}

		line++;
		token = strtok(NULL, DELIMS);
	}

	_freeList(&h);
	free(buffer);
	close(openFile);
	return (0);
}
```
</details>

--------------------

### [monty.h](https://github.com/ananas122/holbertonschool-monty/blob/main/monty.h)
monty.h: The header file that contains the declarations of functions and structures used in the program.
<details>
<summary>File</summary>

```c
 #ifndef MONTY_H
#define MONTY_H

/* LIBRARIES */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

/* DEFINE */

#define DELIMS "\n\t\a\r ;:"

/* STRUCTURES */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* PROTOTYPES */
void (*getfunc(char *opcode))(stack_t **stack, unsigned int line_number);
void _push(stack_t **head, unsigned int n, char *token);
void _freeList(stack_t **head);
void _pall(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);

#endif

```
</details>

--------------------

### [getfunc.c](https://github.com/ananas122/holbertonschool-monty/blob/main/getfunc.c)
The file that contains the definitions of the operation functions available in the program (push, pall, pop, add, swap, nop..).
<details>
<summary>File</summary>

```c
 #include "monty.h"

/**
 * getfunc - selects the correct function to perform the
 * operation asked by the opcode in the script file
 * @opcode: the opcode to be evaluated
 * Return: pointer to the function that corresponds to the opcode
 */

void (*getfunc(char *opcode))(stack_t **stack, unsigned int line_number)
{
        int i = 0;
        instruction_t op_struct[] = {
                {"pall", _pall},
                {"pint", _pint},
                {"pop", _pop},
                {"swap", _swap},
                {"add", _add},
                {"nop", _nop},
                {NULL, NULL}
        };

        /** Loop through array and compare token to opcode */
        for (; op_struct[i].opcode != NULL; i++)
        {
                if (strcmp(opcode, op_struct[i].opcode) == 0)
                        return (op_struct[i].f);
        }
        return (NULL);
}
```
</details>

--------------------

### [_push.c](https://github.com/ananas122/holbertonschool-monty/blob/main/_push.c)
 The file that contains the definition of the push function, which adds an element to the stack.
 <details>
<summary>File</summary>

```c
 #include "monty.h"

/**
 * _push - ajoute un nouveau noeud en haut de la liste
 * @head: Double pointer en haut de la liste
 * @n: interger to be added to the dlistint_t list
 * @token: Chaîne de caractères représentant l'opération à effectuer
 */

void _push(stack_t **head, unsigned int n, char *token)
{
        int value;
        stack_t *new_node;

        if (head == NULL)
        {
                fprintf(stderr, "L%u: usage: push integer\n", n);
                exit(EXIT_FAILURE);
        }

        if (token == NULL)
        {
                fprintf(stderr, "L%u: usage: push integer\n", n);
                exit(EXIT_FAILURE);
        }
        value = atoi(token);
        if (strspn(token, "0123456789+-") != strlen(token))
        {
                fprintf(stderr, "L%u: usage: push integer\n", n);
                exit(EXIT_FAILURE);
        }
        new_node = malloc(sizeof(stack_t));
        if (new_node == NULL)
        {
                fprintf(stderr, "Error: malloc failed\n");
                exit(EXIT_FAILURE);
        }
        new_node->n = value;
        new_node->prev = NULL;
        new_node->next = *head;
        if (*head != NULL)
        {
                (*head)->prev = new_node;
        }
        *head = new_node;
}

```
</details>

--------------------

### [_pall.c](https://github.com/ananas122/holbertonschool-monty/blob/main/pall.c)
The file that contains the definition of the pall function, which prints all elements of the stack.
 <details>
<summary>File</summary>

```c
#include "monty.h"

/**
 * _pall - prints all the values on the stack
 * starting from the top of the stack
 * @stack: double pointer to the beginning of the stack
 * @line_number: line number being interpreted from script file
 * Return: nothing
 */
void _pall(stack_t **stack, unsigned int __attribute__((unused)) line_number)
{
        stack_t *tmp = *stack; /*Créer un ptr tmp pour parcourir la pile*/

        /* Parcourir la pile tant que le ptr tmp n'est pas NULL*/
        while (tmp)
        {
                printf("%d\n", tmp->n);
                tmp = tmp->next;
        }
}
```
</details>

--------------------

### [_pop.c](https://github.com/ananas122/holbertonschool-monty/blob/main/_pop.c)
The file that contains the definition of the pop function, which removes the top element of the stack.
 <details>
<summary>File</summary>

```c
 #include "monty.h"

/**
 * _pop - desempiler the top element of the stacks.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number of the opcode in the Monty file.
 */

void _pop(stack_t **stack, unsigned int line_number)
{
        stack_t *tmp = NULL;

        if (*stack == NULL)
        {
                fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
                exit(EXIT_FAILURE);
        }

        tmp = *stack;
        *stack = (*stack)->next;
        free(tmp);
}

```
</details>

--------------------

### [_add.c](https://github.com/ananas122/holbertonschool-monty/blob/main/_add.c)
The file that contains the definition of the add function, which adds the first two elements of the stack.
 <details>
<summary>File</summary>

```c
  #include "monty.h"

/**
 * _pop - desempiler the top element of the stacks.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number of the opcode in the Monty file.
 */

void _pop(stack_t **stack, unsigned int line_number)
{
        stack_t *tmp = NULL;

        if (*stack == NULL)
        {
                fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
                exit(EXIT_FAILURE);
        }

        tmp = *stack;
        *stack = (*stack)->next;
        free(tmp);
}

```
</details>

--------------------

### [_swap.c](https://github.com/ananas122/holbertonschool-monty/blob/main/_swap.c)
The file that contains the definition of the swap function, which swaps the positions of the first two elements of the stack.
<details>
<summary>File</summary>

```c
#include "monty.h"

/**
 * _swap - switch 2 first elements
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode being executed
 */

void _swap(stack_t **stack, unsigned int line_number)
{
        /* Vérifier si la P contient 2 éléments */
        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }

        /* Échanger les valeurs des deux premiers éléments de la pile*/
        int tmp = (*stack)->n;
        (*stack)->n = (*stack)->next->n;
        (*stack)->next->n = tmp;
}
```
</details>

--------------------

### [_nop.c](https://github.com/ananas122/holbertonschool-monty/blob/main/_nop.c)
The file that contains the definition of the nop function, which does nothing.
<details>
<summary>File</summary>

```c
 #include "monty.h"

/**
 * _nop - Ne rien faire
 * @stack: Double pointeur sur la tête de la pile
 * @line_number: Numéro de la ligne en cours d'exécution
 */

void _nop(stack_t **stack, unsigned int line_number)
{
        (void)stack;
        (void)line_number;
}

```
</details>

--------------------

 ### [_freeList.c](https://github.com/ananas122/holbertonschool-monty/blob/main/_freeList.c)
 <details>
<summary>File</summary>

```c
 #include "monty.h"
/**
 * _freeList - Frees a list_t list.
 * @head: A pointer to the list_t list.
 */

void _freeList(stack_t **head)
{
        if (!head)
                return;

        while (*head && (*head)->next)
        {
                *head = (*head)->next;
                free((*head)->prev);
        }
        free(*head);
}
```
</details>

--------------------


# 4. Usage 🔧

Once you have cloned the repository, navigate to the monty directory and run the following command to compile the program:

`gcc -Wall -Werror -Wextra -pedantic *.c -o monty`

To run the program, use the following command:

`./monty <file_name>`



# 5.Exemples Monty Byte Code Files

Files containing Monty byte codes usually have the .m extension. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument.

`./monty bytecodes/00.m`

 `julien@ubuntu:~/monty$ cat -e bytecodes/00.m`
```
push 1$
push 2$
push 3$
pall$
 ```

```
julien@ubuntu:~/monty$ ./monty bytecodes/00.m
3
2
1
julien@ubuntu:~/monty$
```
### Explication
The instructions in the file bytecodes/00.m are as follows:

1. push 1: Adds the integer 1 to the stack.
2. push 2: Adds the integer 2 to the stack.
3. push 3: Adds the integer 3 to the stack.
3. pall: Displays all the elements in the stack.

When the Monty program is executed with these instructions,
1. it adds the integers 1, 2, and 3 to the stack in that order, and then
2. displays all the elements in the stack (3, 2, and 1) using the pall instruction.
3. Then, the program terminates without any errors, and the terminal returns to the command prompt.


# 6. Environnement
Environment

<!-- ubuntu -->
<a href="https://ubuntu.com/" target="_blank"> <img height="" src="https://img.shields.io/static/v1?label=&message=Ubuntu&color=E95420&logo=Ubuntu&logoColor=E95420&labelColor=2F333A" alt="Suite CRM"></a> OS: Ubuntu 20.04 LTS
<!-- bash -->
<a href="https://www.gnu.org/software/bash/" target="_blank"> <img height="" src="https://img.shields.io/static/v1?label=&message=GNU%20Bash&color=4EAA25&logo=GNU%20Bash&logoColor=4EAA25&labelColor=2F333A" alt="terminal"></a>
<!-- c -->
<a href="https://www.cprogramming.com/" target="_blank"><img src="https://img.shields.io/static/v1?label=&message=C%20Language&color=5C6BC0&logo=c&logoColor=A8B9CC&labelColor=2F333A" alt="C Low level programming language"></a> Language: C
Compiler: gcc 9.3.0
<!-- vim -->
<a href="https://www.vim.org/" target="_blank"> <img height="" src="https://img.shields.io/static/v1?label=&message=Vim&color=019733&logo=Vim&logoColor=019733&labelColor=2F333A" alt="Suite CRM"></a> Editor: VIM 8.1.2269
<!-- git -->
<a href="https://git-scm.com/" target="_blank"> <img height="" src="https://img.shields.io/static/v1?label=&message=Git&color=F05032&logo=Git&logoColor=F05032&labelColor=2F333A" alt="git distributed version control system"></a> Control version: Git
<!-- github -->
<a href="https://github.com" target="_blank"> <img height="" src="https://img.shields.io/static/v1?label=&message=GitHub&color=181717&logo=GitHub&logoColor=f2f2f2&labelColor=2F333A" alt="Github"></a>

Style guidelines: [Betty style](https://github.com/holbertonschool/Betty/wiki)


## 6. AUTHORS :black_nib:

[`samira D and Jerome B`](https://github.com/xdJidx/holbertonschool-simple_shell/blob/main/AUTHORS)


