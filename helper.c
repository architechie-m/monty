#include "monty.h"
/**
 * check_opcode - checks the opcode is present
 * @command: the opcode
 * @line_number: line number of the command
 * Return: -1 on failure and 0(zero) upon sucess
 */

int check_opcode(char *command, unsigned int line_number)
{
	if (get_func(command) == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n",
			line_number, command);
		int_arg = -1;
		return (-1);
	}
	return (0);
}


/**
 * open_file - opens file containing the command
 * @file_name: name of the file to be opened
 *
 * Return:  void
 */

FILE *open_file(char *file_name)
{
	FILE *fp;

	fp = fopen(file_name, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	return (fp);
}
