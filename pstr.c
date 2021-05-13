#include "monty.h"

/**
 * pstr_stack - print a string using stack elements from the top
 * @head: double pointer to head node of stack
 * @line_number: line number of instruction in the file being read
 *
 * Return: no return value (void)
 */
void pstr_stack(stack_t **head, unsigned int line_number)
{
	stack_t *temp = *head;
	(void)line_number;

	if (head == NULL || (*head) == NULL)
	{
		printf("\n");
		return;
	}
	while (temp)
	{
		if (temp->n == 0)
		{
			int_arg = 0;
			return;
		}
		else if (temp->n <= 127 && temp->n >= 1)
		{
			printf("%c", temp->n);
			if (temp->next->n == 0)
				printf("\n");
		}
		else
		{
			fprintf(stderr, "L%d: can't pchar, value out of range\n"
				, line_number);
			int_arg = -1;
			return;
		}
		temp = temp->next;
	}
	printf("\n");
}
