#include "monty.h"
/**
 * f_pint - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
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
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
/**
  *f_lifi- stack <-> queue
  *@option: 0 = stack, 1 = queue
  *@aux: pointer
  *@new_node: pointer
  *@head: pointer
  *Return: nothing
 */
void f_lifi(int option,stack_t *aux, stack_t *new_node, stack_t *head)
{
	if (option == 1)
	{
		if (aux)
			aux->prev = new_node;
		new_node->n = n;
		new_node->next = NULL;
		new_node->prev = *head;
		*head = new_node;
	}
	else
	{
		if (aux)
			aux->prev = new_node;
		new_node->n = n;
		new_node->next = *head;
		new_node->prev = NULL;
		*head = new_node;
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
	int n, j = 0, flag = 0;

	aux = *head;
	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			j++;
		for (; bus.arg[j] != '\0'; j++)
		{
			if (bus.arg[j] > 57 || bus.arg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(bus.arg);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
		if (bus.lifi == 1)
			f_lifi(1, aux, new_node, *head);
		else
			f_lifi(0, aux, new_node, *head);
	}
