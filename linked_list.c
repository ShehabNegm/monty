#include "monty.h"
/**
  * add_dnodeint - function to insert element at the head of d linked list
  * @head: header of the doubly linked list
  * @line: line at the opcode
  * Return: will return the new head;
  */

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->prev = NULL;
	new->next = *head;

	if (*head != NULL)
		(*head)->prev = new;

	*head = new;

	return (new);
}
/**
  * print_dlistint - function to print elements of d linked list
  * @h: header of the doubly linked list
  */

void print_dlistint(stack_t **h)
{
	stack_t *tmp = *h;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
