#include "monty.h"
/*
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
/*

*/
void pall(stack_t **stack, unsigned int line_number)
{
	print_list(*stack);
}
