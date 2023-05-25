#include "monty.h"
/**
  * push - function to push to stack
  * @head: head of the stack
  * @line: line_number of the argument
  */
void push(stack_t **head, unsigned int line)
{
	char *arg;
	int num;

	arg = strtok(NULL, " \n");
	if (isnum(arg) == 1 && arg != NULL)
	{
		num = atoi(arg);
	}
	else
	{
		fprintf(stderr, "L%d:usage:push integer\n", line);
		exit(EXIT_FAILURE);
	}
	add_dnodeint(head, num);
}

/**
  * pall - function to print the stack items
  * @head: head of the stack
  * @line: line_number of the argument
  */

void pall(stack_t **head, __attribute__ ((unused)) unsigned int line)
{
	stack_t *tmp;

	tmp = *head;
	while (tmp)
	{
		fprintf(stdout, "%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
  * pint - function to print the stack item on top only
  * @head: head of the stack
  * @line: line_number of the argument
  */

void pint(stack_t **head, unsigned int line)
{
	if(*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty", line);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", (*head)->n);
}
