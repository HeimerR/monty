#include "monty.h"
/**
* execute - executes the opcode
* @stack: head linked list - stack
* @content: line content
* Return: no return
*/
int execute(char *content, stack_t **stack, int bus[])
{
	instruction_t opst[] = {
				{"push", f_push},
				{"pall", f_pall},
				{NULL, NULL}
				};
	unsigned int i = 0, number = 0;
	char *op, *val;

	bus[1] = 0;
	op = strtok(content, " \n");
	val = strtok(NULL, " \n");
	if (val)
	{
		if (val[0] == '0' && val [1] == '\0')
		{
			number = 0;
		}
		else
		{
			number = atoi(val);
			if (number == 0)
				bus[1] = 1;
		}
	}
	else
		bus[1] = 1;
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{
			opst[i].f(stack, number);
			return (0);
		}
		i++;
	}
	if (op)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", bus[0], op);
		exit(EXIT_FAILURE);
	}
	return (1);
}
