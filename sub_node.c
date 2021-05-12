#include "monty.h"


void sub_node(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;
	int sub = 0, count = 0;

	while (current != NULL)
	{
		current = (current)->next;
		count++;
	}

	if (count < 2)
	{
		printf("L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	current = *head;
	sub = current->next->n - current->n;
	pop_stack(head, line_number);
	pop_stack(head, line_number);
	push_stack(head, sub);
}
