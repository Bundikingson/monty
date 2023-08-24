#include "monty.h"

void monty_pstr(stack_t **stack, unsigned int line_number);
void monty_nop(stack_t **stack, unsigned int line_number);
void monty_pchar(stack_t **stack, unsigned int line_number);

/**
 * monty_nop - Does ABSOLUTELY NOTHING for the MONTY OPCODE 'nop'..
 * @stack: A POINTER to the TOP MODE NODE of a stack_t LINKED LIST..
 * @line_number: The current working line number of a MONTY BYTECODES file..
 */

void monty_nop(stack_t **stack, unsigned int line_number)

{
	(void)stack;
	(void)line_number;
}

/**
 * monty_pchar - PRINTS THE CHAR in the TOP VAL..
 *               NODE of a stack_t LINKED LIST..
 * @stack: A POINTER to the top MODE NODE of a stack_t LINKED LIST..
 * @line_number: The current working line number of a MONTY BYTECODES File..
 */

void monty_pchar(stack_t **stack, unsigned int line_number)

{
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pchar_error(line_number, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		set_op_tok_error(pchar_error(line_number,
					     "value out of range"));
		return;
	}

	printf("%c\n", (*stack)->next->n);
}

/**
 * monty_pstr - PRINTS THE STRING contained in a stack_t LINKED LIST..
 * @stack: A POINTER to the top MODE NODE of a stack_t LINKED LIST..
 * @line_number: The current working LINE NUM of a MONTY BYTECODES File..
 */

void monty_pstr(stack_t **stack, unsigned int line_number)

{
	stack_t *tmp = (*stack)->next;

	while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}

	printf("\n");

	(void)line_number;
}
