#include "monty.h"

/**
 * main - interpreter for monty byte code
 * @argc: number of arguments to main
 * @argv: double pointer to arguments
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	FILE *fp;
	stack_t *head;
	char *line = NULL, *command = NULL, *arg = NULL, *endptr = NULL;
	size_t size;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &size, fp) != -1)
	{
		line_number++;
		command = strtok(line, " ");
		arg = strchr(command, '\n');
		if (arg)
			*arg = 0;
		arg = NULL;
		arg = strtok(NULL, " ");
		if (get_func(command) == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, command);
			free_stuff(fp, head, line);
			exit(EXIT_FAILURE);
		}
		if (strcmp(command, "push") == 0)
		{
			if (arg)
				int_arg = strtol(arg, &endptr, 10);
			if ((arg == NULL || endptr == arg))
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				free_stuff(fp, head, line);
				exit(EXIT_FAILURE);
			}
		}
		get_func(command)(&head, line_number);
	}
/*		workhorse(fp, headptr, line);*/
	if (!feof(fp))
	{
		free_stuff(fp, head, line);
		fprintf(stderr, "Error reading line %d\n", line_number + 1);
		exit(EXIT_FAILURE);
	}
	free_stuff(fp, head, line);
	return (0);
}
