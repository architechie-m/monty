#include "monty.h"

/**
 * modulus - Divide 2nd top stack element by the top element
 * @head: double pointer to stack head node
 * @line_number: line number of instruction in the file
 *
 * Return: no return value (void)
 */
void modulus(stack_t **head, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n",
			line_number);
		int_arg = -1;
		return;
	}
	current = *head;
	if (current->n != 0)
	{
		res = current->next->n % current->n;
	}
	else
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		int_arg = -1;
		return;
	}
	pop_stack(head, line_number);
	pop_stack(head, line_number);
	int_arg = res;
	push_stack(head, line_number);
}
