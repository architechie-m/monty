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
	stack_t *head = NULL;
	unsigned int line_no = 0, int_arg = 0, ops = 0, status = 0;
	char *line = NULL, *command = NULL, *arg = NULL;
	size_t size;
	funcs_t *headptr = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	funcs[0]->opcode = malloc(sizeof(char) * 5);
	strcpy(funcs[0]->opcode, "push");
	funcs[0]->f = add_dnodeint;
	funcs[1]->opcode = malloc(sizeof(char) * 5);
	strcpy(funcs[1]->opcode, "pall");
	funcs[1]->f = print_dlistint;

	printf("Opening file...\n");
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &size, fp) != -1)
	{
		line_no++;
		command = strtok(line, " ");
		arg = strtok(NULL, " ");
		printf("Command: %s, argument: %s\n", command, arg);
		for (ops = 0; ops < 2; ops++)
		{
	  		if (strcmp(command, funcs[ops]->opcode) == 0)
			{
				int_arg = atoi(arg);
				funcs[ops]->f(&head, int_arg);
				status = 1;
				break;
			}
		}
		if (status == 0)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n",
line_no, command);
			exit(EXIT_FAILURE);
		}
	}
	if (!feof(fp))
	{
		fprintf(stderr, "Error reading line %d\n", line_no + 1);
		exit(EXIT_FAILURE);
	}
	return (0);
}
