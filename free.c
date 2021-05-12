#include "monty.h"
/**
 * free_stack_t - frees the stack_t
 * @head: head to the stack list
 *
 * Return: NULL
 */
void free_stack_t(stack_t *head)
{
	stack_t *current;

	while (head != NULL)
	{
		current = head;
		head = head->next;
		free(current);
	}
}

/**
 * free_stuff - frees all relevant memory blocks
 * @fp: pointer to a file stream
 * @head: pointer to funcs_t head node
 * @line: pointer to char array
 *
 * Return: no return value (void)
 */

void free_stuff(FILE *fp, stack_t *head, char *line)
{
	fclose(fp);
	if (head)
		free_stack_t(head);
	free(line);
}
