#include "monty.h"

void swap(stack_t **head, __attribute__((unused))unsigned int line_number)
{
	stack_t *temp = *head;
	if (head == NULL ||*head == NULL || (*head)->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}


	*head = (*head)->next;
	(*head)->next->prev = *head;

	temp->next = (*head)->next;
	(*head)->next->prev = temp;
	(*head)->next = temp;
	temp->prev = *head;
	(*head)->prev = NULL;

}
