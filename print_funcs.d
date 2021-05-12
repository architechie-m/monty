#include "monty.h"

/**
 * print_funcst - prints all elements in a list
 * @h: double pointer to the head node
 * @line_number: line number of instruction in the file being read
 *
 * Return: no return value (void)
 */
void print_funcst(funcs_t **h, unsigned int line_number)
{
	funcs_t *current = *h;
	size_t count = 0;
	(void)line_number;

	printf("Printing list...\n");
	while (current != NULL)
	{
		printf("%s\n", current->n->opcode);
		current = current->next;
		count++;
	}
}
