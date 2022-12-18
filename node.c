#include "monty.h"
/**
 * addnode - add node to the head stack
 * @stack: head of the stack
 * @n: new_value
 * Return: no return
*/
void addnode(stack_t **stack, int n)
{

	stack_t *new_stack, *temp;

	temp = *stack;
	new_stack = malloc(sizeof(stack_t));
	if (new_stack == NULL)
	{ printf("Error\n");
		exit(0); }
	if (temp)
		temp->prev = new_stack;
	new_stack->n = n;
	new_stack->next = *stack;
	new_stack->prev = NULL;
	*stack = new_stack;
}

/**
 * monty_queue - prints the top
 * @stack: stack head
 * @line_num: line_number
 * Return: no return
*/
void monty_queue(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
	bus.lifi = 1;
}

/**
 * addqueue - add node to the tail stack
 * @n: new_value
 * @stack: head of the stack
 * Return: no return
*/
void addqueue(stack_t **stack, int n)
{
	stack_t *new_stack, *temp;

	temp = *stack;
	new_stack = malloc(sizeof(stack_t));
	if (new_stack == NULL)
	{
		printf("Error\n");
	}
	new_stack->n = n;
	new_stack->next = NULL;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
	}
	if (!temp)
	{
		*stack = new_stack;
		new_stack->prev = NULL;
	}
	else
	{
		temp->next = new_stack;
		new_stack->prev = temp;
	}
}
