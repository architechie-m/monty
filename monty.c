#include "monty.h"

struct data ourdata = {NULL, 0};

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
	char *line = NULL;
	size_t size;
	funcs_t *headptr = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	funcs_init(&headptr);
	print_funcst(&headptr, 0);
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		free_funcs_t(headptr);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &size, fp) != -1)
		workhorse(fp, headptr, line);
	if (!feof(fp))
	{
		free_stuff(fp, headptr, line);
		fprintf(stderr, "Error reading line %d\n",
ourdata.line_number + 1);
		exit(EXIT_FAILURE);
	}
	free_stuff(fp, headptr, line);
	return (0);
}
