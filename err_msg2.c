#include "monty.h"

/**
 * pint_err - error message when stack is empty and can't pint
 * @line_num: line number where error occured
 *
 * Exit: EXIT_FAILURE always
 */
void pint_err(unsigned int line_num)
{
	fprintf(stderr, "L%u: can't pint, stack empty\n", line_num);
	exit(EXIT_FAILURE);
}

/**
 * pop_err - error message if stack is empty and can't pop
 * @line_num: line number where error occured
 *
 * Exit: EXIT_FAILURE always
 */
void pop_err(unsigned int line_num)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
	exit(EXIT_FAILURE);
}

/**
 * swap_err - error message when stack contain <2 elements and can't swap
 * @line_num: line number where error occured
 *
 * Exit: EXIT_FAILURE always
 */
void swap_err(unsigned int line_num)
{
	fprintf(stderr, "L%u: can't swap, stack too short\n", line_num);
	exit(EXIT_FAILURE);
}

/**
 * add_err - error message if stack contains <2 elements and can't add
 * @line_num: line number where error occured
 *
 * Exit: EXIT_FAILURE always
 */
void add_err(unsigned int line_num)
{
	fprintf(stderr, "L%u: can't add, stack too short\n", line_num);
	exit(EXIT_FAILURE);
}

/**
 * sub_err - error message if stack contains <2 elements and can't subtract
 * @line_num: line number where error occured
 *
 * Exit: EXIT_FAILURE always
 */
void sub_err(unsigned int line_num)
{
	fprintf(stderr, "L%u: can't sub, stack too short\n", line_num);
	exit(EXIT_FAILURE);
}
