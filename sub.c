#include "monty.h"
/**
  *f_sub- sustration
  *@head: stack head
  *@counter: line_number
  *Return: no return
 */
void f_sub(stack_t **head, unsigned int counter)
{
	stack_t *aux;
	int sus, nodes;

	aux = *head;
	for (nodes = 0; aux != NULL; nodes++)
		aux = aux->next;
	if (nodes < 2)
	{
	fprintf(stderr, "L%u: can't SUB, stack too short\n", counter);
	fclose(bus.file);
	free(bus.content);
	free_stack(*head);
	exit(EXIT_FAILURE);
	}
	sus = (*head)->next->n - (*head)->n;
	(*head)->next->n = sus;
	*head = (*head)->next;
	(*head)->prev = NULL;
	free(aux);
}