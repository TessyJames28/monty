#include "monty.h"


/**
 * monty_mod - computes the rest of the div of top second and first elements
 * @stack: head pointer of the stack
 * @line_num: line number for the file
 * Return: nothing
 */
void monty_mod(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by 0\n", line_num);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n %= (*stack)->n;
	monty_pop(stack, line_num);
}



/**
 * monty_pchar - prints the ascii value of the char at the top of the stack
 * @stack: head pointer of the stack
 * @line_num: line number for the file
 * Return: nothing
 */
void monty_pchar(stack_t **stack, unsigned int line_num)
{
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n",
				line_num);
		exit(EXIT_FAILURE);
	}
	if (!(*stack))
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

/**
 * monty_stack - function that checks if the stack is in stack mode
 * @stack: head pointer of the stack
 * @line_num: line number of the file
 * Return: nothing
 */
void monty_stack(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
	bus.lifi = 0;
}


/**
 * monty_pstr - prints the ascii val of string starting at the top of the stack
 * @stack: head pointer of the stack
 * @line_num: line number of the file
 * Return: nothing
 */
void monty_pstr(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = *stack;

	while (temp)
	{
		if (temp->n == 0)
			break;
		if (temp->n > 127 || temp->n < 0)
			break;
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
	(void)line_num;
}


/**
 * monty_rotl - rotates the stack to the top
 * @stack: head pointer of the stack
 * @line_num: line number of the file
 * Return: nothing
 */
void monty_rotl(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	while (temp->next != 0)
		temp = temp->next;

	temp->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	temp->next->next->prev = temp;
	temp->next->next = NULL;

	(void)line_num;
}
