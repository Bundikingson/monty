#include "monty.h"

int div_error(unsigned int line_number);
int pchar_error(unsigned int line_number, char *message);
int short_stack_error(unsigned int line_number, char *op);
int div_error(unsigned int line_number);
int pop_error(unsigned int line_number);

/**
 * pop_error - PRINTS POP ERROR messages for Empty stacks..
 * @line_number: LINE NUMBER in script where ERROR OCCURED..
 *
 * RETURN: (EXIT_FAILURE) ALWAYS.
 */

int pop_error(unsigned int line_number)

{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pint_error - PRINTS PINT ERROR messages for Empty stacks..
 * @line_number: LINE NUMBER in Monty BYTECODES file where ERROR occurred.
 *
 * RETURN: (EXIT_FAILURE) ALWAYS..
 */

int pint_error(unsigned int line_number)

{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * short_stack_error - PRINTS MONTY math function ERROR messages..
 *                     for stacks/queues smaller than two nodes..
 * @line_number: LINE NUMBER in Monty BYTECODES file where ERROR occurred.
 * @op: OPERATION where the ERROR occurred.
 *
 * RETURN: (EXIT_FAILURE) ALWAYS..
 */

int short_stack_error(unsigned int line_number, char *op)

{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
	return (EXIT_FAILURE);
}

/**
 * div_error - PRINTS DIVISION ERROR messages for div by 0..
 * @line_number: LINE NUMBER in Monty bytecodes file where ERROR occurred..
 *
 * RETURN: (EXIT_FAILURE) ALWAYS..
 */

int div_error(unsigned int line_number)

{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pchar_error - PRINTS PCHAR ERROR messages for EMPTY stacks..
 *               empty stacks and non-character values.
 * @line_number: LINE NUMBER in MONTY BYTECODES file where ERROR occurred..
 * @message: The CORRESPONDING ERROR message to print..
 *
 * RETURN: (EXIT_FAILURE) ALWAYS..
 */

int pchar_error(unsigned int line_number, char *message)

{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);
	return (EXIT_FAILURE);
}
