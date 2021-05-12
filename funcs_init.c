#include "monty.h"

/**
 * createnew - creates a new node
 *
 * Return: Address of the new node
 */
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
 * funcs_init - Initiliases a node
 * @headptr: pointer to the head node
 *
 * Return: Void
 */
void funcs_init(funcs_t **headptr)
{
	addnode_end(headptr, "push", push_stack);
	addnode_end(headptr, "pall", print_dlistint);
	addnode_end(headptr, "pint", pint);
	addnode_end(headptr, "pop", pop_stack);
	addnode_end(headptr, "swap", swap);
	addnode_end(headptr, "add", add_node);
	addnode_end(headptr, "sub", sub_node);
	addnode_end(headptr, "nop", nop);
}

/**
 * addnode_end - adds a node at the end of the list
 * @headptr2: head address of the linked list
 * @str: opcode contained in the monty file
 * @f: function pointer to point to addresses of different opcode instructions
 *
 * Return: void
 */
void addnode_end(funcs_t **headptr2,
char *str, void (*f)(stack_t **stack, unsigned int line_number))
{
	funcs_t *new = NULL, *temp;

	new = createnew();
	strcpy(new->n->opcode, str);
	new->n->f = f;
	if (*headptr2 == NULL)
	{
		*headptr2 = new;
	}
	else
	{
		temp = *headptr2;
		while (temp->next != NULL)
			temp = temp->next;

		temp->next = new;
		new->prev = temp;
		temp = new;
	}
}
