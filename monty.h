#ifndef MONTY_H
#define MONTY_H

/*Header files*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

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

/**
 * struct funcs_s - doubly linked list representation of an instruction_t struct
 * @n: pointer to instruction_t struct
 * @prev: points to the previous funcs_t node
 * @next: points to the next funcs_t node
 *
 */
typedef struct funcs_s
{
        instruction_t *n;
        struct funcs_s *prev;
        struct funcs_s *next;
} funcs_t;

/*Variable definition*/
struct data {
	stack_t *head;
	unsigned int line_number;
};
extern struct data ourdata;

/*Function prototypes*/
void push_stack(stack_t **head, unsigned int line_number);
void print_dlistint(stack_t **h, unsigned int line_no);
void swap(stack_t **head, unsigned int line_number);
void funcs_init(funcs_t **headptr);
funcs_t *createnew(void);
void free_funcs_t(funcs_t *head);
void free_stack_t(stack_t *head);
void addnode_end(funcs_t **head, char *str, void (*)(stack_t **, unsigned int));
void pop_stack(stack_t **head, unsigned int line_number);
void pint(stack_t **head, unsigned int line_number);
void add_node(stack_t **head, unsigned int line_number);
void sub_node(stack_t **head, unsigned int line_number);
void print_funcst(funcs_t **h, unsigned int line_number);
void nop(stack_t **head, unsigned int line_number);
void free_stuff(FILE *fp, funcs_t *headptr, char *line);
void workhorse(FILE *fp, funcs_t *headptr, char *line);
void push_handler(funcs_t *headptr, funcs_t *tmp, char *command, char *endptr,
                  char *arg, char *line, FILE *fp);

#endif /* MONTY_H */
