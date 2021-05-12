#include "monty.h"

void pint(stack_t **head, unsigned int line_number)
{
	if (head == NULL || *head == NULL)
	{
		printf("L%d: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d", (*head)->n);
}
