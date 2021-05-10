#include "monty.h"

/**
 * print_dlistint - prints all elements in a list
 * @h: pointer to the head node
 *
 * Return: returns the number of elements in a node
 */

void print_dlistint(stack_t **h, unsigned int line_number)
{
	stack_t *current = *h;
	size_t count = 0;
	(void)line_number;

	printf("Printing list...\n");
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
		count++;
	}
}
