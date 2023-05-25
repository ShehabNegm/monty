#include "monty.h"
/**
  * match_opcode - function to match opcode with its function
  * @args: opcode and its argument as an array
  * @line : line number that has the instruction
  * @head: head of the double linked list
  */
void match_opcode(char **args, unsigned int line, stack_t **head)
{
	int i, n;
	instruction_t opcode_f[] = {
		/*{"push", push},
		{"pall", push},
		{"pint", push},
		{"pop", push},
		{"swap", push},
		{"add", push},
		{"nop", push},*/
		{NULL, NULL}};

	if (strcmp(args[0], "push") == 0)
	{
		/*if(isalpha(args[1]) != 0)
		{
			fprintf(stderr, "L%d:usage: push integer\n", line);
			exit(EXIT_FAILURE);
		}
		if(args[1] && isalpha(args[1]) == 0)
		{
			n = atoi(args[1]);
		}*/
		n = atoi(args[1]);
		add_dnodeint(head, n);
	}
	else if (strcmp(args[0], "pall") == 0)
	{
		print_dlistint(head);
	}
	else
	{
		for (i = 0; opcode_f[i].opcode != NULL; i++)
		{
			if(opcode_f[i].opcode == args[0])
				opcode_f[i].f(head, line);
		}
	}
}
