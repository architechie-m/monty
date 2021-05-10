#include "monty.h"

funcs_t *createnew(void)
{
        funcs_t *newNode = NULL;

	/*memory allocation for the funcs_t node*/
        newNode = (funcs_t *)malloc(sizeof(funcs_t));
        if (newNode == NULL)
        {
                fprintf(stderr, "Error: malloc failed\n");
                exit(EXIT_FAILURE);
        }
	/*memory allocation for the instruction_t struct (*n) in the node)*/
	newNode->n = malloc(sizeof(instruction_t));
	if (newNode->n == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	/*memory allocation for the char array*/
	newNode->n->opcode = malloc(sizeof(char) * 5);
	if (newNode->n->opcode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
        newNode->next = NULL;
        newNode->prev = NULL;

	return (newNode);
}

/**
 * stack_t - Adds a new node at the beginning of a list
 * @head: pointer to the head node
 * @n: value stored in the new node
 *
 * Return: Address of the new element, or NUll if it failed
 */

void funcs_init(funcs_t **headptr)
{
	funcs_t *new = NULL, *tmp = NULL;

	/*Create first node*/
	new = createnew();
	strcpy(new->n->opcode, "push");
	new->n->f = add_dnodeint;
	*headptr = new;
	tmp = new;
	new = createnew();
	strcpy(new->n->opcode, "pall");
	new->n->f = print_dlistint;
	tmp->next = new;
	new->prev = tmp;
}
