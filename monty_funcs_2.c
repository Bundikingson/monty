#include "monty.h"

void monty_mul(stack_t **stack, unsigned int line_number);
void monty_mod(stack_t **stack, unsigned int line_number);
void monty_add(stack_t **stack, unsigned int line_number);
void monty_sub(stack_t **stack, unsigned int line_number);
void monty_div(stack_t **stack, unsigned int line_number);

/**
 * monty_add - ADDS THE TOP TWO VALS of a stack_t LINKED LIST..
 * @stack: A POINTER TO THE TOP mode node of a stack_t LINKED LIST..
 * @line_number: The current working line number of a MONTY BYTECODES file..
 *
 * Description: The result is stored in the second VAL NODE
 *              from the top and the top value  is removed.
 */

void monty_add(stack_t **stack, unsigned int line_number)

{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_sub - SUBTRACTS the second value from the top of
 *             a stack_t LINKED LIST by the TOP VAL.
 * @stack: A POINTER TO THE TOP mode node of a stack_t linked LIST..
 * @line_number: The current working line number of a MONTY BYTECODES file..
 *
 * DESCRIPTION: The result is stored in the second VAL NODE
 *              from the top and the top value is removed..
 */

void monty_sub(stack_t **stack, unsigned int line_number)

{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "sub"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_div - DIVIDES the 2ND VAL from the top of
 *             a stack_t LINKED LISTt by the TOP VAL..
 * @stack: A pointer to the top MODE NODE of a stack_t LINKED LIST..
 * @line_number: The current working line number of a MONTY BYTECODES file..
 *
 * DESCRIPTION: The RESULT is stored in the second VAL NODE
 *              from the top and the top VAL is REMOVED..
 */

void monty_div(stack_t **stack, unsigned int line_number)

{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "div"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_op_tok_error(div_error(line_number));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_mul - MULTIPLIES the second value from the top of
 *             a stack_t LINKED LIST by the TOP VAL..
 * @stack: A pointer to the top MODE NODE of a stack_t LINKED LIST..
 * @line_number: The current working line number of a MONTY BYTECODES file..
 *
 * DESCRIPTION: The RESULT is stored in the second VAL NODE
 *              from the top and the top VAL is removed..
 */

void monty_mul(stack_t **stack, unsigned int line_number)

{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "mul"));
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_mod - COMPUTES the MODULUS of the 2ND VAL from the
 *             top of a stack_t linked list  by the TOP VAL..
 * @stack: A pointer to the top mode node of a stack_t LINKED LIST..
 * @line_number: The current working line number of a MONTY BYTECODES file..
 *
 * DESCRIPTION: The RESULT is stored in the second value node
 *              from the top and the TOP VAL is REMOVED..
 */

void monty_mod(stack_t **stack, unsigned int line_number)

{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "mod"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_op_tok_error(div_error(line_number));
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	monty_pop(stack, line_number);
}
