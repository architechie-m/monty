#include "monty.h"
/**
 * my_print - print corresponding char representation for non-printable chars
 * @ch: ASCII value of non_printable char
 *
 * Return: no return value (void)
 */
void my_print(int ch)
{
	int chrs[33] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,
			22,23,24,25,26,27,28,29,30,31, 127};
	char *pr[33] = {"NUL", "SOH", "STX", "ETX", "EOT", "ENQ", "ACK", "BEL",
			"BS", "HT", "LF", "VT", "FF", "CR", "SO", "SI", "DLE",
			"DC1", "DC2", "DC3", "DC4", "NAK", "SYN", "ETB", "CAN",
			"EM", "SUB", "ESC", "FS", "GS", "RS", "US", "DEL"};
	int i = 0;

	for (i = 0; i <= 31; i++)
	{
		if (ch == chrs[i])
		{
			printf("%s\n", pr[i]);
			break;
		}
	}
}

/**
 * pchar_stack - prints the char at the top of the stack
 * @head: double pointer to head node of stack
 * @line_number: line number of instruction in the file
 *
 * Return: no return value
 */
void pchar_stack(stack_t **head, unsigned int line_number)
{
	if (head == NULL || (*head) == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n",
			line_number);
		int_arg = -1;
		return;
	}
	if ((*head)->n < 0 || (*head)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n",
			line_number);
		int_arg = -1;
		return;
	}
	if ((*head)->n <= 31 || (*head)->n == 127)
		my_print((*head)->n);
	else
		printf("%c\n", (*head)->n);
}
