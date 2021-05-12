#include "monty.h"


void sub_node(stack_t **head, unsigned int line_number)
{
	int sub, count = 0;
	while (*head != NULL)
	{
		*head = (*head)->next;
		count++;
	}

	if (count < 2)
	{
		printf("L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("initial value: %d\n", (*head)->n);
	(*head) = (*head)->next;
	sub = (*head)->n - (*head)->prev->n;

	(*head)->n = sub;
	free((*head)->prev);
	(*head)->prev = NULL;
	printf("final value: %d\n", (*head)->n);
}
