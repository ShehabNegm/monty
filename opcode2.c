#include "monty.h"
/**
  * add - function to add two top element of the stack to the 2nd element
  * @head: head of the stack
  * @line: line_number of the argument
  */

void add(stack_t **head, unsigned int line)
{
	int len = dlistint_len(head);
	int sum;
	stack_t *tmp = *head;

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short", line);
		exit(EXIT_FAILURE);
	}
	sum = (*head)->n + (*head)->next->n;
	(*head)->next->n = sum;

	*head = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = NULL;
	free(tmp);
}

/**
  * nop - function doesn't do anything
  * @head: head of the stack
  * @line: line_number of the argument
  */

void nop(__attribute__ ((unused))stack_t **head,
		__attribute__ ((unused))unsigned int line)
{
	;
}
