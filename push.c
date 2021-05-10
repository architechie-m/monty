#include "monty.h"
/**
 * stack_t - Adds a new node at the beginning of a list
 * @head: pointer to the head node
 * @n: value stored in the new node
 *
 * Return: Address of the new element, or NUll if it failed
 */

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *newNode;

	newNode = (stack_t *)malloc(sizeof(stack_t));
	if (newNode == NULL)
		return (NULL);

	newNode->n = n;
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

	return (*head);
}
