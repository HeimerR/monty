#include "monty.h"
/**
* execute - executes the opcode
* @stack: head linked list - stack
* @content: line content
* Return: no return
*/
int execute(char *content, stack_t **stack, int line_count)
{
	instruction_t opst[] = {
				{"push", f_push},
				{"pall", f_pall},
				{NULL, NULL}
				};
	unsigned int i = 0, number;
	char *op, *val;


	op = strtok(content, " \n");
	val = strtok(NULL, " \n"); 
	if (val)
		number = atoi(val);
	else
		number = 0;
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
		fprintf(stderr, "L%d: unknown instruction %s\n", line_count, op);
		exit(EXIT_FAILURE);
	}
	return (1);
}
