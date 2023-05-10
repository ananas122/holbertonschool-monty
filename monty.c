#include "monty.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */

int main(int ac, char **av)
{
	char **tokenfile;
	int i;

	if (ac != 2)
	{
		dprintf(2, "Usage: %s file\n", av[0]);
		exit(EXIT_FAILURE);
 	}

	tokenfile = readTextFile(av[1], 1024);
	
	for (i = 0; tokenfile[i][0]; i++)
	{
		get_op_func(tokenfile[i][0]);
	}

    return (0);
}
