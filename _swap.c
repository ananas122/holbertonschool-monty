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

