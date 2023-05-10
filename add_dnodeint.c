#include "monty.h"

/**
 * add_dnodeint - ajoute un nouveau noeud en haut de la liste
 * @head: Double pointer en haut de la liste
 * @n: interger to be added to the dlistint_t list
 *
 * Return: If the function fails - NULL
 *		Otherwise - the address of the new element
 */

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = *head;
	new->prev = NULL;

	if (*head != NULL)
		(*head)->prev = new;

	*head = new;

	return (new);
}
