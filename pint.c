#include "monty.h"

/**
 * pint - prints the element at the top of the stack
 * @head: double pointer to the head node of the stack
 * @line_number: line number of instruction in the file being read
 *
 * Return: no return value (void)
 */
void pint(stack_t **head, unsigned int line_number)
{
	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n",
			line_number);
		int_arg = -1;
		return;
	}
	printf("%d\n", (*head)->n);
}
