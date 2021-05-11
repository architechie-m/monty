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
 * funcs_init - 
 * @head: pointer to the head node
 * @n: value stored in the new node
 *
 * Return: Address of the new element, or NUll if it failed
 */

void funcs_init(funcs_t **headptr)
{
	char *str[] = {"push", "pall", "swap"};

	addnode_end(headptr, str[0], add_dnodeint);
	addnode_end(headptr, str[1], print_dlistint);
	addnode_end(headptr, str[2], swap);


}
funcs_t *addnode_end(funcs_t **head, char *str, void (*f)(stack_t **stack, unsigned int line_number))
{
	funcs_t *new = NULL, *temp;
	new = createnew();
	strcpy(new->n->opcode, str);
	new->n->f = f;
	if (*head == NULL)
	{
		*head = new;
	}
	else
	{
		temp = *head;
		while(temp->next != NULL)
			temp = temp->next;

		temp->next = new;
		new->prev = temp;
		temp = new;
	}
	return (temp);
}
