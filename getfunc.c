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
                {"pint", NULL},
		{"pop", NULL},
		{"swap", NULL},
		{"add", NULL},
		{"nop", NULL},
		{NULL, NULL}
        };

        /** Loop through array and compare token to opcode */
        for (; op_struct[i].opcode != NULL; i++)
        {
                if (strcmp(opcode, op_struct[i].opcode) == 0)
                        return (op_struct[i].f);
        }
	return (NULL);
}
