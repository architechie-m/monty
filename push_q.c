#include "monty.h"
/**
 * push_queue - Adds a new node at the end of a list
 * @head: pointer to the address of the head node
 * @line_number: Value of the new node
 *
 * Return: Address of the new element or NULL if it failed
 */

void push_queue(stack_t **head, unsigned int line_number)
{
	stack_t *newNode;
	stack_t *temp;
	(void)line_number;

	newNode = (stack_t *)malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		int_arg = -1;
		return;
	}

	newNode->n = int_arg;
	newNode->next = NULL;
	newNode->prev = NULL;

	if (*head == NULL)
	{
		*head = newNode;
	}
	else
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;

		temp->next = newNode;
		newNode->prev = temp;
		temp = newNode;
	}
	int_arg = 0;
}
