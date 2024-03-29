#include "monty.h"

int unknown_op_error(char *opcode, unsigned int line_number);
int no_int_error(unsigned int line_number);
int usage_error(void);
int malloc_error(void);
int f_open_error(char *filename);

/**
 * usage_error - IT PRINTS usage ERROR messages..
 *
 * RETURN: (EXIT_FAILURE) ALWAYS..
 */

int usage_error(void)

{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * malloc_error - IT PRINTS MALLOC ERROR messages..
 *
 * RETURN: (EXIT_FAILURE) ALWAYS..
 */

int malloc_error(void)

{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * f_open_error - IT PRINTS FILE OPENING ERROR messages w/ file name..
 * @filename: THE NAME of file FAILED to open..
 *
 * RETURN: (EXIT_FAILURE) ALWAYS..
 */

int f_open_error(char *filename)

{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * unknown_op_error - PRINTS UNKNOWN  Instruction ERROR messages..
 * @opcode: OPCODE where ERROR occurred..
 * @line_number: LINE NUMBER in Monty BYTECODES file where ERROR occured..
 *
 * RETURN: (EXIT_FAILURE) ALWAYS..
 */

int unknown_op_error(char *opcode, unsigned int line_number)

{
	fprintf(stderr, "L%u: unknown instruction %s\n",
		line_number, opcode);
	return (EXIT_FAILURE);
}

/**
 * no_int_error - PRINTS INVALID monty_push argument ERROR messages..
 * @line_number: LINE NUMBER in Monty BYTECODES file where ERROR occurred..
 *
 * RETURN: (EXIT_FAILURE) ALWAYS..
 */

int no_int_error(unsigned int line_number)

{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}
