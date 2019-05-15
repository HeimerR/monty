#include "monty.h"
/**
 * f_pall - prints the stack
 * @head: stack head
 * @number: no used
 * Return: no return
*/
void f_pall(stack_t **head, unsigned int number)
{
	stack_t *h;
	(void)number;

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
 * @number: value to store
 * Return: no return
*/
void f_push(stack_t **head, unsigned int number)
{

	stack_t *new_node;
	stack_t *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (aux)
		aux->prev = new_node;
	new_node->n = number;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}
