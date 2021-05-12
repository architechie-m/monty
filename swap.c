#include "monty.h"

/**
 * swap - swap the top two elements on the stack
 * @head: double pointer to the head node of the stack
 * @line_number: line number of instruction in the file being read
 *
 * Return: no return value (void)
 */
void swap(stack_t **head, unsigned int line_number)
{
	stack_t *temp = *head;
	int temp1 = 0, temp2 = 0;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n",
			line_number);
		int_arg = -1;
		return;
	}
	temp1 = temp->n;
	temp2 = temp->next->n;
	pop_stack(head, line_number);
	pop_stack(head, line_number);
	int_arg = temp1;
	push_stack(head, line_number);
	int_arg = temp2;
	push_stack(head, line_number);
}
