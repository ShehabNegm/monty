#include "monty.h"
/**
  * add_dnodeint - function to insert element at the head of d linked list
  * @head: header of the doubly linked list
  * @n: int to be inserted
  * Return: will return the new head;
  */

stack_t *add_dnodeint(stack_t **head, int n)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
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
  * dlistint_len - function to return length of d linked list
  * @h: header of the doubly linked list
  * Return: will return length of the list
  */

int dlistint_len(stack_t **h)
{
	int length = 0;
	stack_t *tmp = *h;

	while (tmp != NULL)
	{
		length++;
		tmp = tmp->next;
	}
	return (length);
}
/**
  * free_dlistint - function to free memorry allocated of d linked listes
  * @head: header of the doubly linked list
  */

void free_dlistint(stack_t *head)
{
	stack_t *tmp = head;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(head);
}
