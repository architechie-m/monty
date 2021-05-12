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

	if (head == NULL || *head == NULL || (*head)->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		ourdata.line_number = INT_MAX;
		return;
	}
	*head = (*head)->next;
	(*head)->next->prev = *head;

	temp->next = (*head)->next;
	(*head)->next->prev = temp;
	(*head)->next = temp;
	temp->prev = *head;
	(*head)->prev = NULL;
}
