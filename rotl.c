#include "monty.h"

/**
 * rotl_stack - rotates the stack to top
 * @head: double pointer to head node of stack
 * @line_number: line number of instruction in file being read
 *
 * Description: Top stack element becomes last, 2nd top element becomes 1st
 *
 * Return: no return value (void)
 */
void rotl_stack(stack_t **head, unsigned int line_number)
{
	stack_t *temp = *head, *new = NULL;
	int temp1 = 0;

	if (temp == NULL)
		return;
	if (temp->next->next == NULL)
		swap(head, line_number);
	temp1 = temp->n;
	pop_stack(head, line_number);
	temp = *head;
	while (temp->next)
		temp = temp->next;
	new = malloc(sizeof(stack_t *));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		int_arg = -1;
		return;
	}
	new->n = temp1;
	temp->next = new;
	new->prev = temp;
	new->next = NULL;
}
