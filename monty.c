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
	FILE *fp = NULL;
	stack_t *head = NULL;
	char *line = NULL, *command = NULL, *arg = NULL, *e = NULL;
	size_t size = 0;
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
		command = strtok(line, " \n");
		arg = strtok(NULL, " ");
		printf("Command: %s, Argument = %s\n", command, arg);
		if (get_func(command) == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, command);
			free_stuff(fp, head, line);
			exit(EXIT_FAILURE);
		}
		if (strcmp(command, "push") == 0)
		{
			if (arg)
				int_arg = strtol(arg, &e, 10);
			if (arg == NULL || arg == e)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				free_stuff(fp, head, line);
				exit(EXIT_FAILURE);
			}
		}
		get_func(command)(&head, line_number);
	}
	if (!feof(fp))
	{
		free_stuff(fp, head, line);
		fprintf(stderr, "Error reading line %d\n", line_number + 1);
		exit(EXIT_FAILURE);
	}
	printf("Monty's tired\n");
	free_stuff(fp, head, line);
	return (0);
}
