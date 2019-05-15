#include "monty.h"

/**
* check_val - executes the opcode
* @val: head linked list - stack
* Return: number converted
*/
int check_val(char *val)
{
	int n;

	if (val)
	{
		if (val[0] == '0' && val[1] == '\0')
		{
			return (0);
		}
		else
		{
			n = (atoi(val));
			if (n == 0)
				return (1);
		}
	}
	return (0);
}
/**
* execute - executes the opcode
* @stack: head linked list - stack
* @bus: carries variables
* @file: poiner to monty file
* @content: line content
* Return: no return
*/
int execute(char *content, stack_t **stack, int bus[], FILE *file)
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
	if (check_val(val) == 1)
		val = NULL;
	if (check_val(val) == 0 && val)
		number = atoi(val);
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{
			if (!val && i == 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n", bus[0]);
				bus[1] = 1;
				break;
			}
			opst[i].f(stack, number);
			return (0);
		}
		i++;
	}
	if (op && i == 2)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", bus[0], op);
		bus[1] = 1; }
	if (bus[1] == 1)
	{ fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
