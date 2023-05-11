#include "monty.h"

/**
 * main - check the code
 * @ac: nombre d'argument
 * @av: pointer de pointer
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
		dprintf(2, "Usage: %s file\n", av[0]);
		exit (EXIT_FAILURE);
 	}
	
	openFile = open(av[1], O_RDONLY);
	if (openFile == -1)
	{
		printf("ERROR");
		exit (EXIT_FAILURE);
	}

	buffer = malloc(sizeof(char) * 10000);
	if (!buffer)
		return (0);

	readFile = read(openFile, buffer, 10000);
	if (readFile == -1)
	{
		free(buffer);
		close(openFile);
		exit (EXIT_FAILURE);
	}	

	token = strtok(buffer, DELIMS);

	while (token != NULL)
	{
		if (isPush == 1)
		{
			_push(&h, line, token);
			isPush = 0;
			token = strtok(NULL, DELIMS);
			line++;
			continue;
		}
		else if (strcmp(token, "push") == 0)
		{
			isPush = 1;
			token = strtok(NULL, DELIMS);
			continue;
		}
		else 
		{
			if (getfunc(token) != 0)
				getfunc(token)(&h, line);
			else
			{
				_freeList (&h);
				printf("L%d: unknown instruction %s\n", line, token);
				exit (EXIT_FAILURE);
			}			
		}
		
		line++;
		token = strtok(NULL, DELIMS);	
	}
		
	_freeList(&h);
	free(buffer);
	close(openFile);
	return (0);
}