#include "monty.h"
/**
  * str_handler - function to handle string in a line of the file
  * handling the line by splitting it and remove spaces
  * @buf: the line of the file pointer to string
  * Return: opcode and its argument
  */
char *str_handler(char *buf)
{
	const char *delim = " \t\r\a\n";
	char *token;

	token = strtok(buf, delim);
	if (token == NULL)
		return (NULL);
	return (token);
}
