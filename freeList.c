#include "monty.h"

/**
 * _freeList - Frees a list_t list.
 * @head: A pointer to the list_t list.
 *
 */

void _freeList(stack_t **head)
{
	 /* Vérifier si la tête est NULL */
	if (!head)
		return;
	/* Parcourir la liste chainée et libérer chaque noeud */
	while (*head && (*head)->next)
	{
		*head = (*head)->next;
		free((*head)->prev);
	}
	/* Libérer la mémoire occupée par la tête de la liste */
	free(*head);
}
