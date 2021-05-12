#include "monty.h"

/**
 * multiply - Multiply top 2 stack elements
 * @head: double pointer to stack head node
 * @line_number: line number of instruction in the file
 *
 * Return: no return value (void)
 */
void multiply(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;
	int res = 0, count = 0;

	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n",
			line_number);
		int_arg = -1;
		return;
	}
	current = *head;
	res = current->n * current->next->n;
	pop_stack(head, line_number);
	pop_stack(head, line_number);
	int_arg = res;
	push_stack(head, line_number);
}
