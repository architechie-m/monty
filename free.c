#include "monty.h"

/**
 * free_funcs_t - Frees a list
 * @head: Address of the head node to funcs_t
 *
 * Return: Void
 */

void free_funcs_t(funcs_t *head)
{
	funcs_t *current;

	while (head)
	{
		current = head;
		head = head->next;
		free(current->n->opcode);
		free(current->n);
		free(current);
	}
}

/**
 * free_stack_t - frees the stack_t
 * @head: head to the stack list
 *
 * Return: NULL
 */
void free_stack_t(stack_t *head)
{
	stack_t *current;

	while (head)
	{
		current = head;
		head = head->next;
		free(current);
	}
}

/**
 * free_stuff - frees all relevant memory blocks
 * @fp: pointer to a file stream
 * @headptr: pointer to funcs_t head node
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
