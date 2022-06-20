#include "monty.h"
/**
* add - opcode that adds the top two elements of the stack
* @stack: the stack to print
* @line_number: the line number of the opcode
*
* Return: Nothing.
*/
void add(stack_t **stack, unsigned int line_number)
{
	if (list_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	((*stack)->next)->n += (*stack)->n;
	delete_at_index(stack, 0);
}
/**
* nop - doesn't do anything
* @stack: the stack to print
* @line_number: the line number of the opcode
*
* Return: Nothing.
*/
void nop(stack_t **stack, unsigned int line_number)
{
	if (*stack)
		line_number += 0;
}
/**
* sub - opcode that subtracts the top two elements of the stack
* @stack: the stack to print
* @line_number: the line number of the opcode
*
* Return: Nothing.
*/
void sub(stack_t **stack, unsigned int line_number)
{
	if (list_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	((*stack)->next)->n -= (*stack)->n;
	delete_at_index(stack, 0);
}
/**
* divide - opcode that divides the top two elements of the stack
* @stack: the stack to print
* @line_number: the line number of the opcode
*
* Return: Nothing.
*/
void divide(stack_t **stack, unsigned int line_number)
{
	if (list_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{

		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	((*stack)->next)->n /= (*stack)->n;
	delete_at_index(stack, 0);
}
/**
* mul - opcode that multiplies the top two elements of the stack
* @stack: the stack to print
* @line_number: the line number of the opcode
*
* Return: Nothing.
*/
void mul(stack_t **stack, unsigned int line_number)
{
	if (list_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	((*stack)->next)->n *= (*stack)->n;
	delete_at_index(stack, 0);
}
