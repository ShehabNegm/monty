#include "monty.h"
/**
  * sub - function to sub two top element of the stack to the 2nd element
  * @head: head of the stack
  * @line: line_number of the argument
  */

void sub(stack_t **head, unsigned int line)
{
	int len = dlistint_len(head);
	int sb;
	stack_t *tmp = *head;

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	sb = (*head)->n - (*head)->next->n;
	(*head)->next->n = sb;

	*head = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = NULL;
	free(tmp);
}

/**
  * mul - function to mul two top element of the stack to the 2nd element
  * @head: head of the stack
  * @line: line_number of the argument
  */

void mul(stack_t **head, unsigned int line)
{
	int len = dlistint_len(head);
	int multi;
	stack_t *tmp = *head;

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	multi = (*head)->n * (*head)->next->n;
	(*head)->next->n = multi;

	*head = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = NULL;
	free(tmp);
}
/**
  * _div - function to div two top element of the stack to the 2nd element
  * @head: head of the stack
  * @line: line_number of the argument
  */

void _div(stack_t **head, unsigned int line)
{
	int len = dlistint_len(head);
	int dv;
	stack_t *tmp = *head;

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		exit(EXIT_FAILURE);
	}
	dv = (*head)->next->n / (*head)->n;
	(*head)->next->n = dv;

	*head = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = NULL;
	free(tmp);
}

/**
  * mod - function to modulo two top element of the stack to the 2nd element
  * @head: head of the stack
  * @line: line_number of the argument
  */

void mod(stack_t **head, unsigned int line)
{
	int len = dlistint_len(head);
	int md;
	stack_t *tmp = *head;

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		exit(EXIT_FAILURE);
	}
	md = (*head)->next->n % (*head)->n;
	(*head)->next->n = md;

	*head = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = NULL;
	free(tmp);
}
