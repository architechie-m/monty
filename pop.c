#include "monty.h"


void pop_stack(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if(*head == NULL || head == NULL)
	{
		printf("L%d: can't pop an empty stack", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *head;
	*head = temp->next;
	if (*head != NULL)
		(*head)->prev = NULL;
	free(temp);
}
