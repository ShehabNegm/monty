#include "monty.h"
/**
  * str_handler - function to handle string in a line of the file
  * handling the line by splitting it and remove spaces
  * @buf: the line of the file pointer to string
  * @line_number: line number at the file
  */
void str_handler(char *buf, unsigned int line_number)
{
	const char *delim = " \t\r\a\n";
	char *token;
	int token_count = 0;
	char **opcode = NULL;
	(void) line_number;

	opcode = malloc(sizeof(char *) * 64);
	if (opcode == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}


	token = strtok(buf, delim);
	while (token)
	{
		opcode[token_count] = token;
		token = strtok(NULL, delim);
		token_count++;
	}
	if (opcode[1] == NULL)
		opcode[1] = "\0";



	printf("%s\n", opcode[0]);
	printf("%s\n", opcode[1]);
}
