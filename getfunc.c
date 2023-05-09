#include "monty.h"

/**
 * get_op_func - selects the correct function to perform the
 * operation asked by the opcode in the script file
 * @opcode: the opcode to be evaluated
 * Return: pointer to the function that corresponds to the opcode
 */
void (*get_op_func(char *opcode))(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	instruction_t op_struct[] = {
		{"push", op_push},
		{"pall", op_pall},
		{NULL, NULL}
  	};

	/** Loop through array and compare token to opcode */
	for (int i = 0; op_struct[i].op_func != NULL; i++)
	{
		if (strcmp(opcode, op_struct[i].op_func) == 0)
			return (op_struct[i].f);
	}

	return (NULL);
}

