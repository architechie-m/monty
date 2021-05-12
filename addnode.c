#include "monty.h"

/**
 * add_node - adds the top two stack elements
 * @head: double pointer to head of stack
 * @line_number: line number of command being run in the file
 *
 * Return: no return value void
 */
void add_node(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;
	int count = 0, sum = 0;

	while (current != NULL)
	{
		current = current->next;
		count++;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n",
			line_number);
		int_arg = -1;
		return;
	}
	current = *head;
	sum = current->n + current->next->n;
	pop_stack(head, line_number);
	pop_stack(head, line_number);
	int_arg = sum;
	push_stack(head, sum);
}
