#include "monty.h"

/**
 * check_staqueue - determines whether to call push_stack or push_queue
 * @head: double pointer to stack head node
 * @line_number: line number from of instruction in file being read
 *
 * Return: no return value (void)
 */
void check_staqueue(stack_t **head, unsigned int line_number)
{
	if (line_number == 0)
		push_stack(head, line_number);
	if (line_number == 1)
		push_queue(head, line_number);
}
