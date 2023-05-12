#include "monty.h"

/**
 * main - Open, read, and close file.m.
 * @ac: nombre d'arguments
 * @av: pointer de pointers
 * Return: Always 0.
 */

int main(int ac, char **av)
{
	int line = 1;
	ssize_t openFile, readFile;
	char *buffer, *token;
	int isPush = 0;
	stack_t *h = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	openFile = open(av[1], O_RDONLY);
	if (openFile == -1)
	{
		fprintf(stderr,"Error: can't open file %s", av[1]);
		exit(EXIT_FAILURE);
	}

	buffer = malloc(sizeof(char) * 10000);
	if (!buffer)
		return (0);

	readFile = read(openFile, buffer, 10000);
	if (readFile == -1)
	{
		free(buffer);
		close(openFile);
		exit(EXIT_FAILURE);
	}
	
	/*Obtenir le premier token*/
	token = strtok(buffer, DELIMS);

	while (token != NULL)
	{
		if (isPush == 1)
		{
			/*Si la commande "push" a été détectée*/
			_push(&h, line, token);/*Ajouter le token à la pile*/
			isPush = 0;/*Réinitialiser le drapeau "push"*/
			token = strtok(NULL, DELIMS);/*Obtenir le token suivant*/
			line++;
			continue;
		}
		else if (strcmp(token, "push") == 0)
		{
			/*Si la commande "push" est détectée*/
			isPush = 1;/*Activer le drapeau "push"*/
			token = strtok(NULL, DELIMS);/*Obtenir le token suivant*/
			continue;
		}
		else
		{
			/*Si la commande n'est pas "push"*/
			if (getfunc(token) != 0)
				getfunc(token)(&h, line);/*Exécuter la commande correspondante*/
			else
			{
				_freeList(&h);
				fprintf(stderr, "L%d: unknown instruction %s\n", line, token);
				exit(EXIT_FAILURE);
			}
		}

		line++;
		token = strtok(NULL, DELIMS);/*Obtenir le token suivant*/
	}

	_freeList(&h);
	free(buffer);
	close(openFile);
	return (0);
}
