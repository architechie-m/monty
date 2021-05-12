#include "monty.h"

/**
 * push_stack - Adds a new node at the beginning of a list
 * @head: pointer to the head node
 * @number: value stored in the new node
 *
 * Return: Address of the new element, or NUll if it failed
 */

void push_stack(stack_t **head, unsigned int line_number)
{
	stack_t *newNode;
	(void)line_number;

	newNode = (stack_t *)malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newNode->n = int_arg;
	newNode->next = NULL;
	newNode->prev = NULL;

	if (*head == NULL)
		*head = newNode;
	else
	{
		newNode->next = *head;
		(*head)->prev = newNode;
		*head = newNode;
	}
	printf("Done\n");
}
