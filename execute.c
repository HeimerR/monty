#include "monty.h"
/**
* execute - executes the opcode
* @stack: head linked list - stack
* @content: line content
* Return: no return
*/
void execute(char *content, stack_t **stack)
{
	instruction_t opst[] = {
				{"push", f_push},
				{"pall", f_pall},
				{NULL, NULL}
				};
	unsigned int i = 0, j = 0, number;

	strtok
	
	/*	char op[5];
	char val[10];

	while (content[i] != ' ' && content[i] != '\n')
	{
		op[i] = content[i];
		i++;
	}
	op[i] = '\0';
	if (content[i] == '\n')
	{
		number = 0;
	}
	else
	{
		while (content[i] != '\n')
		{
			val[j++] = content[i++];
		}
	}
	val[j] = '\0';
	number = atoi(&val[0]);
	i = 0; */
	while (opst[i].opcode)
	{
		if (strcmp(&op[0], opst[i].opcode) == 0)
		{
			opst[i].f(stack, number);
		}
		i++;
	}
}
