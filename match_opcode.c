#include "monty.h"
/**
  * match_opcode - function to match opcode with its function
  * @args: opcode and its argument as an array
  * Return: matched function
  */
func match_opcode(char *args)
{
	int i = 0;
	instruction_t opcode_f[] = {
		{"push", push},
		{"pall", pall},
		/*{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},*/
		{NULL, NULL}};

	while (opcode_f[i].opcode != NULL && strcmp(opcode_f[i].opcode, args) != 0)
	{
		i++;
	}
	return (opcode_f[i].f);
}
