#include "monty.h"

/**
 * _pint - prints the value at the top of the stack
 * @stack: The stack to operate on.
 * @line_number: line number
 * Return: The value at the top of the stack
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	/* Vérifier si le stack est vide */
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Imprimer la valeur au sommet de la pile */
	printf("%d\n", (*stack)->n);
}

