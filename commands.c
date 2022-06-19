#include "monty.h"
/**
 * push - opcode to push an item unto the stack.
 * @stack: the stack to push to
 * @line_number: the line number of the opcode.
 *
 * Return: Nothing.
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *res;
	const int arg = global_arg;

	if (global_arg != -1)
	{
		res = add_dnodeint(stack, arg);
		if (res == NULL)
			exit(EXIT_FAILURE);
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * pall - opcode to print the content of the stack
 * @stack: the stack to print
 * @line_number: the line number of the opcode
 *
 * Return: nothing.
*/
void pall(stack_t **stack, unsigned int line_number)
{
	print_list(*stack);
	line_number += 0;
}
