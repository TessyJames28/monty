#include "monty.h"

/**
 * usage_err - error message for usage error
 *
 * Exit: EXIT FAILURE always
 */
void usage_err(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * f_open_err - error message when file's unable to open
 * @filename: argument for name of file
 *
 * Exit: EXIT_FAILURE always
 */
void f_open_err(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}

/**
 * invalid_op_err - error message for file that contains invalid instruction
 * @line_num: error line number in Monty bytecode
 * @opcode: opcode where error occurred
 *
 * Exit: EXIT_FAILURE always
 */
void invalid_op_err(char *opcode, unsigned int line_num)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_num, opcode);
	exit(EXIT_FAILURE);
}

/**
 * malloc_err - error message when you can't malloc anymore
 *
 * Exit: EXIT_FAILURE always
 */
void malloc_err(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

/**
 * push_err - error message if push arg is not an integer or no arg given
 * @line_num: line number where error occured
 *
 * Exit: EXIT_FAILURE always
 */
void push_err(unsigned int line_num)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_num);
	exit(EXIT_FAILURE);
}
