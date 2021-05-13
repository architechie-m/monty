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
	char *line = NULL, *command = NULL, *arg = NULL;
	int status = -1;
	size_t size;
	unsigned int line_number = 0, staqueue = 0, temp = 0;

	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	fp = open_file(argv[1]);
	while (getline(&line, &size, fp) != -1)
	{
		line_number++, command = strtok(line, " \n"), arg = strtok(NULL, " ");
		if (strcmp(line, "\n") == 0)
			continue;
		if (strcmp(command, "push") == 0)
			push_handler(arg, line, fp, head, line_number),
				temp = line_number, line_number = staqueue, status = 0;
		if (strcmp(command, "stack") == 0)
		{
			staqueue = 0;
			continue;
		}
		if (strcmp(command, "queue") == 0)
		{
			staqueue = 1;
			continue;
		}
		if (check_opcode(command, line_number) == 0)
			get_func(command)(&head, line_number);
		if (int_arg == -1)
			free_stuff(fp, head, line), exit(EXIT_FAILURE);
		if (status != -1)
			line_number = temp, status = -1;
	}
	if (!feof(fp))
		fprintf(stderr, "Error reading line %d\n", line_number + 1),
			free_stuff(fp, head, line), exit(EXIT_FAILURE);
	free_stuff(fp, head, line);
	return (0);
}


void push_handler(char *arg, char *line, FILE *fp, stack_t *head,
		  unsigned int line_number)
{
	char *e = NULL;

	if (arg)
		int_arg = strtol(arg, &e, 10);
	if (arg == NULL || arg == e)
		fprintf(stderr, "L%d: usage: push integer\n", line_number),
			free_stuff(fp, head, line), exit(EXIT_FAILURE);
}
