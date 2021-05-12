#include "monty.h"

/**
 * pall_stack - prints all elements in a list
 * @h: double pointer to the head node
 * @line_number: line number of instruction in the file
 *
 * Return: returns the number of elements in a node
 */

void pall_stack(stack_t **h, unsigned int line_number)
{
	stack_t *current = *h;
	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
