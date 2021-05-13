#include "monty.h"
/**
 * add_q - Adds a new node at the end of a list
 * @head: pointer to the address of the head node
 * @n: Value of the new node
 *
 * Return: Address of the new element or NULL if it failed
 */

void add_q(stack_t **head, unsigned int line_number)
{
	stack_t *newNode;
	stack_t *temp;

	newNode = (stack_t *)malloc(sizeof(stack_t));

	if (newNode == NULL)
		return (NULL);
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

}
