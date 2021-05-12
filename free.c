#include "monty.h"

/**
 * free_dlistint - Frees a list
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
		free (current);
	}
	printf("funcs_t freed successfully");
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
                free (current);
        }
	printf("stack_s freed successfully");
}
