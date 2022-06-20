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
/**
 * pint - opcode that prints the value at the top of the stack.
 * @stack: the stack to print
 * @line_number: the line number of the opcode
 *
 * Return: Nothing.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * pop - opcode that removes the top element of the stack
 * @stack: the stack to print
 * @line_number: the line number of the opcode
 *
 * Return: Nothing.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	delete_at_index(stack, 0);
}
/**
 * swap - opcode that swaps the top two elements of the stack
 * @stack: the stack to print
 * @line_number: the line number of the opcode
 *
 * Return: Nothing.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (list_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = ((*stack)->next)->n;
	((*stack)->next)->n = temp;
}
