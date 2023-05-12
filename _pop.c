#include "monty.h"

/**
 * _pop - desempiler the top element of the stacks.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number of the opcode in the Monty file.
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	/* si la pile est vide*/
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Stocke le sommet dans une variable temporaire */
	tmp = *stack;
	/* Met à jour le sommet en le remplaçant par le suivant */
	*stack = (*stack)->next;
	/* Libère la mémoire allouée pour l'ancien sommet*/
	free(tmp);
}
