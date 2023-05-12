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
