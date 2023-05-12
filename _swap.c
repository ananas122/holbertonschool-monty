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

	/* Échanger les valeurs des 2 1er élm de la pile*/
	int tmp = (*stack)->n;/*stocker la valeur du 1er élm de la pile,*/
	(*stack)->n = (*stack)->next->n;/*swap la val du 1er élm avc le 2eme élm*/
	(*stack)->next->n = tmp;/*placer la val tmp dans le 2eme élm.*/
}

