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
		printf("%d\n", tmp->n);
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
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty", line);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
  * pop - function to remove the top element of the stack
  * @head: head of the stack
  * @line: line_number of the argument
  */

void pop(stack_t **head, unsigned int line)
{
	stack_t *tmp = *head;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack", line);
		exit(EXIT_FAILURE);
	}
	*head = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = NULL;
	free(tmp);
}
/**
  * swap - function to swap two top element of the stack
  * @head: head of the stack
  * @line: line_number of the argument
  */

void swap(stack_t **head, unsigned int line)
{
	int len = dlistint_len(head);
	int tmp;

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short", line);
		exit(EXIT_FAILURE);
	}
	tmp = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = tmp;
}
