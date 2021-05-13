#include "monty.h"

/**
 * pchar_stack - prints the char at the top of the stack
 * @head: double pointer to head node of stack
 * @line_number: line number of instruction in the file
 *
 * Return: no return value
 */
void pchar_stack(stack_t **head, unsigned int line_number)
{
	if (head == NULL || *(head) == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n",
			line_number);
		int_arg = -1;
		return;
	}
	if ((*head)->n < 0 || (*head)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n",
			line_number);
		int_arg = -1;
		return;
	}
	printf("%c\n", (*head)->n);
}
