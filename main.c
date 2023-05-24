#include "monty.h"

/**
  * main - function main as entry point for program
  * @ac: number of arguments passed
  * @av: arguments array
  * Return: 0 on success
  */

int main(int ac, char **av)
{
	FILE *f;
	unsigned int line = 0;
	char buf[1024];

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
		if (strcmp(buf, "\n") != 0)
			str_handler(buf, line);
	}
	return (0);
}

