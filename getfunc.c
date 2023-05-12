#include "monty.h"

/**
 * getfunc - selects the correct function to perform the
 * operation asked by the opcode in the script file
 * @opcode: the opcode to be evaluated
 * Return: pointer to the function that corresponds to the opcode
 */

void (*getfunc(char *opcode))(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	instruction_t op_struct[] = {
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{NULL, NULL}
	};

	/* Boucle à travers le tab d'instructions et comparer le token à l'opcode */
	/* Vérifier si le token correspond à l'opcode de l'instruction*/
	for (; op_struct[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, op_struct[i].opcode) == 0)
			return (op_struct[i].f);
	}
	return (NULL);
}
