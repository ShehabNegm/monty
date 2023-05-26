#include "monty.h"

/**
  * main - function main as entry point for program
  * @ac: number of arguments passed
  * @av: arguments array
  * Return: 0 on success
  */

int main(int ac, char **av)
{
	stack_t *head = NULL;
	FILE *f;
	unsigned int line = 0;
	char buf[1024];
	char *opcode;
	func op_f;

	if (ac != 2 || access(av[1], F_OK) != 0)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	f = fopen(av[1], "r");
	if (f == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(buf, 1024, f))
	{
		line++;
		opcode = str_handler(buf);
		if (opcode == NULL || opcode[0] == '#')
			continue;
		op_f = match_opcode(opcode);
		if (op_f == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line, opcode);
			exit(EXIT_FAILURE);
		}
		op_f(&head, line);
	}
	fclose(f);
	free_dlistint(head);
	return (0);
}
