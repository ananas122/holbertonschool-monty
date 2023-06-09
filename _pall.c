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
