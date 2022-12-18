#include "monty.h"


/**
 * monty_rotr - rotates the stack to the bottom
 * @stack: head pointer of the stack
 * @line_num: line number of the file
 * Return: nothing
 */
void monty_rotr(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	while (temp->next)
		temp = temp->next;

	temp->next = *stack;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*stack)->prev = temp;
	(*stack) = temp;

	(void)line_num;
}
