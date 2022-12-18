#include "monty.h"

/**
 * monty_add - function that adds the top two elements of the stack
 * @stack: head pointer of the stack
 * @line_num: line number for the file
 * Return: nothing
 */
void monty_add(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL || (*stack)->next == NULL)
		add_err(line_num);

	(*stack)->next->n += (*stack)->n;
	monty_pop(stack, line_num);
}


/**
 * monty_nop - function that does nothing
 * @stack: head pointer of the stack
 * @line_num: line number for the file
 * Return: nothing
 */
void monty_nop(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
}


/**
 * monty_sub - function that substract the top elment from the second element
 * @stack: head pointer of the stack
 * @line_num: line number for the file
 * Return: nothing
 */
void monty_sub(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL || (*stack)->next == NULL)
		sub_err(line_num);

	(*stack)->next->n -= (*stack)->n;
	monty_pop(stack, line_num);
}


/**
 * monty_div - divides the second top element with the top element of the stack
 * @stack: head pointer of the stack
 * @line_num: line number for the file
 * Return: nothing
 */
void monty_div(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by 0\n", line_num);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n /= (*stack)->n;
	monty_pop(stack, line_num);
}


/**
 * monty_mul - multiplies the second top element with the top element
 * @stack: head pointer of the stack
 * @line_num: line number for the file
 * Return: nothing
 */
void monty_mul(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	monty_pop(stack, line_num);
}
