#include "monty.h"

/**
 * monty_push - add node to the stack
 * @stack: stack head
 * @line_num: line_number
 * Return: no return
*/
void monty_push(stack_t **stack, unsigned int line_num)
{
	int n, j = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			j++;
		for (; bus.arg[j] != '\0'; j++)
		{
			if (bus.arg[j] > 57 || bus.arg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{	fclose(bus.file);
			free(bus.content);
			free_stack(*stack);
			push_err(line_num);
		}
	}
	else
	{	fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		push_err(line_num);
	}

	n = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(stack, n);
	else
		addqueue(stack, n);
}


/**
 * monty_pall - function that prints opcode element on the stack from top down
 * @stack: the stack
 * @line_num: opcode line number
 * Return: nothing
 */
void monty_pall(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = *stack;

	while (temp != 0)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	(void)line_num;
}


/**
 * monty_pint - function that prints opcode element at the top of the stack
 * @stack: the stack
 * @line_num: opcode line number
 * Return: nothing
 */
void monty_pint(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL)
		pint_err(line_num);

	printf("%d\n", (*stack)->n);
}


/**
 * monty_pop - function that remove the top opcode element on the stack
 * @stack: the stack head
 * @line_num: opcode line number
 * Return: nothing
 */
void monty_pop(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
		pop_err(line_num);

	*stack = (*stack)->next;
	free(temp);
}


/**
 * monty_swap - function that swaps the top two element of the stack
 * @stack: the stack
 * @line_num: opcode line number
 * Return: nothing
 */
void monty_swap(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
		swap_err(line_num);

	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	temp->next = (*stack)->next;
	temp->prev = *stack;
	(*stack)->next = temp;
	temp->next->prev = temp;
}
