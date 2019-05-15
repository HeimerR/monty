#include "monty.h"
/**
 * f_pall - prints the stack
 * @head: stack head
 * @counter: no used
 * Return: no return
*/
void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
/**
 * f_push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_push(stack_t **head, unsigned int counter)
{
	stack_t *new_node, *aux;
	int n, j, flag = 0;

	aux = *head;
	if (bus.arg)
	{
		if (bus.arg[0] == '0' && bus.arg[1] == '\0')
			n = 0;
		else
		{
			for (j = 0; bus.arg[j] != '\0'; j++)
			{
				if (bus.arg[j] > 57 || bus.arg[j] < 48)
					flag = 1;
			}
			n = (atoi(bus.arg));
			if (n == 0 || flag == 1)
			{ fprintf(stderr, "L%d: usage: push integer\n", counter);
				fclose(bus.file);
				free(bus.content);
				free_stack(*head);
				exit(EXIT_FAILURE); }
		}
	}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (aux)
		aux->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}
void f_pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		printf("L%u: can't pint, stack empty\n", counter);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
