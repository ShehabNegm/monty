#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef void (*func)(stack_t **stack, unsigned int line_number);
char *str_handler(char *buf);
int isnum(char *str);
func match_opcode(char *args);
void push(stack_t **head, unsigned int line);
void pall(stack_t **head, unsigned int line);
void pint(stack_t **head, unsigned int line);
void pop(stack_t **head, unsigned int line);
void swap(stack_t **head, unsigned int line);
void add(stack_t **head, unsigned int line);
void nop(stack_t **head, unsigned int line);
void sub(stack_t **head, unsigned int line);
void _div(stack_t **head, unsigned int line);
void mul(stack_t **head, unsigned int line);
void mod(stack_t **head, unsigned int line);

stack_t *add_dnodeint(stack_t **head, int n);
int dlistint_len(stack_t **h);
void free_dlistint(stack_t *head);


#endif
