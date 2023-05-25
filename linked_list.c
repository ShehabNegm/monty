#include "monty.h"
/**
  * add_dnodeint - function to insert element at the head of d linked list
  * @head: header of the doubly linked list
  * @n: int to be inserted
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
