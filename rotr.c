#include "monty.h"

/**
 * rotr_stack - rotate the stack to the bottom
 * @head: double pointer to head node of stack
 * @line_number: line number of instruction in file being read
 *
 * Description: Last element becomes 1st
 *
 * Return: no return value (void)
 */
void rotr_stack(stack_t **head, unsigned int line_number)
{
	stack_t *temp = *head;
	int temp1 = 0;

	if (temp == NULL)
		return;
	while (temp->next)
		temp = temp->next;
	temp1 = temp->n;
	temp->prev->next = NULL;
	free(temp);
	int_arg = temp1;
	push_stack(head, line_number);
}
