#include "monty.h"

/**
 * pall_stack - prints all elements in a list
 * @head: double pointer to the head node
 * @line_number: line number of instruction in the file
 *
 * Return: returns the number of elements in a node
 */

void pall_stack(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;
	(void)line_number;

	if (head == NULL || (*head) == NULL)
		return;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
