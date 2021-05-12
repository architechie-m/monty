#include "monty.h"

/**
 * pop_stack - remove an element from the top of the stack
 * @head: double pointer to the head node of the stack
 * @line_number: line number of instruction in the file being read
 *
 * Return: no return value (void)
 */
void pop_stack(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (*head == NULL || head == NULL)
	{
		fprintf(stderr, "L%d: can't pop, stack empty\n",
			line_number);
		int_arg = -1;
		return;
	}

	temp = *head;
	*head = temp->next;
	if (*head != NULL)
		(*head)->prev = NULL;
	free(temp);
}
