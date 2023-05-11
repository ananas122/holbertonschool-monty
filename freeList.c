#include "monty.h"

/**
 * _freeList - Frees a list_t list.
 * @head: A pointer to the list_t list.
 */

void _freeList(stack_t **head)
{
	if (!head)
		return;

	while(*head && (*head)->next)
	{
		*head = (*head)->next;
		free((*head)->prev);
	}
	free(*head);
}
