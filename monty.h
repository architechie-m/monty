#ifndef MONTY_H
#define MONTY_H

/*Header files*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <ctype.h>

/*Struct definitions*/
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/*Variable definition*/
extern int int_arg;
int int_arg;

/*Function prototypes*/
void push_stack(stack_t **head, unsigned int line_number);
void pall_stack(stack_t **h, unsigned int line_number);
void swap(stack_t **head, unsigned int line_number);
void free_stack_t(stack_t *head);
void pop_stack(stack_t **head, unsigned int line_number);
void pint(stack_t **head, unsigned int line_number);
void add_node(stack_t **head, unsigned int line_number);
void sub_node(stack_t **head, unsigned int line_number);
void nop(stack_t **head, unsigned int line_number);
void free_stuff(FILE *fp, stack_t *head, char *line);
void (*get_func(char *s))(stack_t **head, unsigned int line_number);
int check_opcode(char *command, unsigned int line_number);
FILE *open_file(char *filename);
void my_print(int ch);
void divide(stack_t **head, unsigned int line_number);
void multiply(stack_t **head, unsigned int line_number);
void modulus(stack_t **head, unsigned int line_number);
void pchar_stack(stack_t **head, unsigned int line_number);
void pstr_stack(stack_t **head, unsigned int line_number);
void rotl_stack(stack_t **head, unsigned int line_number);
void rotr_stack(stack_t **head, unsigned int line_number);
void add_q(stack_t **head, unsigned int line_number);
#endif /* MONTY_H */
