#include "monty.h"

void add_node(stack_t **head, unsigned int line_number)
{
	int count = 0;
	while(*head != NULL)
	{
		*head =(*head)->next;
		count++;
	}
	if (count < 2)
	{
		printf("L%d: can't add, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	*head = (*head)->next;
	sum = (*head)->n + (*head)->prev->n;
	free((*head)->prev);
	(*head)->prev = NULL;

}
