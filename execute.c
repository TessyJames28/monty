#include "monty.h"
/**
* execute - executes the opcode
* @stack: head linked list - stack
* @line_num: line_counter
* @file: poiner to monty file
* @content: line content
* Return: no return
*/
int execute(char *content, stack_t **stack, unsigned int line_num, FILE *file)
{
	instruction_t opcode_func[] = {
		{"push", monty_push},
		{"pall", monty_pall},
		{"pint", monty_pint},
		{"pop", monty_pop},
		{"swap", monty_swap},
		{"add", monty_add},
		{"nop", monty_nop},
		{"sub", monty_sub},
		{"div", monty_div},
		{"mul", monty_mul},
		{"mod", monty_mod},
		{"pchar", monty_pchar},
		{"pstr", monty_pstr},
		{"rotl", monty_rotl},
		{"rotr", monty_rotr},
		{"queue", monty_queue},
		{"stack", monty_stack},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *op_code;

	op_code = strtok(content, " \n\t");
	if (op_code && op_code[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opcode_func[i].opcode && op_code)
	{
		if (strcmp(op_code, opcode_func[i].opcode) == 0)
		{
			opcode_func[i].f(stack, line_num);
			return (0);
		}
		i++;
	}
	if (op_code && opcode_func[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, op_code);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}


/**
* free_stack - frees a doubly linked list
* @stack: head of the stack
*/
void free_stack(stack_t *stack)
{
	stack_t *temp;

	temp = stack;
	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}
