#include "monty.h"

/**
 * _add - Ajout des 2 premiers elements de la pile
 *
 * @stack: Double pointeur sur la tête de la pile
 * @line_number: Numéro de la ligne en cours d'exécution
 *
 */

void _add(stack_t **stack, unsigned int line_number)
{
	int a, b, result;

	/* Vérifier si la P contient 2 éléments */
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Obtenir les valeurs des 2 1er éléments*/
	a = (*stack)->n;
	b = (*stack)->next->n;
	result = a + b;
	/*stockage dans le 2eme elm top*/
	_pop(stack, line_number);
	(*stack)->n = result;
}
