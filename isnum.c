#include "monty.h"

/**
  * isnum- function to check if string can be convirted to int
  * @str: inout string
  * Return: 1 if sucess 0 if not
  */

int isnum(char *str)
{
	int i = 0;

	if (str == NULL)
	{
		return (0);
	}
	while (str[i])
	{
		if (str[0] == '-')
		{
			i++;
			continue;
		}
		if (!isdigit(str[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
